#pragma once

#include "common_math.h"

struct Interval final {
    Interval();
    Interval(double min, double max);

    double size() const;
    bool contains(double x) const;
    bool surrounds(double x) const;

    static const Interval empty;
    static const Interval R;
    static const Interval R_plus;

    double min, max;
};

const Interval empty(+infinity, -infinity);
const Interval R(-infinity, +infinity);
const Interval R_plus(0, +infinity);
