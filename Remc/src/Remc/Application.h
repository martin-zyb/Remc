#pragma once

#include "Core.h"

#include "Remc/Window.h"
#include "Remc/LayerStack.h"
#include "Events/Event.h"
#include "Remc/Events/ApplicationEvent.h"


namespace Remc
{

	class REMC_API Application
	{
	private:
		std::unique_ptr<Window> m_Window;
		bool m_Running = true;
		bool OnWindowClose(WindowCloseEvent& e);
		LayerStack m_LayerStack;
	public:
		Application();
		virtual ~Application();

		void run();

		void OnEvent(Event& e);

		void PushLayer(Layer* layer);
		void PushOverLayer(Layer* layer);
	};

	// To be define in CLIENT
	Application* CreateApplication();

}