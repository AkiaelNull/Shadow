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

#define BIT(x) (1 << x)