cmake_minimum_required (VERSION 3.11)

include(FetchContent)
set(FETCHCONTENT_UPDATES_DISCONNECTED TRUE)
FetchContent_Declare(ftxui
        GIT_REPOSITORY https://github.com/ArthurSonzogni/ftxui
        GIT_TAG e213cfda372114fd551e20eddbf4263df6c8f759 # Important: Specify a version or a commit hash here.
)
FetchContent_MakeAvailable(ftxui)

project(main LANGUAGES CXX VERSION 1.0.0)
add_executable(main src/main.cpp src/styles.cpp
        src/file.cpp
        src/file.h)
target_link_libraries(main
        PRIVATE ftxui::screen
        PRIVATE ftxui::dom
        PRIVATE ftxui::component # Not needed for this example.
)