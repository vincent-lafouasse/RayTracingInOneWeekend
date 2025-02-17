#include <iostream>
#include "Color.hpp"

int main() {
    constexpr int size = 256;
    constexpr int width = size;
    constexpr int height = size;

    std::cout << "P3\n" << width << " " << height << "\n255\n";

    for (int col = 0; col < height; ++col) {
        std::clog << "Scanlines remaining: " << (height - col) << std::endl;
        for (int row = 0; row < width; ++row) {
            Color color(row, 0, col);
            color /= size - 1;

            writeColor(std::cout, color);
            std::cout << '\n';
        }
    }
}
