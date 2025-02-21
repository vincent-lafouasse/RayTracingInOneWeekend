#include "Camera.hpp"

#include "Color.hpp"

void Camera::render(const Hittable& scene) const {
    (void)this;
    (void)scene;
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
