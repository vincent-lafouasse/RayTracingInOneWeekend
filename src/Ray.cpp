#include "Ray.hpp"

Ray::Ray(const Vec3& origin, const Vec3& direction)
    : __origin(origin), __direction(direction) {}

Ray& Ray::operator=(const Ray& r) {
    if (this == &r)
        return *this;

    if (r.direction().magnitude() == 0.0) {
        throw NullDirectionException();
    }

    this->__origin = r.__origin;
    this->__direction = r.__direction;
    return *this;
}

Point3 Ray::origin() const {
    return this->__origin;
}

Vec3 Ray::direction() const {
    return this->__direction;
}

Point3 Ray::at(const double t) const {
    return origin() + t * direction();
}
