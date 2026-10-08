cmake_minimum_required(VERSION 3.22)

project(PLAY_WAVETABLE VERSION 1.0.0)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

add_subdirectory(../../../SUBMODULES/JUCE JUCE)

juce_add_console_app(PlayWavetable
    PRODUCT_NAME "PlayWavetable"
    NEEDS_WEB_BROWSER FALSE
    NEEDS_CURL FALSE)

target_sources(PlayWavetable
    PRIVATE
        SOURCE/PlayWavetable.cpp
        SOURCE/WavetableCallback.cpp
        SOURCE/Wavetable.cpp)

target_compile_definitions(PlayWavetable
    PRIVATE
        JUCE_WEB_BROWSER=0
        JUCE_USE_CURL=0)

target_link_libraries(PlayWavetable
    PRIVATE
        juce::juce_audio_devices
    PUBLIC
        juce::juce_recommended_config_flags
        juce::juce_recommended_warning_flags)
