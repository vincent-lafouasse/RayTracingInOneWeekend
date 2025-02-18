#include <iostream>
#include "Color.hpp"
#include "Ray.hpp"

namespace Config {
constexpr double DISPLAY_ASPECT_RATIO = 16.0 / 9.0;
constexpr int DISPLAY_HEIGHT = 800;
};  // namespace Config

namespace Colors {
const Color WHITE(1.0, 1.0, 1.0);
const Color BLUE(0.0, 0.0, 1.0);
const Color LIGHT_BLUE(0.5, 0.7, 1.0);
const Color BLACK(0.0, 0.0, 0.0);
const Color RED(1.0, 0.0, 0.0);
};  // namespace Colors

struct Sphere {
    Point3 center;
    double radius;

    // returns the value of t in the equation Ray = origin + t * direction
    double is_hit(const Ray& r) const {
        const Vec3 oc = this->center - r.origin();
        const double a = Vec3::dot(r.direction(), r.direction());
        const double b = -2.0 * Vec3::dot(oc, r.direction());
        const double c = Vec3::dot(oc, oc) - this->radius * this->radius;
        const double discriminant = b * b - 4 * a * c;

        if (discriminant < 0) {
            return -1.0;
        } else {
            return (-b - std::sqrt(discriminant)) / (2.0 * a);
        }
    }
};

Color ray_color(const Ray& r, const Sphere& s) {
    const double t = s.is_hit(r);
    if (t > 0.0) {
        const Point3 intersection = r.at(t) - s.center;
        const Vec3 normal = intersection.normalized();
        // scale from [-1, 1] to [0, 1]
        return 0.5 * (normal + Vec3(1, 1, 1));
    }

    const Vec3 unit_direction = r.direction().normalized();

    // a == 0 when y == -1 -> white
    // a == 1 when y == 1  -> black
    const double a = 0.5 * (unit_direction.y() + 1.0);
    return (1.0 - a) * Colors::WHITE + a * Colors::LIGHT_BLUE;
}

int main() {
    constexpr int display_width =
        static_cast<int>(Config::DISPLAY_ASPECT_RATIO * Config::DISPLAY_HEIGHT);
    constexpr int display_height = Config::DISPLAY_HEIGHT;

    constexpr double effective_aspect_ratio =
        static_cast<double>(display_width) / display_height;

    constexpr double fov = 1.0;
    const Point3 camera(0.0, 0.0, 0.0);

    constexpr double viewport_height = 2.0;
    constexpr double viewport_width = viewport_height * effective_aspect_ratio;

    // notice the viewport is orthogonal to Oz
    const Vec3 viewport_u(viewport_width, 0, 0);
    const Vec3 viewport_v(0, -viewport_height, 0);

    const Vec3 pixel_delta_u = viewport_u / display_width;
    const Vec3 pixel_delta_v = viewport_v / display_height;

    const Point3 viewport_center = camera - Vec3(0, 0, fov);
    const Point3 viewport_top_left =
        viewport_center - viewport_u / 2 - viewport_v / 2;
    const Point3 pixel00 =
        viewport_top_left + 0.5 * (pixel_delta_u + pixel_delta_v);

    const Sphere sphere = {.center = Point3(0, 0, -1), .radius = 0.5};

    std::cout << "P3\n" << display_width << " " << display_height << "\n255\n";

    for (int row = 0; row < display_height; ++row) {
        std::clog << "Scanlines remaining: " << (display_height - row)
                  << std::endl;
        for (int col = 0; col < display_width; ++col) {
            Point3 pixel = pixel00 + col * pixel_delta_u + row * pixel_delta_v;
            Ray ray(camera, pixel - camera);
            Color color = ray_color(ray, sphere);

            writeColor(std::cout, color);
            std::cout << '\n';
        }
    }
}
