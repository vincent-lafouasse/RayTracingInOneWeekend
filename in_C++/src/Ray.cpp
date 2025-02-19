#include "Ray.hpp"

Ray::Ray(const Vec3& origin, const Vec3& direction)
    : m_origin(origin), m_direction(direction) {}

Ray& Ray::operator=(const Ray& r) {
    if (this == &r)
        return *this;

    if (r.direction().magnitude() == 0.0) {
        throw NullDirectionException();
    }

    this->m_origin = r.m_origin;
    this->m_direction = r.m_direction;
    return *this;
}

Point3 Ray::origin() const {
    return this->m_origin;
}

Vec3 Ray::direction() const {
    return this->m_direction;
}

Point3 Ray::at(const double t) const {
    return this->origin() + t * this->direction();
}
