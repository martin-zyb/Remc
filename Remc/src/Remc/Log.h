#pragma once

#include <memory>

#include "Core.h"
#include "spdlog/spdlog.h"
#include "spdlog/fmt/ostr.h"
#include "spdlog/sinks/stdout_color_sinks.h"

namespace Remc
{
	class REMC_API Log
	{
	private:
		static std::shared_ptr<spdlog::logger> s_CoreLogger;
		static std::shared_ptr<spdlog::logger> s_ClientLogger;
	public:
		static void Init();

		inline static std::shared_ptr<spdlog::logger>& GetCoreLogger() { return s_CoreLogger; }
		inline static std::shared_ptr<spdlog::logger>& GetClientLogger() { return s_ClientLogger; }
	};

}

// Core Log macros
#define REMC_CORE_TRACE(...)    ::Remc::Log::GetCoreLogger()->trace(__VA_ARGS__)
#define REMC_CORE_INFO(...)      ::Remc::Log::GetCoreLogger()->info(__VA_ARGS__)
#define REMC_CORE_WARN(...)   ::Remc::Log::GetCoreLogger()->warn(__VA_ARGS__)
#define REMC_CORE_ERROR(...)   ::Remc::Log::GetCoreLogger()->error(__VA_ARGS__)
#define REMC_CORE_FATAL(...)    ::Remc::Log::GetCoreLogger()->fatal(__VA_ARGS__)

// Client Log macros
#define REMC_TRACE(...)    ::Remc::Log::GetClientLogger()->trace(__VA_ARGS__)
#define REMC_INFO(...)       ::Remc::Log::GetClientLogger()->info(__VA_ARGS__)
#define REMC_WARN(...)    ::Remc::Log::GetClientLogger()->warn(__VA_ARGS__)
#define REMC_ERROR(...)    ::Remc::Log::GetClientLogger()->error(__VA_ARGS__)
#define REMC_FATAL(...)     ::Remc::Log::GetClientLogger()->fatal(__VA_ARGS__)