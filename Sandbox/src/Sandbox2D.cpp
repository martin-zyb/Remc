#include "Sandbox2D.h"
#include <imgui/imgui.h>

#include <glm/gtc/matrix_transform.hpp>
#include <glm/gtc/type_ptr.hpp>

Sandbox2D::Sandbox2D()
	: Layer("Sandbox2D"), m_CameraController(1280.0f / 720.0f), m_SquareColor({ 0.2f, 0.3f, 0.8f, 1.0f })
{
}

void Sandbox2D::OnAttach()
{
	REMC_PROFILE_FUNCTION();

	m_CheckerboardTexture = Remc::Texture2D::Create("assets/textures/Checkerboard.png");

}

void Sandbox2D::OnDetach()
{
	REMC_PROFILE_FUNCTION();
}

void Sandbox2D::OnUpdate(Remc::Timestep ts)
{
	REMC_PROFILE_SCOPE("Sandbox2D::OnUpdate");

	// Update
	m_CameraController.OnUpdate(ts);

	Remc::Renderer2D::ResetStats();

	// Render
	{
		REMC_PROFILE_SCOPE("Renderer Prep");
		Remc::RenderCommand::SetClearColor({ 0.1f, 0.1f, 0.1f, 1 });
		Remc::RenderCommand::Clear();
	}

	{
		static float rotation = 0.0f;
		rotation += ts * 50.0f;

		REMC_PROFILE_SCOPE("Renderer Draw");

		Remc::Renderer2D::BeginScene(m_CameraController.GetCamera());
		Remc::Renderer2D::DrawRotatedQuad({ -1.0f, 0.0f }, { 0.8f, 0.8f }, -45.0f, {0.8f, 0.2f, 0.3f, 1.0f});
		Remc::Renderer2D::DrawQuad({ -1.0f, 0.0f }, { 0.8f, 0.8f }, { 0.8f, 0.2f, 0.3f, 1.0f });
		Remc::Renderer2D::DrawQuad({ 0.5f, -0.5f }, { 0.5f, 0.75f }, m_SquareColor);
		//Remc::Renderer2D::DrawQuad({ 0.0f, 0.0f, -0.1f }, { 10.0f, 10.0f }, m_CheckerboardTexture, 10.0f, glm::vec4( 0.9f, 1.0f, 0.75f, 1.0f ) );
		Remc::Renderer2D::DrawQuad({ 0.0f, 0.0f, -0.1f }, { 20.0f, 20.0f }, m_CheckerboardTexture, 10.0f);
		Remc::Renderer2D::DrawRotatedQuad({ 0.75f, 0.75f }, { 1.0f, 1.0f }, rotation, m_CheckerboardTexture, 20.0f);
		Remc::Renderer2D::EndScene();

		float alpha = Color_grid ? 0.7f : 0.0f;

		Remc::Renderer2D::BeginScene(m_CameraController.GetCamera());
		for (float y = -5.0f; y < 5.0f; y += 0.5f)
		{
			for (float x = -5.0f; x < 5.0f; x += 0.5f)
			{
				glm::vec4 color = { (x + 5.0f) / 10.0f, 0.4f, (y + 5.0f) / 10.0f, alpha };
				Remc::Renderer2D::DrawQuad({ x, y }, { 0.45f, 0.45f }, color);
			}
		}
		Remc::Renderer2D::EndScene();
	}
}

void Sandbox2D::OnImGuiRender()
{
	REMC_PROFILE_FUNCTION();

		ImGui::Begin("Settings");

		ImGui::Checkbox("Color Grid", &Color_grid);

		auto stats = Remc::Renderer2D::GetStats();
		ImGui::Text("Renderer2D Stats:");
		ImGui::Text("	Draw Calls:	%d", stats.DrawCalls);
		ImGui::Text("	Quads:		 %d", stats.QuadCount);
		ImGui::Text("	Vertices:	  %d", stats.GetTotalVertexCount());
		ImGui::Text("	Indices:	   %d", stats.GetTotalIndexCount());

		ImGui::Text("\n");
		ImGui::ColorEdit4("Square Color", glm::value_ptr(m_SquareColor));
		ImGui::Text("\n");

		ImGui::End();
}

void Sandbox2D::OnEvent(Remc::Event& e)
{
	m_CameraController.OnEvent(e);
}