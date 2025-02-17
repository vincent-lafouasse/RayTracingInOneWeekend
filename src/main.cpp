#include <iostream>
#include "Color.hpp"

namespace Config {
constexpr double DISPLAY_ASPECT_RATIO = 16.0 / 9.0;
constexpr int DISPLAY_HEIGHT = 800;
};  // namespace Config

int main() {
    constexpr int display_width =
        static_cast<int>(Config::DISPLAY_ASPECT_RATIO * Config::DISPLAY_HEIGHT);
    constexpr int display_height = Config::DISPLAY_HEIGHT;

    std::cout << "P3\n" << display_width << " " << display_height << "\n255\n";

    for (int row = 0; row < display_height; ++row) {
        std::clog << "Scanlines remaining: " << (display_height - row)
                  << std::endl;
        for (int col = 0; col < display_width; ++col) {
            const double red = static_cast<double>(row) / (display_height - 1);
            const double blue = static_cast<double>(col) / (display_width - 1);
            Color color(red, 0.0, blue);

            writeColor(std::cout, color);
            std::cout << '\n';
        }
    }
}
