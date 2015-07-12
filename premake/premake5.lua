
solution "bitbuf_test"
    basedir ".."
    location (_ACTION)
    startproject "bitbuf_test"
    configurations { "Debug", "Release" }
    platforms "x32"
    flags { "MultiProcessorCompile", "Symbols" }

    -- GCC specific build options.
    configuration "gmake"
        -- Enables C++11 support.
        buildoptions { "-std=c++0x" }
    configuration {}

    project "bitbuf_test"
        kind "ConsoleApp"
        language "C++"
        files
        {
            "../sourcesdk/**.h",
            "../sourcesdk/**.cpp",
            "../tests/**.h",
            "../tests/**.cpp"
        }
        includedirs
        {
            "../sourcesdk/include"
        }

        configuration "Debug"
            targetdir (_ACTION .. "/build/Debug")
            defines { "DEBUG" }

        configuration "Release"
            targetdir (_ACTION .. "/build/Release")
            defines { "NDEBUG" }
            optimize "Full"
        configuration {}
