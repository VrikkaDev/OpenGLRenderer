file(GLOB_RECURSE src_files
        "src/*.h"
        "src/*.cpp")

cmake_minimum_required(VERSION 3.24)
project(openglrendering)

set(CMAKE_CXX_STANDARD 17)

set(CMAKE_MODULE_PATH "cmke")
include(CMake/cotire.cmake)

set(OpenGL_GL_PREFERENCE GLVND)
set(GLFW_BUILD_DOCS OFF CACHE BOOL "" FORCE)
set(GLFW_BUILD_TESTS OFF CACHE BOOL "" FORCE)
set(GLFW_BUILD_EXAMPLES OFF CACHE BOOL "" FORCE)

add_subdirectory("vendor/glfw")
add_subdirectory("vendor/glm")
add_subdirectory("vendor/glad")


find_package(OpenGL REQUIRED)
include_directories(${OPENGL_INCLUDE_DIRS})
find_package(Threads REQUIRED)

add_executable(openglrendering ${src_files})

target_link_libraries(openglrendering PUBLIC glfw ${GLFW_LIBRARIES} ${OPENGL_LIBRARIES}
        glm glad)
set_target_properties(openglrendering PROPERTIES COTIRE_CXX_PREFIX_HEADER_INIT "src/pch.h")
cotire(openglrendering)
target_include_directories(openglrendering PUBLIC "vendor" PUBLIC "src")
set_target_properties(openglrendering PROPERTIES LINKER_LANGUAGE CXX)
