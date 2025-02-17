#include <iostream>
#include "Color.hpp"

int main() {
    constexpr int size = 256;
    constexpr int width = size;
    constexpr int height = size;

    std::cout << "P3\n" << width << " " << height << "\n255\n";

    for (int y = 0; y < height; ++y) {
        std::clog << "Scanlines remaining: " << (height - y) << std::endl;
        for (int x = 0; x < width; ++x) {
            Color color(x, 0, y);
            color /= size;

            writeColor(std::cout, color);
            std::cout << '\n';
        }
    }
}
