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

#ifdef HZ_DEBUG
	#define HZ_ENABLE_ASSERTS
#endif

#ifdef REMC_ENABLE_ASSERTS
	#define REMC_ASSERT(x, ...) { if(!(x)) { REMC_ERROR("Assertion Failed : {0}", __VA_ARGS__); __debugbreak();} }
	#define REMC_CORE_ASSERT(x, ...) { if(!(x)) REMC_CORE_ERROR("Assertion Failed : {0}", __VA_ARGS__); __debugbreak();} }
#else
	#define REMC_ASSERT(x, ...)
	#define REMC_CORE_ASSERT(x, ...)
#endif


#define BIT(x) (1 << x)

#define REMC_BIND_EVENT_FN(fn) std::bind(&fn, this, std::placeholders::_1)