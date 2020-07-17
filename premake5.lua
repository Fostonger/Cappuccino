workspace "Cappuccino"
	architecture "x64"

	configurations {
		"Debug",
		"Release",
		"Dist"
	}

outputdir = "%{cfg.buildcfg}-%{cfg.system}-%{cfg.architecture}"

-- Include directories relative to root folder (solution direstory)
IncludeDir = {}
IncludeDir["GLFW"] = "Cappuccino/vendor/GLFW/include"

include "Cappuccino/vendor/GLFW"

project "Cappuccino"
	location "Cappuccino"
	kind "SharedLib"
	language "C++"

	targetdir ("bin/" .. outputdir .. "/%{prj.name}")
	objdir ("bin-int/" .. outputdir .. "/%{prj.name}")

	pchheader "cappch.h"
	pchsource "Cappuccino/src/cappch.cpp"

	files{
		"%{prj.name}/src/**.h",
		"%{prj.name}/src/**.cpp"
	}

	includedirs{
		"%{prj.name}/vendor/spdlog/include",
		"%{prj.name}/src",
		"%{IncludeDir.GLFW}"
	}

	links{
		"GLFW",
		"opengl32.lib"
	}

	filter "system:windows"
		cppdialect "C++17"
		staticruntime "On"
		systemversion "latest"

		defines{
			"CAP_PLATFORM_WINDOWS",
			"CAP_BUILD_DLL"
		}

		postbuildcommands{
			("{COPY} %{cfg.buildtarget.relpath} ../bin/" .. outputdir .. "/Sandbox")
		}

	filter "configurations:Debug"
		defines "CAP_DEBUG"
		symbols "On"

	filter "configurations:Release"
		defines "CAP_RELEASE"
		optimize "On"

	filter "configurations:Dist"
		defines "CAP_DIST"
		optimize "On"

project "Sandbox"
	location "Sandbox"
	kind "ConsoleApp"

	language "C++"

	targetdir ("bin/" .. outputdir .. "/%{prj.name}")
	objdir ("bin-int/" .. outputdir .. "/%{prj.name}")

	files{
		"%{prj.name}/src/**.h",
		"%{prj.name}/src/**.cpp"
	}

	includedirs{
		"Cappuccino/vendor/spdlog/include",
		"Cappuccino/src"
	}

	links{
		"Cappuccino"
	}

	filter "system:windows"
		cppdialect "C++17"
		staticruntime "On"
		systemversion "latest"

		defines{
			"CAP_PLATFORM_WINDOWS"
		}

	filter "configurations:Debug"
		defines "CAP_DEBUG"
		symbols "On"

	filter "configurations:Release"
		defines "CAP_RELEASE"
		optimize "On"

	filter "configurations:Dist"
		defines "CAP_DIST"
		optimize "On"
