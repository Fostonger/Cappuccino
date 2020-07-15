#pragma once

#ifdef CAP_PLATFORM_WINDOWS
	#ifdef CAP_BUILD_DLL
		#define CAP_API _declspec(dllexport)
	#else 
		#define CAP_API _declspec(dllimport)
	#endif
#endif

#define BIT(x) (1 << x)