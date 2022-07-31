#pragma once
#include "Application.h"

#ifdef REMC_PLATFORM_WINDOWS

extern Remc::Application* Remc::CreateApplication();

int main(int argc,char** argv)
{
	Remc::Log::Init();
	REMC_CORE_WARN("Initialized log !");
	REMC_INFO("Hello,welcome to Remc Engine !");

	auto app = Remc::CreateApplication();
	app->run();
	delete app;
	return 0;
}

#endif