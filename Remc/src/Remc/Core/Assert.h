#pragma once

#include "Remc/Core/Base.h"
#include "Remc/Core/Log.h"

#ifdef REMC_ENABLE_ASSERTS

namespace Remc::Assert
{
	// Returns the simple file name rather than full path as suggested by LovelySanta
	constexpr const char* CurrentFileName(const char* path) {
		const char* file = path;
		while (*path)
		{
			if (*path == '/' || *path == '\\')
				file = ++path;
			else
				path++;
		}
		return file;
	}
}

// Alteratively we could use the same "default" message for both "WITH_MSG" and "NO_MSG" and
// provide support for custom formatting by concatenating the formatting string instead of having the format inside the default message
#define REMC_INTERNAL_ASSERT_IMPL(type, check, msg, ...) { if(!(check)) { REMC##type##ERROR(msg, __VA_ARGS__); REMC_DEBUGBREAK(); } }
#define REMC_INTERNAL_ASSERT_WITH_MSG(type, check, ...) REMC_INTERNAL_ASSERT_IMPL(type, check, "Assertion failed: {0}", __VA_ARGS__)
#define REMC_INTERNAL_ASSERT_NO_MSG(type, check) REMC_INTERNAL_ASSERT_IMPL(type, check, "Assertion '{0}' failed at {1}:{2}", REMC_STRINGIFY_MACRO(check), ::Remc::Assert::CurrentFileName(__FILE__), __LINE__)

#define REMC_INTERNAL_ASSERT_GET_MACRO_NAME(arg1, arg2, macro, ...) macro
#define REMC_INTERNAL_ASSERT_GET_MACRO(...) REMC_EXPAND_MACRO( REMC_INTERNAL_ASSERT_GET_MACRO_NAME(__VA_ARGS__, REMC_INTERNAL_ASSERT_WITH_MSG, REMC_INTERNAL_ASSERT_NO_MSG) )

// Currently accepts at least the condition and one additional parameter (the message) being optional
#define REMC_ASSERT(...) REMC_EXPAND_MACRO( REMC_INTERNAL_ASSERT_GET_MACRO(__VA_ARGS__)(_, __VA_ARGS__) )
#define REMC_CORE_ASSERT(...) REMC_EXPAND_MACRO( REMC_INTERNAL_ASSERT_GET_MACRO(__VA_ARGS__)(_CORE_, __VA_ARGS__) )
#else
#define REMC_ASSERT(...)
#define REMC_CORE_ASSERT(...)
#endif