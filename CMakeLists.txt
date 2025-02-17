cmake_minimum_required(VERSION 3.10)
project(RayTracingInOneWeekend
    LANGUAGES CXX
)

set(CMAKE_CXX_STANDARD 11)
set(CMAKE_CXX_FLAGS "-Wall -Wextra -pedantic -g3")
set(CMAKE_EXPORT_COMPILE_COMMANDS ON)

set(EXEC_NAME RayTracer)
add_executable(${EXEC_NAME})

target_sources(${EXEC_NAME} PRIVATE
    src/main.cpp
    src/Vec3.cpp
    src/Vec3.hpp
    src/Color.cpp
    src/Color.hpp
    src/Ray.cpp
    src/Ray.hpp
)

target_include_directories(${EXEC_NAME} PUBLIC
    src
)
