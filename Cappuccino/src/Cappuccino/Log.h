#pragma once

#include <memory>

#include "Core.h"
#include "spdlog/spdlog.h"
#include "spdlog/fmt/ostr.h"

namespace Cappuccino {
	class CAP_API Log
	{
	public:
		static void Init();

		inline static std::shared_ptr<spdlog::logger>& GetCoreLogger() { return s_CoreLogger;}
		inline static std::shared_ptr<spdlog::logger>& GetClientLogger() { return s_ClientLogger;}
	private:
		static std::shared_ptr<spdlog::logger> s_CoreLogger;
		static std::shared_ptr<spdlog::logger> s_ClientLogger;
	};
}


//Core log macros
#define CP_CORE_INFO(...)    ::Cappuccino::Log::GetCoreLogger()->info(__VA_ARGS__)
#define CP_CORE_TRACE(...)   ::Cappuccino::Log::GetCoreLogger()->trace(__VA_ARGS__)
#define CP_CORE_WARN(...)    ::Cappuccino::Log::GetCoreLogger()->warn(__VA_ARGS__)
#define CP_CORE_ERROR(...)   ::Cappuccino::Log::GetCoreLogger()->error(__VA_ARGS__)
#define CP_CORE_FATAL(...)   ::Cappuccino::Log::GetCoreLogger()->fatal(__VA_ARGS__)

//Client log macros
#define CP_FATAL(...)        ::Cappuccino::Log::GetClientLogger()->fatal(__VA_ARGS__)
#define CP_INFO(...)         ::Cappuccino::Log::GetClientLogger()->info(__VA_ARGS__)
#define CP_ERROR(...)        ::Cappuccino::Log::GetClientLogger()->error(__VA_ARGS__)
#define CP_TRACE(...)        ::Cappuccino::Log::GetClientLogger()->trace(__VA_ARGS__)
#define CP_WARN(...)         ::Cappuccino::Log::GetClientLogger()->warn(__VA_ARGS__)


