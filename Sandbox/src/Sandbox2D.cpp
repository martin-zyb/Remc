#include "Sandbox2D.h"
#include <imgui/imgui.h>

#include <glm/gtc/matrix_transform.hpp>
#include <glm/gtc/type_ptr.hpp>

Sandbox2D::Sandbox2D()
	: Layer("Sandbox2D"), m_CameraController(1280.0f / 720.0f)
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

	// Render
	{
		REMC_PROFILE_SCOPE("Renderer Prep");
		Remc::RenderCommand::SetClearColor({ 0.1f, 0.1f, 0.1f, 1 });
		Remc::RenderCommand::Clear();
	}

	{
		REMC_PROFILE_SCOPE("Renderer Draw");
		Remc::Renderer2D::BeginScene(m_CameraController.GetCamera());
		Remc::Renderer2D::DrawQuad({ -1.0f, 0.0f }, { 0.8f, 0.8f }, { 0.8f, 0.2f, 0.3f, 1.0f });
		Remc::Renderer2D::DrawQuad({ 0.5f, -0.5f }, { 0.5f, 0.75f }, { 0.2f, 0.3f, 0.8f, 1.0f });
		Remc::Renderer2D::DrawQuad({ 0.0f, 0.0f, -0.1f }, { 10.0f, 10.0f }, m_CheckerboardTexture);
		Remc::Renderer2D::EndScene();
	}
}

void Sandbox2D::OnImGuiRender()
{
	REMC_PROFILE_FUNCTION();

	ImGui::Begin("Settings");
	ImGui::ColorEdit4("Square Color", glm::value_ptr(m_SquareColor));

	ImGui::End();
}

void Sandbox2D::OnEvent(Remc::Event& e)
{
	m_CameraController.OnEvent(e);
}