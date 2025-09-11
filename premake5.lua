workspace "DND_START"
    architecture "x64"

   configurations { "Debug", "Release", "Dist" }
   platforms { "x64" }
   location "build"

   filter "configurations:Debug"
      defines { "DEBUG" }
      symbols "On"

   filter "configurations:Release"
      defines { "NDEBUG" }
      optimize "On"

   filter {}

outputdir = "%{cfg.buildcfg}-%{cfg.system}-%{cfg.architecture}"

project "engine"
   location "engine"
   kind "SharedLib"
   language "C++"

   targetdir ("bin/" .. outputdir .. "/engine")
   objdir ("bin-int/" .. outputdir .. "/engine")

   files { "engine/src/**.h", "engine/src/**.cpp" } 

   includedirs {"engine/vendor/spdlog/include", "engine/src" }

    filter "system:windows"
        cppdialect "C++17"
        staticruntime "On"
        systemversion "latest"

        defines {
            "ENGINE_PLATFORM_WINDOWS",
            "ENGINE_BUILD_DLL",
            "_WINDLL"
         }

         postbuildcommands {
            ("{COPY} %{cfg.buildtarget.relpath} ../bin/" .. outputdir .. "/sandbox")
         }

    filter "configurations:Dist"
        defines "ENGINE_DIST"
        optimize "On"

   -- ENGINE_PLATFORM_WINDOWS;ENGINE_BUILD_DLL;_WIN_DLL;

project "sandbox"
   location "sandbox"
   kind "ConsoleApp"
   language "C++"

   targetdir ("bin/" .. outputdir .. "/%{prj.name}")
   objdir ("bin-int/" .. outputdir .. "/%{prj.name}")

   files { "%{prj.name}/src/**.h", "%{prj.name}/src/**.cpp" } 

   includedirs {"engine/vendor/spdlog/include" }

    links { "engine" }

    filter "system:windows"
        cppdialect "C++17"
        staticruntime "On"
        systemversion "latest"

        defines {
            "SANDBOX_PLATFORM_WINDOWS"
         }

    filter "configurations:Dist"
        defines "SANDBOX_DIST"
        optimize "On"