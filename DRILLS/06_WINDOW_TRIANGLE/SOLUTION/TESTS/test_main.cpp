// calculate_triangle_points() in SOURCE/TrianglePoints.cpp - called here with width / height of 400 by 300
// TriangleComponent::paint() in SOURCE/TriangleComponent.cpp - passes same call result to juce::Path
#include <catch_amalgamated.hpp>

#include "TrianglePoints.h"

TEST_CASE("calculate_triangle_points puts the top corner at half the width and 20 down")
{
    TrianglePoints points = calculate_triangle_points(400.0f, 300.0f);
    REQUIRE(points.top.x == 200.0f);
    REQUIRE(points.top.y == 20.0f);
}

TEST_CASE("calculate_triangle_points puts both bottom corners 20 from the bottom and 20 from each side")
{
    TrianglePoints points = calculate_triangle_points(400.0f, 300.0f);
    REQUIRE(points.bottom_left.x == 20.0f);
    REQUIRE(points.bottom_left.y == 280.0f);
    REQUIRE(points.bottom_right.x == 380.0f);
    REQUIRE(points.bottom_right.y == 280.0f);
}
