include "./vendor/premake/premake_customization/solution_items.lua"

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
IncludeDir["GLFW"] = "%{wks.location}/Remc/vendor/GLFW/include"
IncludeDir["Glad"] = "%{wks.location}/Remc/vendor/Glad/include"
IncludeDir["ImGui"] = "%{wks.location}/Remc/vendor/imgui"
IncludeDir["glm"] = "%{wks.location}/Remc/vendor/glm"
IncludeDir["stb_image"] = "%{wks.location}/Remc/vendor/stb_image"
IncludeDir["entt"] = "%{wks.location}/Remc/vendor/entt/include"
IncludeDir["yaml_cpp"] = "%{wks.location}/Remc/vendor/yaml-cpp/include"

group "Dependencies"
	include "vendor/premake"
	include "Remc/vendor/GLFW"
	include "Remc/vendor/GLad"
	include "Remc/vendor/imgui"
	include "Remc/vendor/yaml-cpp"

group ""

include "Remc"
include "Sandbox"
include "RTShell"