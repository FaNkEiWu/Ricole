workspace "Ricole"
    architecture "x64"
    configurations { "Debug", "Release", "Dist" }

outputdir = "%{cfg.buildcfg}-%{cfg.system}-%{cfg.architecture}"

-- include directories relative to root folder
IncludeDir = {}
IncludeDir["GLFW"] = "Ricole/vendor/GLFW/include"

include "Ricole/vendor/GLFW"

project "Ricole"
    location "Ricole"
    kind "SharedLib"
    language "C++"

    targetdir ("bin/" .. outputdir .. "/%{prj.name}")
    objdir ("bin-int/" .. outputdir .. "/%{prj.name}")

    pchheader "rcpch.h"
    pchsource "Ricole/src/rcpch.cpp"

    files { 
        "%{prj.name}/src/**.h",
        "%{prj.name}/src/**.cpp"
    }
     
    includedirs {
        "%{prj.name}/src",
        "%{prj.name}/vendor/spdlog/include",
        "%{IncludeDir.GLFW}"
    }

    links {
        "GLFW",
        "opengl32.lib",
        "dwmapi.lib"
    }

    filter "system:windows"
        cppdialect "C++20"
        staticruntime "On"
        runtime "Release"
        systemversion "latest"

        defines {
            "RC_PLATFORM_WINDOWS",
            "RC_BUILD_DLL"
        }

        postbuildcommands {
            "{COPY} %{cfg.buildtarget.relpath} ../bin/" .. outputdir .. "/Ruth"
        }

    filter "configurations:Debug"
        defines "RC_DEBUG"
        symbols "On"

    filter "configurations:Release"
        defines "RC_RELEASE"
        symbols "On"

    filter "configurations:Dist"
        defines "RC_DIST"
        symbols "On"

project "Ruth"
    location "Ruth"
    kind "ConsoleApp"
    language "C++"

    targetdir ("bin/" .. outputdir .. "/%{prj.name}")
    objdir ("bin-int/" .. outputdir .. "/%{prj.name}")

    pchheader "rupch.h"
    pchsource "Ruth/src/rupch.cpp"

    files {
        "%{prj.name}/src/**.h",
        "%{prj.name}/src/**.cpp"
    }

    includedirs {
        "Ricole/vendor/spdlog/include",
        "Ricole/src"
    }
    
    links {
        "Ricole"
    }

    filter "system:windows"
        cppdialect "C++20"
        staticruntime "On"
        runtime "Release"
        systemversion "latest"

        defines {
            "RC_PLATFORM_WINDOWS"
        }

    filter "configurations:Debug"
        defines "RC_DEBUG"
        symbols "On"

    filter "configurations:Release"
        defines "RC_RELEASE"
        symbols "On"

    filter "configurations:Dist"
        defines "RC_DIST"
        symbols "On"