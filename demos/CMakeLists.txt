message (STATUS "ftxui-components: Demos enabled")

set(CMAKE_ARCHIVE_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/bin)
set(CMAKE_LIBRARY_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/bin)
set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/bin)

function(demo binName fileName)
    add_executable(ftxui-ext-demo-${binName} src/${fileName}.cpp)
    target_link_libraries(ftxui-ext-demo-${binName}
        ftxui-ext # This library
        ftxui::component ftxui::dom ftxui::screen # Ftxui builtins (why isn't there an alias for these? Ugh)
    )
endfunction()

demo(wrapping TextWrapping)
# Dependencies {{{
include(FetchContent)

FetchContent_Declare(ftxui
  GIT_REPOSITORY https://github.com/ArthurSonzogni/ftxui
)

# Why the actual FUCK are these enabled by default?
# This will not affect consumers, but WHY?! Why isn't there a check to disable them
# when there's a consumer application?
set (FTXUI_BUILD_DOCS OFF CACHE INTERNAL "")
set (FTXUI_BUILD_EXAMPLES OFF CACHE INTERNAL "")
set (FTXUI_ENABLE_INSTALL OFF CACHE INTERNAL "")

FetchContent_GetProperties(ftxui)
if(NOT ftxui_POPULATED)
  FetchContent_Populate(ftxui)
  add_subdirectory(${ftxui_SOURCE_DIR} ${ftxui_BINARY_DIR})
endif()

# }}}
