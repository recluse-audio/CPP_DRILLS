#include <juce_gui_basics/juce_gui_basics.h>

#include "TriangleComponent.h"

class TriangleWindow final : public juce::DocumentWindow
{
public:
    explicit TriangleWindow(juce::String name)
        : DocumentWindow(name, juce::Colours::black, allButtons)
    {
        setUsingNativeTitleBar(true);

        TriangleComponent* content = new TriangleComponent();
        setContentOwned(content, true);

        int width = getWidth();
        int height = getHeight();
        centreWithSize(width, height);
        setVisible(true);
    }

    void closeButtonPressed() override
    {
        juce::JUCEApplication* application = juce::JUCEApplication::getInstance();
        application->systemRequestedQuit();
    }

private:
    JUCE_DECLARE_NON_COPYABLE_WITH_LEAK_DETECTOR(TriangleWindow)
};

class WindowTriangleApplication final : public juce::JUCEApplication
{
public:
    WindowTriangleApplication()
    {
    }

    const juce::String getApplicationName() override
    {
        return JUCE_APPLICATION_NAME_STRING;
    }

    const juce::String getApplicationVersion() override
    {
        return JUCE_APPLICATION_VERSION_STRING;
    }

    void initialise(const juce::String& command_line) override
    {
        juce::ignoreUnused(command_line);

        juce::String name = getApplicationName();
        TriangleWindow* window = new TriangleWindow(name);
        main_window.reset(window);
    }

    void shutdown() override
    {
        main_window = nullptr;
    }

    void systemRequestedQuit() override
    {
        quit();
    }

private:
    std::unique_ptr<TriangleWindow> main_window;
};

START_JUCE_APPLICATION(WindowTriangleApplication)
