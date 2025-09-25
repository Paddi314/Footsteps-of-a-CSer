// utils.h

#pragma once

#include "Point.h"
#include <cmath>

// Helper function to calculate distance between two points
inline double distance(const Point& p1, const Point& p2) {
    double dx = p1.get_x() - p2.get_x();
    double dy = p1.get_y() - p2.get_y();
    return sqrt(dx * dx + dy * dy);
}
