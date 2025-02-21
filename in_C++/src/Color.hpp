#pragma once

#include "Vec3.hpp"

using Color = Vec3;

void writeColor(std::ostream& os, const Color& color);

namespace Colors {
const Color WHITE(1.0, 1.0, 1.0);
const Color BLUE(0.0, 0.0, 1.0);
const Color LIGHT_BLUE(0.5, 0.7, 1.0);
const Color BLACK(0.0, 0.0, 0.0);
const Color RED(1.0, 0.0, 0.0);
};  // namespace Colors
