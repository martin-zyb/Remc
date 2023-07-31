#pragma once
#include "Remc/Core/Core.h"

#ifdef REMC_PLATFORM_WINDOWS

extern Remc::Application* Remc::CreateApplication();

int main(int argc, char** argv)
{
	Remc::Log::Init();
	REMC_CORE_WARN("Initialized log !");
	REMC_INFO("Hello,welcome to Remc Engine !");

	REMC_PROFILE_BEGIN_SESSION("Startup", "RemcProfile-Startup.json");
	auto app = Remc::CreateApplication();
	REMC_PROFILE_END_SESSION();

	REMC_PROFILE_BEGIN_SESSION("Runtime", "RemcProfile-Runtime.json");
	app->Run();
	REMC_PROFILE_END_SESSION();

	REMC_PROFILE_BEGIN_SESSION("Startup", "RemcProfile-Shutdown.json");
	delete app;
	REMC_PROFILE_END_SESSION();
}

#endif