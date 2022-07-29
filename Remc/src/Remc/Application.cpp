#include "rcpch.h"
#include "Application.h"

#include "Remc/Log.h"
#include "Remc/Events/ApplicationEvent.h"

namespace Remc
{

	Application::Application()
	{

	}

	Application::~Application()
	{

	}

	void Application::run()
	{
		WindowResizeEvent e(1200, 720);
		if (e.IsInCategory(EventCategoryApplication))
		{
			REMC_TRACE(e);
		}
		if (e.IsInCategory(EventCategoryInput))
		{
			REMC_TRACE(e);
		}

		while (true);
	}

}