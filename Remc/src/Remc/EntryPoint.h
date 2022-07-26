#pragma once

#ifdef REMC_PLATFORM_WINDOWS

extern Remc::Application* Remc::CreateApplication();

int main(int argc,char** argv)
{
	auto app = Remc::CreateApplication();
	app->run();
	delete app;
	return 0;
}

#endif