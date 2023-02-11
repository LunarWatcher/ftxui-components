
add_library(ftxui-ext
    ftxui-ext/components/Checkbox.cpp
)

find_path(FTXUI_INCLUDE_PATH ftxui/component/component_base.hpp)

target_link_libraries(ftxui-ext PUBLIC 
    ftxui::component ftxui::dom ftxui::screen
)
target_include_directories(ftxui-ext PUBLIC ./)
