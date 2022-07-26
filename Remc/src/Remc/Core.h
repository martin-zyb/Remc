#pragma once

#ifdef REMC_PLATFORM_WINDOWS
	#ifdef REMC_BUILD_DLL
		#define REMC_API __declspec(dllexport)
	#else
		#define REMC_API __declspec(dllimport)
	#endif
#else 
	#error Remc only support Windows !
#endif