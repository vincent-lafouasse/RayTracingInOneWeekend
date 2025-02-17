#include <iostream>
#include "Color.hpp"

namespace Config {
constexpr int SIZE = 256;
};

int main() {
    constexpr int width = Config::SIZE;
    constexpr int height = Config::SIZE;

    std::cout << "P3\n" << width << " " << height << "\n255\n";

    for (int row = 0; row < height; ++row) {
        std::clog << "Scanlines remaining: " << (height - row) << std::endl;
        for (int col = 0; col < width; ++col) {
            const double red =
                static_cast<double>(row) / static_cast<double>(height - 1);
            const double blue =
                static_cast<double>(col) / static_cast<double>(width - 1);
            Color color(red, 0.0, blue);

            writeColor(std::cout, color);
            std::cout << '\n';
        }
    }
}
