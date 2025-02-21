#include "Camera.hpp"

#include <iostream>
#include "Color.hpp"

Camera::Camera(const uint32_t width, const double aspect_ratio)
    : width(width),
      height(static_cast<uint32_t>(width / aspect_ratio)),
      eye(Point3(0, 0, 0)),
      fov(1.0) {
    const double effective_aspect_ratio = width / static_cast<double>(height);
    constexpr double viewport_height = 2.0;
    const double viewport_width = viewport_height * effective_aspect_ratio;

    // notice the viewport is orthogonal to Oz
    const Vec3 viewport_u(viewport_width, 0, 0);
    const Vec3 viewport_v(0, -viewport_height, 0);

    this->delta_u = viewport_u / this->width;
    this->delta_v = viewport_v / this->height;

    // notice we look along the negative z-axis
    const Point3 viewport_center = this->eye + Vec3(0, 0, -this->fov);
    const Point3 viewport_top_left =
        viewport_center - viewport_u / 2 - viewport_v / 2;
    this->pixel00 = viewport_top_left + 0.5 * (this->delta_u + this->delta_v);
}

void Camera::render(const Hittable& scene) const {
    std::cout << "P3\n" << this->width << " " << this->height << "\n255\n";

    for (uint32_t row = 0; row < this->height; ++row) {
        std::clog << "Scanlines remaining: " << (this->height - row)
                  << std::endl;
        for (uint32_t col = 0; col < this->width; ++col) {
            Point3 pixel = pixel00 + col * this->delta_u + row * this->delta_v;
            Ray ray(this->eye, pixel - this->eye);
            Color color = Camera::ray_color(ray, scene);

            writeColor(std::cout, color);
            std::cout << '\n';
        }
    }
}

Color Camera::ray_color(const Ray& r, const Hittable& scene) {
    const HitRecord rec = scene.hit(r, Interval::R_plus());
    if (rec) {
        // scale from [-1, 1] to [0, 1]
        return 0.5 * (rec.normal + Vec3(1, 1, 1));
    }

    const Vec3 unit_direction = r.direction().normalized();
    // a == 0 when y == -1 -> white
    // a == 1 when y == 1  -> black
    const double a = 0.5 * (unit_direction.y() + 1.0);
    return (1.0 - a) * Colors::WHITE + a * Colors::LIGHT_BLUE;
}
