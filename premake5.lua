workspace "Remc"
	architecture "x64"

	configurations
	{
		"Debug",
		"Release",
		"Dist"
	}
	
startproject "Sandbox" 

outputdir = "%{cfg.buildcfg}-%{cfg.system}-%{cfg.architecture}"

IncludeDir = {}
IncludeDir["GLFW"] = "Remc/vendor/GLFW/include"
IncludeDir["GLad"] = "Remc/vendor/GLad/include"
IncludeDir["ImGui"] = "Remc/vendor/imgui"
IncludeDir["glm"] = "Remc/vendor/glm"

group "Dependencies"
	include "Remc/vendor/GLFW"
	include "Remc/vendor/GLad"
	include "Remc/vendor/imgui"

group ""

project "Remc"
		location "Remc"
		kind "SharedLib"
		language "C++"
		staticruntime "off"

		targetdir ("bin/" .. outputdir .. "/%{prj.name}")
		objdir ("bin-int/" .. outputdir .. "/%{prj.name}")

		pchheader "rcpch.h"
		pchsource "Remc/src/rcpch.cpp"

		files
		{
			"%{prj.name}/src/**.h",
			"%{prj.name}/src/**.cpp",
			"%{prj.name}/vendor/glm/glm/**.hpp",
			"%{prj.name}/vendor/glm/glm/**.inl"
		}

		includedirs
		{
			"%{prj.name}/src",
			"%{prj.name}/vendor/spdlog/include",
			"%{IncludeDir.GLFW}",
			"%{IncludeDir.GLad}",
			"%{IncludeDir.ImGui}",
			"%{IncludeDir.glm}"
		}

		links
		{
			"GLFW",
			"GLad",
			"ImGui",
			"opengl32.lib"
		}

		filter "system:windows"
			cppdialect "C++17"
			systemversion "latest"

			defines
			{
				"REMC_PLATFORM_WINDOWS",
				"REMC_BUILD_DLL",
				"GLFW_INCLUDE_NONE"
			}

			postbuildcommands
			{
				("{COPY} %{cfg.buildtarget.relpath} \"../bin/" .. outputdir .. "/Sandbox/\"")
			}

		filter "configurations:Debug"
			defines "REMC_DEBUG"
			runtime "Debug"
			symbols "On"

		filter "configurations:Release"
			defines "REMC_RELEASE"
			runtime "Release"
			optimize "On"

		filter "configurations:Dist"
			defines "REMC_DIST"
			runtime "Release"
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
		"Remc/src",
		"Remc/vendor",
		"%{IncludeDir.glm}"
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
		runtime "Debug"
		symbols "On"

	filter "configurations:Release"
		defines "REMC_RELEASE"
		runtime "Release"
		optimize "On"

	filter "configurations:Dist"
		defines "REMC_DIST"
		runtime "Release"
		optimize "On"

