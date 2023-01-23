#include <Remc.h>

#include "imgui/imgui.h"

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
			REMC_TRACE("Tab key is pressed (poll)!");
	}

	virtual void OnImGuiRender() override
	{
		ImGui::Begin("Test");
		ImGui::Text("Hello Remc Engine");
		ImGui::End();
	}

	void OnEvent(Remc::Event& event) override
	{
		if (event.GetEventType() == Remc::EventType::KeyPressed)
		{
			Remc::KeyPressedEvent& e = (Remc::KeyPressedEvent&)event;
			if (e.GetKeyCode() == REMC_KEY_TAB)
				REMC_TRACE("Tab key is pressed (event)!");
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
	}

	~Sandbox()
	{

	}

};

Remc::Application* Remc::CreateApplication()
{
	return new Sandbox();
}