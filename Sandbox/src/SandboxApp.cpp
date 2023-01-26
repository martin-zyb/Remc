#include <Remc.h>

#include "imgui/imgui.h"

#include "Platform/OpenGL/OpenGLShader.h"

#include <glm/gtc/type_ptr.hpp>
#include <glm/gtc/matrix_transform.hpp>

class ExampleLayer : public Remc::Layer
{
public:
	ExampleLayer()
		: Layer("Example") , m_Camera(-1.6f, 1.6f, -0.9f, 0.9f) , m_CameraPosition(0.0f)
	{
		m_VertexArray.reset(Remc::VertexArray::Create());

		float vertices[3 * 7] = {
			-0.5f, -0.5f, 0.0f, 0.8f, 0.2f, 0.8f, 1.0f,
			 0.5f, -0.5f, 0.0f, 0.2f, 0.3f, 0.8f, 1.0f,
			 0.0f,  0.5f, 0.0f, 0.8f, 0.8f, 0.2f, 1.0f
		};

		Remc::Ref<Remc::VertexBuffer> vertexBuffer;
		vertexBuffer.reset(Remc::VertexBuffer::Create(vertices, sizeof(vertices)));
		Remc::BufferLayout layout = {
			{ Remc::ShaderDataType::Float3, "a_Position" },
			{ Remc::ShaderDataType::Float4, "a_Color" }
		};
		vertexBuffer->SetLayout(layout);
		m_VertexArray->AddVertexBuffer(vertexBuffer);

		uint32_t indices[3] = { 0, 1, 2 };
		Remc::Ref<Remc::IndexBuffer> indexBuffer;
		indexBuffer.reset(Remc::IndexBuffer::Create(indices, sizeof(indices) / sizeof(uint32_t)));
		m_VertexArray->SetIndexBuffer(indexBuffer);
		m_SquareVA.reset(Remc::VertexArray::Create());

		float squareVertices[5 * 4] = {
			-0.5f, -0.5f, 0.0f, 0.0f, 0.0f,
			 0.5f, -0.5f, 0.0f, 1.0f, 0.0f,
			 0.5f,  0.5f, 0.0f, 1.0f, 1.0f,
			-0.5f,  0.5f, 0.0f, 0.0f, 1.0f
		};

		Remc::Ref<Remc::VertexBuffer> squareVB;
		squareVB.reset(Remc::VertexBuffer::Create(squareVertices, sizeof(squareVertices)));
		squareVB->SetLayout({
			{ Remc::ShaderDataType::Float3, "a_Position" },
			{ Remc::ShaderDataType::Float2, "a_TexCoord" }
		});
		m_SquareVA->AddVertexBuffer(squareVB);

		uint32_t squareIndices[6] = { 0, 1, 2, 2, 3, 0 };
		Remc::Ref<Remc::IndexBuffer> squareIB;
		squareIB.reset(Remc::IndexBuffer::Create(squareIndices, sizeof(squareIndices) / sizeof(uint32_t)));
		m_SquareVA->SetIndexBuffer(squareIB);

		std::string vertexSrc = R"(
			#version 330 core
			
			layout(location = 0) in vec3 a_Position;
			layout(location = 1) in vec4 a_Color;

			uniform mat4 u_ViewProjection;
			uniform mat4 u_Transform;

			out vec3 v_Position;
			out vec4 v_Color;

			void main()
			{
				v_Position = a_Position;
				v_Color = a_Color;
				gl_Position = u_ViewProjection * u_Transform * vec4(a_Position, 1.0);
			}
		)";

		std::string fragmentSrc = R"(
			#version 330 core
			
			layout(location = 0) out vec4 color;

			in vec3 v_Position;
			in vec4 v_Color;

