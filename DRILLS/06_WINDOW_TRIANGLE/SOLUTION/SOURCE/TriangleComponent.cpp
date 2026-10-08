#include "TriangleComponent.h"

#include "TrianglePoints.h"

TriangleComponent::TriangleComponent()
{
    setSize(400, 300);
}

void TriangleComponent::paint(juce::Graphics& graphics)
{
    graphics.fillAll(juce::Colours::black);

    float width = static_cast<float>(getWidth());
    float height = static_cast<float>(getHeight());
    TrianglePoints points = calculate_triangle_points(width, height);

    juce::Path triangle;
    triangle.startNewSubPath(points.top.x, points.top.y);
    triangle.lineTo(points.bottom_left.x, points.bottom_left.y);
    triangle.lineTo(points.bottom_right.x, points.bottom_right.y);
    triangle.closeSubPath();

    graphics.setColour(juce::Colours::white);
    graphics.fillPath(triangle);
}
