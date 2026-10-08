#pragma once

struct TrianglePoint
{
    float x;
    float y;
};

struct TrianglePoints
{
    TrianglePoint top;
    TrianglePoint bottom_left;
    TrianglePoint bottom_right;
};

TrianglePoints calculate_triangle_points(float width, float height);
