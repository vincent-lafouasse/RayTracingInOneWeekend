#include "common_math.h"

#include <random>

inline double random_double() {
    static std::random_device rd;
    static std::uniform_real_distribution<double> distribution(0.0, 1.0);
    static std::mt19937 generator(rd());
    return distribution(generator);
}

double random_double(const double min, const double max) {
    return min + (max - min) * random_double();
}
