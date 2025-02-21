#pragma once

#include "Interval.hpp"
#include "Ray.hpp"

struct HitRecord {
    Point3 p;
    Vec3 normal;
    double t;

    HitRecord(const Point3& p, const Vec3& normal, double t)
        : p(p), normal(normal), t(t) {}
    static HitRecord None() { return {Vec3(0, 0, 0), Vec3(0, 0, 0), -1.0}; }
    explicit operator bool() const { return this->t >= 0; };
};

class Hittable {
   public:
    virtual ~Hittable() = default;
    virtual HitRecord hit(const Ray& ray, Interval range) const = 0;
};
