#pragma once

#ifdef SW_PLATFORM_WINDOWS
	#ifdef SW_BUILD_DLL
		#define SW_API __declspec(dllexport)
	#else
		#define SW_API __declspec(dllimport)
	#endif 
#else
	#error Shadow only supports Windows
#endif

#ifdef SW_DEBUG
	#define SW_ENABLE_ASSERTS
#endif

#ifdef SW_ENABLE_ASSERTS
#define SW_ASSERT(x, ...) { if(!(x)) { SW_ERROR("Assertion Failed: {0}", __VA_ARGS__); __debugbreak(); } }
#define SW_CORE_ASSERT(x, ...) { if(!(x)) { SW_CORE_ERROR("Assertion Failed: {0}", __VA_ARGS__); __debugbreak(); } }
#else
#define SW_ASSERT(x, ...)
#define SW_CORE_ASSERT(x, ...)
#endif

#define BIT(x) (1 << x)

#define SW_BIND_EVENT_FN(fn) std::bind(&fn, this, std::placeholders::_1)