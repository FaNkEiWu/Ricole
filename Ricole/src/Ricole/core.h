#pragma once

#ifdef RC_PLATFORM_WINDOWS
	#ifdef RC_BUILD_DLL
		#define RICOLE_API __declspec(dllexport)
	#else
		#define RICOLE_API __declspec(dllimport)
	#endif
#else
	#error Ricole only support Windows!
#endif // RC_PLATFORM_WINDOWS

#define BIT(x) (1 << x)
