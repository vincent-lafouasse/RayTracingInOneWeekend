#pragma once

#include "Color.hpp"
#include "Hittable.hpp"
#include "Vec3.hpp"

class Camera final {
   public:
    Camera(uint32_t width, double aspect_ratio);
    void render(const Hittable& scene) const;

   private:
    static Color ray_color(const Ray& r, const Hittable& scene);
    Ray get_ray(uint32_t row, uint32_t col) const;

    uint32_t width, height;
    Point3 eye;
    double fov;
    Point3 pixel00;
    Vec3 delta_u;
    Vec3 delta_v;
};