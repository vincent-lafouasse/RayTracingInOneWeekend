#pragma once

#include "Hittable.hpp"
#include "Vec3.hpp"

class Sphere final : public Hittable {
   public:
    Sphere(const Point3& center, double radius)
        : center(center), radius(radius) {}

    // returns the value of t in the equation Ray = origin + t * direction
    HitRecord hit(const Ray& r, double t_min, double t_max) const override {
        const Vec3 oc = this->center - r.origin();
        const double a = Vec3::dot(r.direction(), r.direction());
        const double h = Vec3::dot(r.direction(), oc);
        const double c = Vec3::dot(oc, oc) - radius * radius;
        const double discriminant = h * h - a * c;

        if (discriminant < 0) {
            return HitRecord::None();
        }

        const double sqrtDiscriminant = std::sqrt(discriminant);

        // try lowest root then highest root
        double root = (h - sqrtDiscriminant) / a;
        if (root <= t_min || root >= t_max) {
            root = (h + sqrtDiscriminant) / a;
            if (root <= t_min || root >= t_max) {
                return HitRecord::None();
            }
        }
        double t = root;
        Vec3 p = r.at(root);
        Vec3 normal = (p - this->center) / this->radius;
        return HitRecord(p, normal, t);
    }

    virtual ~Sphere() = default;

   private:
    Point3 center;
    double radius;
};
