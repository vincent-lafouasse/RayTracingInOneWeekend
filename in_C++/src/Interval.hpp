#pragma once

#include "common_math.h"

struct Interval final {
    Interval();
    Interval(double min, double max);

    double size() const;
    bool contains(double x) const;
    bool surrounds(double x) const;
    double clamp(double x) const;

    static Interval empty() { return {+infinity, -infinity}; }
    static Interval R() { return {-infinity, +infinity}; }
    static Interval R_plus() { return {0, +infinity}; }

    double min, max;
};
