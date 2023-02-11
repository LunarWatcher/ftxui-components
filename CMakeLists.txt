cmake_minimum_required(VERSION 3.15)
project(ftxui-ext)



if (CMAKE_PROJECT_NAME STREQUAL PROJECT_NAME)
    message (STATUS "ftxui-components: Running standalone")
    set (ENABLE_DEMOS ON)
else()
    message (STATUS "ftxui-components: Running as a submodule; disabling dependencies.")
    set (ENABLE_DEMOS OFF)
endif()

set(CMAKE_CXX_STANDARD 20)

if (ENABLE_DEMOS)
    add_subdirectory(demos)
endif()
add_subdirectory(src)

# vim:ft=cmake
