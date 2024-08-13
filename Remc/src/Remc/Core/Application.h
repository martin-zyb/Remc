#pragma once

#include "Remc/Core/Base.h"

#include "Remc/Core/Window.h"
#include "Remc/Core/LayerStack.h"
#include "Remc/Events/Event.h"
#include "Remc/Events/ApplicationEvent.h"

#include "Remc/ImGui/ImGuiLayer.h"

#include "Remc/Core/Timestep.h"

int main(int argc, char** argv);

namespace Remc {

	class REMC_API Application
	{
	public:
		Application(const std::string& name = "Remc App");
		virtual ~Application();

		void OnEvent(Event& e);

		void PushLayer(Layer* layer);
		void PushOverlay(Layer* layer);

		Window& GetWindow() { return *m_Window; }

		void Close();

		ImGuiLayer* GetImGuiLayer() { return m_ImGuiLayer; }

		static Application& Get() { return *s_Instance; }

	private:
		void Run();
		bool OnWindowClose(WindowCloseEvent& e);
		bool OnWindowResize(WindowResizeEvent& e);

		Scope<Window> m_Window;
		ImGuiLayer* m_ImGuiLayer;
		bool m_Running = true;
		bool m_Minimized = false;
		LayerStack m_LayerStack;

		float m_LastFrameTime = 0.0f;

		static Application* s_Instance;

		friend int ::main(int argc, char** argv);
	};

	// To be defined in CLIENT
	Application* CreateApplication();

}