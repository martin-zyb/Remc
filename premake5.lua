workspace "Remc"
	architecture "x86_64"
	startproject "RTShell"

	configurations
	{
		"Debug",
		"Release",
		"Dist"
	}

	flags
	{
		"MultiProcessorCompile"
	}

outputdir = "%{cfg.buildcfg}-%{cfg.system}-%{cfg.architecture}"

-- Include directories relative to root folder (solution directory)
IncludeDir = {}
IncludeDir["GLFW"] = "Remc/vendor/GLFW/include"
IncludeDir["Glad"] = "Remc/vendor/Glad/include"
IncludeDir["ImGui"] = "Remc/vendor/imgui"
IncludeDir["glm"] = "Remc/vendor/glm"
IncludeDir["stb_image"] = "Remc/vendor/stb_image"
IncludeDir["entt"] = "Remc/vendor/entt/include"

group "Dependencies"
	include "Remc/vendor/GLFW"
	include "Remc/vendor/GLad"
	include "Remc/vendor/imgui"

group ""

project "Remc"
	location "Remc"
	kind "StaticLib"
	language "C++"
	cppdialect "C++17"
	staticruntime "on"

	targetdir ("bin/" .. outputdir .. "/%{prj.name}")
	objdir ("bin-int/" .. outputdir .. "/%{prj.name}")

	pchheader "rcpch.h"
	pchsource "Remc/src/rcpch.cpp"

	files
	{
		"%{prj.name}/src/**.h",
		"%{prj.name}/src/**.cpp",
		"%{prj.name}/vendor/stb_image/**.h",
		"%{prj.name}/vendor/stb_image/**.cpp",
		"%{prj.name}/vendor/glm/glm/**.hpp",
		"%{prj.name}/vendor/glm/glm/**.inl",
	}

	defines
	{
		"_CRT_SECURE_NO_WARNINGS",
		"GLFW_INCLUDE_NONE"
	}

	includedirs
	{
		"%{prj.name}/src",
		"%{prj.name}/vendor/spdlog/include",
		"%{IncludeDir.GLFW}",
		"%{IncludeDir.Glad}",
		"%{IncludeDir.ImGui}",
		"%{IncludeDir.glm}",
		"%{IncludeDir.stb_image}",
		"%{IncludeDir.entt}"
	}

	links 
	{ 
		"GLFW",
		"Glad",
		"ImGui",
		"opengl32.lib"
	}

	filter "system:windows"
		systemversion "latest"

		defines
		{
			"REMC_BUILD_DLL",
		}

	filter "configurations:Debug"
		defines "REMC_DEBUG"
		runtime "Debug"
		symbols "on"

	filter "configurations:Release"
		defines "REMC_RELEASE"
		runtime "Release"
		optimize "on"

	filter "configurations:Dist"
		defines "REMC_DIST"
		runtime "Release"
		optimize "on"

project "Sandbox"
	location "Sandbox"
	kind "ConsoleApp"
	language "C++"
	cppdialect "C++17"
	staticruntime "on"

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
		systemversion "latest"

	filter "configurations:Debug"
		defines "REMC_DEBUG"
		runtime "Debug"
		symbols "on"

	filter "configurations:Release"
		defines "REMC_RELEASE"
		runtime "Release"
		optimize "on"

	filter "configurations:Dist"
		defines "REMC_DIST"
		runtime "Release"
		optimize "on"

project "RTShell"
	location "RTShell"
	kind "ConsoleApp"
	language "C++"
	cppdialect "C++17"
	staticruntime "on"

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
		"%{IncludeDir.glm}",
		"%{IncludeDir.entt}"
	}

	links
	{
		"Remc"
	}

	filter "system:windows"
		systemversion "latest"

	filter "configurations:Debug"
		defines "REMC_DEBUG"
		runtime "Debug"
		symbols "on"

	filter "configurations:Release"
		defines "REMC_RELEASE"
		runtime "Release"
		optimize "on"

	filter "configurations:Dist"
		defines "REMC_DIST"
		runtime "Release"
		optimize "on"