#include "Interval.hpp"

// an empty interval
Interval::Interval() : min(+infinity), max(-infinity) {}

Interval::Interval(double min, double max) : min(min), max(max) {}

double Interval::size() const {
    return max - min;
}

bool Interval::contains(double x) const {
    return min <= x && x <= max;
}

bool Interval::surrounds(double x) const {
    return min < x && x < max;
}

double Interval::clamp(double x) const {
    if (x > this->max) {
        return this->max;
    }
    if (x < this->min) {
        return this->min;
    }
    return x;
}
