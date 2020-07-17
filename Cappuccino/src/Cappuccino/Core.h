#pragma once

#ifdef CAP_PLATFORM_WINDOWS
	#ifdef CAP_BUILD_DLL
		#define CAP_API _declspec(dllexport)
	#else 
		#define CAP_API _declspec(dllimport)
	#endif
#endif

#ifdef CP_ENABLE_ASSERTS
	#define CP_ASSERT(x, ...) { if(!(x)) {CP_ERROR("Assertion failed: {0}," __VA_ARGS__); __debugbreak(); } }
	#define CP_CORE_ASSERT(x, ...) { if(!(x)) {CP_CORE_ERROR("Assertion failed: {0}," __VA_ARGS__); __debugbreak(); } } 
#else
	#define CP_ASSERT(x, ...)
	#define CP_CORE_ASSERT(x, ...)
	
#endif

#define BIT(x) (1 << x)