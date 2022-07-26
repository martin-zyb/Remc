#include <Remc.h>

class Sandbox : public Remc::Application
{
public:
	Sandbox()
	{

	}

	~Sandbox()
	{

	}

};

Remc::Application* Remc::CreateApplication()
{
	return new Sandbox();
}