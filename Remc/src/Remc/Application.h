#pragma once

#include "Core.h"

#include "Remc/Window.h"
#include "Remc/LayerStack.h"
#include "Events/Event.h"
#include "Remc/Events/ApplicationEvent.h"

#include "Remc/ImGui/ImGuiLayer.h"

namespace Remc
{

	class REMC_API Application
	{
	private:
		std::unique_ptr<Window> m_Window;
		ImGuiLayer* m_ImGuiLayer;
		bool m_Running = true;
		bool OnWindowClose(WindowCloseEvent& e);
		LayerStack m_LayerStack;

		static Application* s_Instance;
	public:
		Application();
		virtual ~Application();

		void run();

		void OnEvent(Event& e);

		void PushLayer(Layer* layer);
		void PushOverLayer(Layer* layer);

		inline static Application& Get() { return *s_Instance; }
		inline Window& GetWindow() { return *m_Window; }
	};

	// To be defined in CLIENT
	Application* CreateApplication();

}