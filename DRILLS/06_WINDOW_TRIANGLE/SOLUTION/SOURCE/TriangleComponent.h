#pragma once

#include <juce_gui_basics/juce_gui_basics.h>

// Main.cpp passes new TriangleComponent to juce::DocumentWindow::setContentOwned()
class TriangleComponent final : public juce::Component
{
public:
    TriangleComponent();

    void paint(juce::Graphics& graphics) override;

private:
    JUCE_DECLARE_NON_COPYABLE_WITH_LEAK_DETECTOR(TriangleComponent)
};
