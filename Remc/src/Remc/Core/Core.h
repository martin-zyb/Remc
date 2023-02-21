#pragma once

#include <memory>

#ifdef REMC_PLATFORM_WINDOWS
#if REMC_DYNAMIC_LINK
	#ifdef REMC_BUILD_DLL
		#define REMC_API __declspec(dllexport)
	#else
		#define REMC_API __declspec(dllimport)
	#endif
#else
    #define REMC_API
#endif
#else
	#error Remc only supports Windows!
#endif

#ifdef REMC_DEBUG
	#define REMC_ENABLE_ASSERTS
#endif

#ifdef REMC_ENABLE_ASSERTS
	#define REMC_ASSERT(x, ...) { if(!(x)) { REMC_ERROR("Assertion Failed: {0}", __VA_ARGS__); __debugbreak(); } }
	#define REMC_CORE_ASSERT(x, ...) { if(!(x)) { REMC_CORE_ERROR("Assertion Failed: {0}", __VA_ARGS__); __debugbreak(); } }
#else
	#define REMC_ASSERT(x, ...)
	#define REMC_CORE_ASSERT(x, ...)
#endif

#define BIT(x) (1 << x)

#define REMC_BIND_EVENT_FN(fn) std::bind(&fn, this, std::placeholders::_1)

namespace Remc
{

	template<typename T>
	using Scope = std::unique_ptr<T>;

	template<typename T>
	using Ref = std::shared_ptr<T>;

}