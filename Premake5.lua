workspace "Shadow"
	architecture "x64"

	configurations
	{
		"Debug",
		"Release",
		"Dist"
	}

outputdir = "%{cfg.buildcfg}-%{cfg.system}-%{cfg.architecture}"

-- Include directories relative to root folder (solution directory)
IncludeDir = {}
IncludeDir["GLFW"] = "Shadow/vendor/GLFW/include"
IncludeDir["Glad"] = "Shadow/vendor/Glad/include"
IncludeDir["ImGui"] = "Shadow/vendor/imgui"

include "Shadow/vendor/GLFW"
include "Shadow/vendor/Glad"
include "Shadow/vendor/imgui"

project "Shadow"
	location "Shadow"
	kind "SharedLib"
	language "C++"
	staticruntime "off"

	targetdir ("bin/" .. outputdir .. "/%{prj.name}")
	objdir ("bin-int/" .. outputdir .. "/%{prj.name}")

	pchheader "swpch.h"
	pchsource "Shadow/src/swpch.cpp"

	files
	{
		"%{prj.name}/src/**.h",
		"%{prj.name}/src/**.cpp"
	}

	includedirs
	{
		"%{prj.name}/src",
		"%{prj.name}/vendor/spdlog/include",
		"%{IncludeDir.GLFW}",
		"%{IncludeDir.Glad}",
		"%{IncludeDir.ImGui}"
	}

	links 
	{ 
		"GLFW",
		"Glad",
		"ImGui",
		"opengl32.lib"
	}

	filter "system:windows"
		cppdialect "C++17"
		systemversion "latest"

		defines
		{
			"SW_PLATFORM_WINDOWS",
			"SW_BUILD_DLL",
			"GLFW_INCLUDE_NONE"
		}

		postbuildcommands
		{
			("{COPY} %{cfg.buildtarget.relpath} ../bin/" .. outputdir .. "/Sandbox")
		}

	filter "configurations:Debug"
		defines "SW_DEBUG"
		runtime "Debug"
		symbols "On"

	filter "configurations:Release"
		defines "SW_RELEASE"
		runtime "Release"
		optimize "On"

	filter "configurations:Dist"
		defines "SW_DIST"
		runtime "Release"
		optimize "On"

project "Sandbox"
	location "Sandbox"
	kind "ConsoleApp"
	language "C++"
	staticruntime "off"

	targetdir ("bin/" .. outputdir .. "/%{prj.name}")
	objdir ("bin-int/" .. outputdir .. "/%{prj.name}")

	files
	{
		"%{prj.name}/src/**.h",
		"%{prj.name}/src/**.cpp"
	}

	includedirs
	{
		"Shadow/vendor/spdlog/include",
		"Shadow/src"
	}

	links
	{
		"Shadow"
	}

	filter "system:windows"
		cppdialect "C++17"
		systemversion "latest"

		defines
		{
			"SW_PLATFORM_WINDOWS"
		}

	filter "configurations:Debug"
		defines "SW_DEBUG"
		runtime "Debug"
		symbols "On"

	filter "configurations:Release"
		defines "SW_RELEASE"
		runtime "Release"
		optimize "On"

	filter "configurations:Dist"
		defines "SW_DIST"
		runtime "Release"
		optimize "On"