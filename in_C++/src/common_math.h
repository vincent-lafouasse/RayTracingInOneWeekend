#pragma once

#include <cmath>
#include <limits>

constexpr double infinity = std::numeric_limits<double>::infinity();
constexpr double pi = 3.14159265358979323846;

inline double degrees_to_radians(double degrees) {
    return degrees * pi / 180.0;
}

double random_double();
double random_double(double min, double max);
