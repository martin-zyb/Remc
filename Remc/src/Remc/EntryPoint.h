#pragma once

#ifdef REMC_PLATFORM_WINDOWS

extern Remc::Application* Remc::CreateApplication();

int main(int argc,char** argv)
{
	Remc::Log::Init();
	REMC_CORE_WARN("Initialized log!");
	int a = 5;
	REMC_CLIENT_INFO("Hello! Var={0}", a);

	auto app = Remc::CreateApplication();
	app->run();
	delete app;
	return 0;
}

#endif