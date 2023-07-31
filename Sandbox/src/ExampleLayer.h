#pragma once

#include "Remc.h"

class ExampleLayer : public Remc::Layer
{
public:
	ExampleLayer();
	virtual ~ExampleLayer() = default;

	virtual void OnAttach() override;
	virtual void OnDetach() override;

	void OnUpdate(Remc::Timestep ts) override;
	virtual void OnImGuiRender() override;
	void OnEvent(Remc::Event& e) override;
private:
	Remc::ShaderLibrary m_ShaderLibrary;
	Remc::Ref<Remc::Shader> m_Shader;
	Remc::Ref<Remc::VertexArray> m_VertexArray;

	Remc::Ref<Remc::Shader> m_FlatColorShader;
	Remc::Ref<Remc::VertexArray> m_SquareVA;

	Remc::Ref<Remc::Texture2D> m_Texture, m_LogoTexture;

	glm::vec3 m_SquareMoveDistance = glm::vec3(0.0f);
	float m_SquareMoveSpeed = 1.0f;

	Remc::OrthographicCameraController m_CameraController;

	glm::vec3 m_SquareColor = { 0.2f, 0.3f, 0.8f };

	bool Triangle, Texture, LogoTexture, Flat;
};
