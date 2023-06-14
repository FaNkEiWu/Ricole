#pragma once

#include "Core.h"

#include "spdlog/spdlog.h"
#include "spdlog/fmt/ostr.h"

namespace Ricole {

	class RICOLE_API Log {

	public:
		static void Init();

		inline static std::shared_ptr<spdlog::logger>& GetCoreLogger() { return s_CoreLogger; }
		inline static std::shared_ptr<spdlog::logger>& GetClientLogger() { return s_ClientLogger; }
	
	private :
		static std::shared_ptr<spdlog::logger> s_CoreLogger;
		static std::shared_ptr<spdlog::logger> s_ClientLogger;
	};

}

// Core log macros
#define RC_CORE_TRACE(...) ::Ricole::Log::GetCoreLogger()->trace(__VA_ARGS__)
#define RC_CORE_INFO(...)  ::Ricole::Log::GetCoreLogger()->info(__VA_ARGS__)
#define RC_CORE_WARN(...)  ::Ricole::Log::GetCoreLogger()->warn(__VA_ARGS__)
#define RC_CORE_ERROR(...) ::Ricole::Log::GetCoreLogger()->error(__VA_ARGS__)
#define RC_CORE_FATAL(...) ::Ricole::Log::GetCoreLogger()->fatal(__VA_ARGS__)

// Core log macros
#define RC_TRACE(...) ::Ricole::Log::GetClientLogger()->trace(__VA_ARGS__)
#define RC_INFO(...)  ::Ricole::Log::GetClientLogger()->info(__VA_ARGS__)
#define RC_WARN(...)  ::Ricole::Log::GetClientLogger()->warn(__VA_ARGS__)
#define RC_ERROR(...) ::Ricole::Log::GetClientLogger()->error(__VA_ARGS__)
#define RC_FATAL(...) ::Ricole::Log::GetClientLogger()->fatal(__VA_ARGS__)


