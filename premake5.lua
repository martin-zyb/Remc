workspace "Remc"
	architecture "x64"

	configurations
	{
		"Debug",
		"Release",
		"Dist"
	}

outputdir = "%{cfg.buildcfg}-%{cfg.system}/%{cfg.architecture}"

project "Remc"
		location "Remc"
		kind "SharedLib"
		language "C++"

		targetdir ("bin/" .. outputdir .. "/%{prj.name}")
		objdir ("bin-int/" .. outputdir .. "/%{prj.name}")

		pchheader "rcpch.h"
		pchsource "Remc/src/rcpch.cpp"

		files
		{
			"%{prj.name}/src/**.h",
			"%{prj.name}/src/**.cpp"
		}

		includedirs
		{
			"%{prj.name}/src",
			"%{prj.name}/vendor/spdlog/include"
		}

		filter "system:windows"
			cppdialect "C++17"
			staticruntime "On"
			systemversion "latest"

			defines
			{
				"REMC_PLATFORM_WINDOWS",
				"REMC_BUILD_DLL"
			}

			postbuildcommands
			{
				("{COPY} %{cfg.buildtarget.relpath} ../bin/" .. outputdir .. "/Sandbox")
			}

		filter "configurations:Debug"
			defines "REMC_DEBUG"
			symbols "On"

		filter "configurations:Release"
			defines "REMC_RELEASE"
			optimize "On"

		filter "configurations:Dist"
			defines "REMC_DIST"
			optimize "On"

project "Sandbox"
	location "Sandbox"
	kind "ConsoleApp"
	language "C++"

	targetdir ("bin/" .. outputdir .. "/%{prj.name}")
	objdir ("bin-int/" .. outputdir .. "/%{prj.name}")

	files
	{
		"%{prj.name}/src/**.h",
		"%{prj.name}/src/**.cpp"
	}

	includedirs
	{
		"Remc/vendor/spdlog/include",
		"Remc/src"
	}

	links
	{
		"Remc"
	}

	filter "system:windows"
		cppdialect "C++17"
		staticruntime "On"
		systemversion "latest"

		defines
		{
			"REMC_PLATFORM_WINDOWS"
		}

	filter "configurations:Debug"
		defines "REMC_DEBUG"
		symbols "On"

	filter "configurations:Release"
		defines "REMC_RELEASE"
		optimize "On"

	filter "configurations:Dist"
		defines "REMC_DIST"
		optimize "On"

