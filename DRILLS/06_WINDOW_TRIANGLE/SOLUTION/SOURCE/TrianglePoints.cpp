#include "TrianglePoints.h"

TrianglePoints calculate_triangle_points(float width, float height)
{
    float margin = 20.0f;
    TrianglePoints points;

    points.top.x = width / 2.0f;
    points.top.y = margin;

    points.bottom_left.x = margin;
    points.bottom_left.y = height - margin;

    points.bottom_right.x = width - margin;
    points.bottom_right.y = height - margin;

    return points;
}
