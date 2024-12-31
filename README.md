mc_rtc new robot module template
==

This project is a template for a new robot module project wihtin [mc_rtc]

It comes with:
- a CMake project that can build a controller in [mc_rtc], the project can be put within [mc_rtc] source-tree for easier updates
- clang-format files
- automated GitHub Actions builds on three major platforms

This repository actually creates two robot modules:
- `Kuavo4pro` is a C++ robot module in the [src](src) folder
- `Kuavo4proYAML` is a YAML robot module in the [yaml](yaml) folder

They both re-create the JVRC1 robot module shipped with [mc_rtc]

Quick start
--

1. Renaming the robot module from `Kuavo4pro` to `MyRobotModule`. In a shell (Git Bash on Windows, replace sed with gsed on macOS):

```bash
sed -i -e's/Kuavo4pro/MyRobotModule/g' `find . -type f`
```

2. If you choose to build a C++ robot module

```bash
git rm -rf yaml
sed -i -e's/add_subdirectory(yaml)//' CMakeLists.txt
git mv src/Kuavo4pro.in.cpp src/MyRobotModule.in.cpp
git mv src/Kuavo4pro.h src/MyRobotModule.h
```

3. If you choose to build a YAML robot module

```bash
git rm -rf src
sed -i -e's/add_subdirectory(src)//' CMakeLists.txt
```

4. You can customize the project name in vcpkg.json as well, note that this must follow [vcpkg manifest rules](https://github.com/microsoft/vcpkg/blob/master/docs/users/manifests.md)

5. Build and install the project

6. Run using your [mc_rtc] interface of choice, and setting `MainRobot` to `MyRobotModule`

[mc_rtc]: https://jrl-umi3218.github.io/mc_rtc/



# Notes

### Installation

- Do not put in catkin_ws

- Use mkdir build, cd, make .., make, (sudo) make install to compile the robot module

### Use name Kuavo4pro in mc-rtc

### Collision Pair is not added yet