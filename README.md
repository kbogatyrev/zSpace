**This is Konstantin's implementation of Conway's Game of Life.**
  
The code was written in C++98 with Visual Studio 2022 Community Edition and built using cmake 
with MSVC and GCC compilers. It was tested on Windows 10 and on Windows Subsystem for Linux running 
Ubuntu 20.04. I was unable to create a MacOS build.

The easiest way to build the project is using Visual Studio: just open this folder and follow 
the prompts. To build from a command line (assuming Windows build environment with cmake):

-- cd to this directory:
>cd GameOfLife

-- create the build directory:  
>mkdir build

-- cd to the build directory:  
>cd build

-- configure the build:  
>cmake ..

-- build the executable: 
>cmake --build . --config Release

(or "...config Debug" for debug builds) 

The Windows executable gol.exe will be in the build\Release or (build\Debug) directory.
The Linux binary gol will be written to the build directory.

