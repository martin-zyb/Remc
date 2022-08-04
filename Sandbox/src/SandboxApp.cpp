#include <Remc.h>

class ExampleLayer : public Remc::Layer
{
public:
	ExampleLayer()
		: Layer("Example")
	{

	}

	void OnUpdate() override
	{
		REMC_INFO("ExampleLayer::Update");
	}

	void OnEvent(Remc::Event& event) override
	{
		REMC_TRACE("{0}", event);
	}

};

class Sandbox : public Remc::Application
{
public:
	Sandbox()
	{
		PushLayer(new ExampleLayer());
		PushOverLayer(new Remc::ImGuiLayer());
	}

	~Sandbox()
	{

	}

};

Remc::Application* Remc::CreateApplication()
{
	return new Sandbox();
}