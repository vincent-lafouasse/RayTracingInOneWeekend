#pragma once

#include "Ray.hpp"

struct HitRecord {
    Point3 p;
    Vec3 normal;
    double t;

    operator bool() const { return this->t >= 0; };
};

class Hittable {
   public:
    virtual ~Hittable() = default;
    virtual HitRecord hit(const Ray& ray, double t_min, double t_max) const = 0;
};
