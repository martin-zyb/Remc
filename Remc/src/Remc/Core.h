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

#ifdef REMC_ENABLE_ASSERTS
	#define REMC_ASSERT(x, ...) { if(!(x)) { REMC_ERROR("Assertion Failed : {0}", __VA_ARGS__); __debugbreak();} }
	#define REMC_CORE_ASSERT(x, ...) { if(!(x)) REMC_CORE_ERROR("Assertion Failed : {0}", __VA_ARGS__); __debugbreak();} }
#else
	#define REMC_ASSERT(x, ...)
	#define REMC_CORE_ASSERT(x, ...)
#endif


#define BIT(x) (1 << x)