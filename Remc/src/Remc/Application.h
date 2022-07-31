#pragma once

#include "Core.h"
#include "Events/Event.h"
#include "Remc/Window.h"

namespace Remc
{

	class REMC_API Application
	{
	private:
		std::unique_ptr<Window> m_Window;
		bool m_Running = true;
	public:
		Application();
		virtual ~Application();

		void run();
	};

	// To be define in CLIENT
	Application* CreateApplication();

}