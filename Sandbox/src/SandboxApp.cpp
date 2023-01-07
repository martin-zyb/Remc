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
		if (Remc::Input::IsKeyPressed(REMC_KEY_TAB))
		{
			REMC_TRACE("Tab key is pressed (poll)!");
		}
	}

	void OnEvent(Remc::Event& event) override
	{
		if (event.GetEventType() == Remc::EventType::KeyPressed)
		{
			Remc::KeyPressedEvent& e = (Remc::KeyPressedEvent&)event;
			if (e.GetKeyCode() == REMC_KEY_TAB)
			{
				REMC_TRACE("Tab key is pressed (event)!");
			}
			REMC_TRACE("{0}", (char)e.GetKeyCode());
		}
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