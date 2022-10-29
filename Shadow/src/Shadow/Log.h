#pragma once

#include "Core.h"
#include "spdlog/spdlog.h"
#include "spdlog/fmt/ostr.h"

namespace Shadow {

	class SW_API Log
	{
	public:
		static void Init();

		inline static std::shared_ptr<spdlog::logger>& GetCoreLogger() { return s_CoreLogger; }
		inline static std::shared_ptr<spdlog::logger>& GetClientLogger() { return s_ClientLogger; }
	private:
		static std::shared_ptr<spdlog::logger> s_CoreLogger;
		static std::shared_ptr<spdlog::logger> s_ClientLogger;
	};

}

#define SW_CORE_TRACE(...)        ::Shadow::Log::GetClientLogger()->trace(__VA_ARGS__);
#define SW_CORE_INFO(...)         ::Shadow::Log::GetClientLogger()->info(__VA_ARGS__);
#define SW_CORE_WARN(...)         ::Shadow::Log::GetClientLogger()->warn(__VA_ARGS__);
#define SW_CORE_ERROR(...)        ::Shadow::Log::GetClientLogger()->error(__VA_ARGS__);
#define SW_CORE_FATAL(...)        ::Shadow::Log::GetClientLogger()->fatal(__VA_ARGS__);

#define SW_TRACE(...)      ::Shadow::Log::GetClientLogger()->trace(__VA_ARGS__);
#define SW_INFO(...)       ::Shadow::Log::GetClientLogger()->info(__VA_ARGS__);
#define SW_WARN(...)       ::Shadow::Log::GetClientLogger()->warn(__VA_ARGS__);
#define SW_ERROR(...)      ::Shadow::Log::GetClientLogger()->error(__VA_ARGS__);
#define SW_FATAL(...)      ::Shadow::Log::GetClientLogger()->fatal(__VA_ARGS__);