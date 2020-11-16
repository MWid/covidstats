# covidstats
This little command line tool retrieves the daily new infections with COVID 19 as reported by the [RKI](https://www.rki.de).

# Usage
```cmd
covidstats - Command line tool to retrieve the new cases of COVID 19 infections as published by RKI.
Allowed options:
  -h [ --help ]         print usage message
  -o [ --output ] arg   pathname for output (if empty, stdout is used)
```

# Building from source
Builds are only tested under Windows 10 using MSBuild Tools 2019 (16.8.1).

## Prerequisites (Windows)
You need a current C++ compiler supporting C++ 17 and [CMake](https://cmake.org/).

## Cloning repository
To build from source you need to clone this repository first. Since this repository uses the package manager [vcpkg](https://github.com/microsoft/vcpkg) as a git submodule you have to run the following command:
```cmd
git clone --recurse-submodules https://github.com/MWid/covidstats.git
```

## Building vcpkg
Open a command prompt for VS 2019 and change directory to the subdirectory `sripts/vcpkg`. Then run
```cmd
bootstrap-vcpkg.bat
```

## Installing dependencies
The following libraries are requiered:
* [cpprestsdk](https://github.com/microsoft/cpprestsdk)
* [Boost](https://www.boost.org/)
* [nlohmann_json](https://github.com/nlohmann/json)

To install them just type
```cmd
scripts/vcpkg/vcpkg.exe install boost-algorithm:x64-windows boost-program-options:x64-windows nlohmann-json:x64-windows cpprestsdk:x64-windows
```
Now go for a coffee! This step takes some time.

## Building covidstats
From the root of your cloned repository run CMake:
```cmd
cmake -DCMAKE_TOOLCHAIN_FILE:STRING=scripts/vcpkg/scripts/buildsystems/vcpkg.cmake -S . -B ../build -G "Visual Studio 16 2019"
```
This command generates the neccessary files for building covidstats. These files are written to the directoy `build` parallel to your source directory. If you have Visual Studio 2019 installed you can open the generated solution `covidstats.sln` and build the solution as usual. Or you can just run CMake again this time from within the `build` directory:
```cmd
cmake --build . --config Release --target ALL_BUILD
```
If everything works as expected you find the executable `covidstats` (and 2 dlls) in the subdirectory `src/Release`.

## Building covidstats as single executable
If you want to build `covidstats` as a single executable without any dependencies (besides the dependencies to the C runtime) then copy the file [x64-windows-mixed.cmake](../blob/master/x64-windows-mixed.cmake) to the subdirectory `scripts/vcpkg/triplets` of your source directory and then run:
```cmd
scripts/vcpkg/vcpkg.exe install boost-algorithm:x64-windows-mixed boost-program-options:x64-windows-mixed nlohmann-json:x64-windows-mixed cpprestsdk:x64-windows-mixed
```
Also when running CMake the first time to generate the build files you must run:
```cmd
cmake -DCMAKE_TOOLCHAIN_FILE:STRING=scripts/vcpkg/scripts/buildsystems/vcpkg.cmake -DVCPKG_TARGET_TRIPLET:STRING=x64-windows-mixed -S . -B ../build -G "Visual Studio 16 2019"
```
At last just run
```cmd
cmake --build . --config Release --target ALL_BUILD
```
again. That's it!
