#pragma once

#include "Ray.hpp"

struct HitRecord {
    Point3 p;
    Vec3 normal;
    double t;
};

class Hittable {
   public:
    virtual ~Hittable() = default;
    virtual bool hit(const Ray& ray,
                     double t_min,
                     double t_max,
                     HitRecord& rec) const = 0;
};