#pragma once

#include "Remc.h"

class Sandbox2D : public Remc::Layer
{
public:
	Sandbox2D();
	virtual ~Sandbox2D() = default;

	virtual void OnAttach() override;
	virtual void OnDetach() override;

	void OnUpdate(Remc::Timestep ts) override;
	virtual void OnImGuiRender() override;
	void OnEvent(Remc::Event& e) override;
private:
	Remc::OrthographicCameraController m_CameraController;

	// Temp
	Remc::Ref<Remc::VertexArray> m_SquareVA;
	Remc::Ref<Remc::Shader> m_FlatColorShader;
	Remc::Ref<Remc::Framebuffer> m_Framebuffer;

	Remc::Ref<Remc::Texture2D> m_CheckerboardTexture;

	glm::vec4 m_SquareColor = { 0.2f, 0.3f, 0.8f, 1.0f };

	bool Color_grid;
};