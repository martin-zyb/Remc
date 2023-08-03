#include "rcpch.h"
#include "Remc/Core/Input.h"

#ifdef REMC_PLATFORM_WINDOWS
	#include "Platform/Windows/WindowsInput.h"
#endif

namespace Remc {

	Scope<Input> Input::s_Instance = Input::Create();

	Scope<Input> Input::Create()
	{
		#ifdef REMC_PLATFORM_WINDOWS
			return CreateScope<WindowsInput>();
		#else
			REMC_CORE_ASSERT(false, "Unknown platform!");
		return nullptr;
		#endif
	}
}