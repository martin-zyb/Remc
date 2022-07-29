#pragma once

#include "Core.h"
#include "Events/Event.h"

namespace Remc
{

	class REMC_API Application
	{
	public:
		Application();
		virtual ~Application();

		void run();
	};

	// To be define in CLIENT
	Application* CreateApplication();

}