#include "common_math.h"

#include <cstdlib>

double random_double() {
    return std::rand() / (RAND_MAX + 1.0);
}

double random_double(const double min, const double max) {
    return min + (max - min) * random_double();
}
