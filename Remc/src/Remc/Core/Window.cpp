#include "rcpch.h"
#include "Remc/Core/Window.h"

#ifdef REMC_PLATFORM_WINDOWS
	#include "Platform/Windows/WindowsWindow.h"
#endif

namespace Remc
{

	Scope<Window> Window::Create(const WindowProps& props)
	{
		#ifdef REMC_PLATFORM_WINDOWS
			return CreateScope<WindowsWindow>(props);
		#else
			REMC_CORE_ASSERT(false, "Unknown platform!");
			return nullptr;
		#endif
	}

}