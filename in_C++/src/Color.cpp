#include "Color.hpp"

namespace {
uint8_t clamp(uint16_t color) {
    if (color > 255) {
        return 255;
    }

    return color;
}
}  // namespace

void writeColor(std::ostream& os, const Color& color) {
    const uint8_t red = clamp(256.0 * color.r());
    const uint8_t green = clamp(256.0 * color.g());
    const uint8_t blue = clamp(256.0 * color.b());

    os << +red << " " << +green << " " << +blue;
}
