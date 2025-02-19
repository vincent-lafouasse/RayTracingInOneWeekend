#include "Sphere.hpp"

Sphere::Sphere(const Point3& center, const double radius)
    : center(center), radius(radius) {}

HitRecord Sphere::hit(const Ray& r,
                      const double t_min,
                      const double t_max) const {
    const Vec3 oc = this->center - r.origin();
    const double a = Vec3::dot(r.direction(), r.direction());
    const double h = Vec3::dot(r.direction(), oc);
    const double c = Vec3::dot(oc, oc) - radius * radius;
    const double discriminant = h * h - a * c;

    if (discriminant < 0) {
        return HitRecord::None();
    }

    const double sqrtDiscriminant = std::sqrt(discriminant);

    // try the lowest root then highest root
    double root = (h - sqrtDiscriminant) / a;
    if (root <= t_min || root >= t_max) {
        root = (h + sqrtDiscriminant) / a;
        if (root <= t_min || root >= t_max) {
            return HitRecord::None();
        }
    }
    const double t = root;
    const Vec3 p = r.at(root);
    const Vec3 normal = (p - this->center) / this->radius;
    return {p, normal, t};
}
