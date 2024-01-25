cmake_minimum_required (VERSION 3.16)

project (gol)
add_executable (gol)

if (MSVC)
	set(CMAKE_CXX_STANDARD 98)
	if (CMAKE_BUILD_TYPE MATCHES "Debug")
		message("   ***  MSVC DEBUG BUILD  ***")
		message (STATUS "Windows debug mode")
		add_compile_definitions(
			_DEBUG
			_CONSOLE
		)
		add_compile_options(
			/JMC /GS /W3 
			/Zi /Gm- /Od 
			/errorReport:prompt /WX- /Zc:forScope /RTC1 /Gd /MDd /FC 
			/diagnostics:column 
		)
	else()
		message("   ***  MSVC RELEASE BUILD  ***")
		message (STATUS "Windows release mode")
		add_compile_definitions(
			WIN32
			_CONSOLE
			NDEBUG
		)
		add_compile_options(
			/GS /GL /W3 /Gy 
			/Zi /Gm- /O2 
			/errorReport:prompt /WX- /Zc:forScope /Gd /Oi /MD 
			/FC 
			/EHsc /nologo 
			/diagnostics:column 
		)
	endif()
else()
	set(CMAKE_POSITION_INDEPENDENT_CODE ON)
	set(CMAKE_CXX_STANDARD 98)
    add_compile_options(-Wall -Wextra -pedantic -Werror)
endif()

target_sources (gol PRIVATE 
    GameOfLife.h
	GameOfLife.cc)

