#include <Remc.h>
#include <Remc/Core/EntryPoint.h>

#include "EditorLayer.h"

namespace Remc {

	class RTShell : public Application
	{
	public:
		RTShell()
			: Application("RTShell")
		{
			PushLayer(new EditorLayer());
		}

		~RTShell()
		{
		}
	};

	Application* CreateApplication()
	{
		return new RTShell();
	}

}