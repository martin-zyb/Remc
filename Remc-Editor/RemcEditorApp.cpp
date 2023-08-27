#include <Remc.h>
#include <Remc/Core/EntryPoint.h>

#include "EditorLayer.h"

namespace Remc {

	class RemcEditor : public Application
	{
	public:
		RemcEditor()
			: Application("Remc Editor")
		{
			PushLayer(new EditorLayer());
		}

		~RemcEditor()
		{
		}
	};

	Application* CreateApplication()
	{
		return new RemcEditor();
	}

}