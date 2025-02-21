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

    uint32_t width, height;
    Point3 eye;
    double fov;
    Point3 pixel00;
    Vec3 delta_u;
    Vec3 delta_v;
};