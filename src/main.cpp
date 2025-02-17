#include <iostream>

int main() {
    constexpr int size = 256;
    constexpr int width = size;
    constexpr int height = size;

    std::cout << "P3\n" << width << " " << height << "\n255\n";

    for (int y = 0; y < height; ++y) {
        std::clog << "Scanlines remaining: " << (height - y) << std::endl;
        for (int x = 0; x < width; ++x) {
            double r = static_cast<double>(x) / static_cast<double>(width - 1);
            double g = static_cast<double>(y) / static_cast<double>(width - 1);
            double b = 0.0;

            int int_r = static_cast<int>(r * 255.9999);
            int int_g = static_cast<int>(g * 255.9999);
            int int_b = static_cast<int>(b * 255.9999);

            std::cout << int_r << " " << int_g << " " << int_b << "\n";
        }
    }
}
