#pragma once

#include "Core.h"
#include "Events/Event.h"
#include "Remc/Events/ApplicationEvent.h"
#include "Remc/Window.h"

namespace Remc
{

	class REMC_API Application
	{
	private:
		std::unique_ptr<Window> m_Window;
		bool m_Running = true;
		bool OnWindowClose(WindowCloseEvent& e);
	public:
		Application();
		virtual ~Application();

		void run();

		void OnEvent(Event& e);
	};

	// To be define in CLIENT
	Application* CreateApplication();

}