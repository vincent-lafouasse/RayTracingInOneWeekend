#include "Color.hpp"

void writeColor(std::ostream& os, const Color& color) {
    const int int_r = static_cast<int>(color.r() * 255.9999);
    const int int_g = static_cast<int>(color.g() * 255.9999);
    const int int_b = static_cast<int>(color.b() * 255.9999);

    os << int_r << " " << int_g << " " << int_b;
}
