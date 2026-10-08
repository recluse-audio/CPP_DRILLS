cmake_minimum_required(VERSION 3.22)

project(WINDOW_TRIANGLE VERSION 1.0.0)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

add_subdirectory(../../../SUBMODULES/JUCE JUCE)

juce_add_gui_app(WindowTriangle
    PRODUCT_NAME "WindowTriangle"
    NEEDS_WEB_BROWSER FALSE
    NEEDS_CURL FALSE)

target_sources(WindowTriangle
    PRIVATE
        SOURCE/Main.cpp
        SOURCE/TriangleComponent.cpp
        SOURCE/TrianglePoints.cpp)

target_compile_definitions(WindowTriangle
    PRIVATE
        JUCE_WEB_BROWSER=0
        JUCE_USE_CURL=0
        JUCE_APPLICATION_NAME_STRING="$<TARGET_PROPERTY:WindowTriangle,JUCE_PRODUCT_NAME>"
        JUCE_APPLICATION_VERSION_STRING="$<TARGET_PROPERTY:WindowTriangle,JUCE_VERSION>")

target_link_libraries(WindowTriangle
    PRIVATE
        juce::juce_gui_basics
    PUBLIC
        juce::juce_recommended_config_flags
        juce::juce_recommended_warning_flags)