			void main()
			{
				color = vec4(v_Position * 0.5 + 0.5, 1.0);
				color = v_Color;
			}
		)";

		m_Shader.reset(Remc::Shader::Create(vertexSrc, fragmentSrc));

		std::string flatShaderVertexSrc = R"(
			#version 330 core
			
			layout(location = 0) in vec3 a_Position;

			uniform mat4 u_ViewProjection;
			uniform mat4 u_Transform;

			out vec3 v_Position;

			void main()
			{
				v_Position = a_Position;
				gl_Position = u_ViewProjection * u_Transform * vec4(a_Position, 1.0);	
			}
		)";

		std::string flatShaderFragmentSrc = R"(
			#version 330 core
			
			layout(location = 0) out vec4 color;

			in vec3 v_Position;

			uniform vec3 u_Color;

			void main()
			{
				color = vec4(u_Color, 1.0);
			}
		)";

		m_FlatColorShader.reset(Remc::Shader::Create(flatShaderVertexSrc, flatShaderFragmentSrc));

		std::string textureShaderVertexSrc = R"(
			#version 330 core
			
			layout(location = 0) in vec3 a_Position;
			layout(location = 1) in vec2 a_TexCoord;

			uniform mat4 u_ViewProjection;
			uniform mat4 u_Transform;

			out vec2 v_TexCoord;

			void main()
			{
				v_TexCoord = a_TexCoord;
				gl_Position = u_ViewProjection * u_Transform * vec4(a_Position, 1.0);
			}
		)";

		std::string textureShaderFragmentSrc = R"(
			#version 330 core
			
			layout(location = 0) out vec4 color;

			in vec2 v_TexCoord;
			
			uniform sampler2D u_Texture;

			void main()
			{
				color = texture(u_Texture, v_TexCoord);
			}
		)";

		m_TextureShader.reset(Remc::Shader::Create(textureShaderVertexSrc, textureShaderFragmentSrc));

		m_Texture = Remc::Texture2D::Create("assets/textures/Checkerboard.png");
		m_LogoTexture = Remc::Texture2D::Create("assets/textures/Logo.png");

		std::dynamic_pointer_cast<Remc::OpenGLShader>(m_TextureShader)->Bind();
		std::dynamic_pointer_cast<Remc::OpenGLShader>(m_TextureShader)->UploadUniformInt("u_Texture", 0);
	}

	void OnUpdate(Remc::Timestep ts) override
	{
		if (Remc::Input::IsKeyPressed(REMC_KEY_LEFT))
		{
			m_CameraPosition.x -= m_CameraMoveSpeed * ts;
		}
		else if (Remc::Input::IsKeyPressed(REMC_KEY_RIGHT))
		{
			m_CameraPosition.x += m_CameraMoveSpeed * ts;
		}
		if (Remc::Input::IsKeyPressed(REMC_KEY_UP))
		{
			m_CameraPosition.y += m_CameraMoveSpeed * ts;
		}
		else if (Remc::Input::IsKeyPressed(REMC_KEY_DOWN))
		{
			m_CameraPosition.y -= m_CameraMoveSpeed * ts;
		}

		if (Remc::Input::IsKeyPressed(REMC_KEY_A))
		{
			m_CameraRotation += m_CameraRotationSpeed * ts;
		}
		else if (Remc::Input::IsKeyPressed(REMC_KEY_D))
		{
			m_CameraRotation -= m_CameraRotationSpeed * ts;
		}

		if (Remc::Input::IsKeyPressed(REMC_KEY_J))
		{
			m_SquareMoveDistance.x -= m_SquareMoveSpeed * ts;
		}
		else if (Remc::Input::IsKeyPressed(REMC_KEY_L))
		{
			m_SquareMoveDistance.x += m_SquareMoveSpeed * ts;
		}
		if (Remc::Input::IsKeyPressed(REMC_KEY_I))
		{
			m_SquareMoveDistance.y += m_SquareMoveSpeed * ts;
		}
		else if (Remc::Input::IsKeyPressed(REMC_KEY_K))
		{
			m_SquareMoveDistance.y -= m_SquareMoveSpeed * ts;
		}

		Remc::RenderCommand::SetClearColor({ 0.1f, 0.1f, 0.1f, 1.0f });
		Remc::RenderCommand::Clear();

		m_Camera.SetPosition(m_CameraPosition);
		m_Camera.SetRotation(m_CameraRotation);

		Remc::Renderer::BeginScene(m_Camera);

		glm::mat4 scale = glm::scale(glm::mat4(1.0f), glm::vec3(0.1f));

		std::dynamic_pointer_cast<Remc::OpenGLShader>(m_FlatColorShader)->Bind();
		std::dynamic_pointer_cast<Remc::OpenGLShader>(m_FlatColorShader)->UploadUniformFloat3("u_Color", m_SquareColor);

		for (int y = 0; y < 20; y++)
		{
			for (int x = 0; x < 20; x++)
			{
				glm::vec3 pos(x * 0.11f + m_SquareMoveDistance.x, y * 0.11f + m_SquareMoveDistance.y, 0.0f);
				glm::mat4 transform = glm::translate(glm::mat4(1.0f), pos) * scale;
				
				if(Flat) Remc::Renderer::Submit(m_FlatColorShader, m_SquareVA, transform);
			}
		}

		m_Texture->Bind();
		if (Texture) Remc::Renderer::Submit(m_TextureShader, m_SquareVA, glm::scale(glm::mat4(1.0f), glm::vec3(1.5f)));

		m_LogoTexture->Bind();
		if (LogoTexture) Remc::Renderer::Submit(m_TextureShader, m_SquareVA, glm::scale(glm::mat4(1.0f), glm::vec3(1.5f)));

		// Triangle
		if (Triangle) Remc::Renderer::Submit(m_Shader, m_VertexArray);

		Remc::Renderer::EndScene();
	}

	virtual void OnImGuiRender() override
	{
		ImGui::Begin("Settings");
		ImGui::Checkbox("Triangle", &Triangle);
		if (ImGui::CollapsingHeader("Textures"))
		{
			ImGui::Checkbox("BasicTexture", &Texture);
			ImGui::Checkbox("LogoTexture", &LogoTexture);
		}
		if (ImGui::CollapsingHeader("Flats"))
		{
			ImGui::Checkbox("Flat", &Flat);
			ImGui::ColorEdit3("Flat Color", glm::value_ptr(m_SquareColor));
		}
		ImGui::End();
	}

	void OnEvent(Remc::Event& event) override
	{

	}

private:
	Remc::Ref<Remc::Shader> m_Shader;
	Remc::Ref<Remc::VertexArray> m_VertexArray;

	Remc::Ref<Remc::Shader> m_FlatColorShader, m_TextureShader;
	Remc::Ref<Remc::VertexArray> m_SquareVA;

	Remc::Ref<Remc::Texture2D> m_Texture, m_LogoTexture;

	Remc::OrthographicCamera m_Camera;
	glm::vec3 m_CameraPosition;
	float m_CameraMoveSpeed = 3.0f;

	float m_CameraRotation = 0.0f;
	float m_CameraRotationSpeed = 120.0f;

	glm::vec3 m_SquareMoveDistance = glm::vec3(0.0f);
	float m_SquareMoveSpeed = 1.0f;

	glm::vec3 m_SquareColor = { 0.2f, 0.3f, 0.8f };

	bool Triangle, Texture, LogoTexture, Flat;
};

class Sandbox : public Remc::Application
{
public:
	Sandbox()
	{
		PushLayer(new ExampleLayer());
	}

	~Sandbox()
	{

	}

};

Remc::Application* Remc::CreateApplication()
{
	return new Sandbox();
}