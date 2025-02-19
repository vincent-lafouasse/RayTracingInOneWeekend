#pragma once

#include "Hittable.hpp"
#include "Vec3.hpp"

class Sphere final : public Hittable {
   public:
    Sphere(const Point3& center, double radius);
    ~Sphere() override = default;

    HitRecord hit(const Ray& r, double t_min, double t_max) const override;

   private:
    Point3 center;
    double radius;
};
