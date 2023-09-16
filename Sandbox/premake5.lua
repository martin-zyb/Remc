project "Sandbox"
	kind "ConsoleApp"
	language "C++"
	cppdialect "C++17"
	staticruntime "on"

	targetdir ("%{wks.location}/bin/" .. outputdir .. "/%{prj.name}")
	objdir ("%{wks.location}/bin-int/" .. outputdir .. "/%{prj.name}")

	files
	{
		"src/**.h",
		"src/**.cpp"
	}

	includedirs
	{
		"%{wks.location}/Remc/vendor/spdlog/include",
		"%{wks.location}/Remc/src",
		"%{wks.location}/Remc/vendor",
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