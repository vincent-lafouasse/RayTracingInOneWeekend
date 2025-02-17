#include "Vec3.hpp"

#include <cmath>

Vec3::Vec3(double x, double y, double z) : x(x), y(y), z(z) {}

// TODO: complete rule of 5

Vec3& Vec3::operator+=(const Vec3& v) {
    this->x += v.x;
    this->y += v.y;
    this->z += v.z;
    return *this;
}

Vec3& Vec3::operator-=(const Vec3& v) {
    this->x -= v.x;
    this->y -= v.y;
    this->z -= v.z;
    return *this;
}

Vec3& Vec3::operator*=(double s) {
    this->x *= s;
    this->y *= s;
    this->z *= s;
    return *this;
}

Vec3& Vec3::operator/=(double s) {
    this->x /= s;
    this->y /= s;
    this->z /= s;
    return *this;
}

Vec3& Vec3::operator+=(double s) {
    this->x += s;
    this->y += s;
    this->z += s;
    return *this;
}

Vec3& Vec3::operator-=(double s) {
    this->x -= s;
    this->y -= s;
    this->z -= s;
    return *this;
}

double Vec3::magnitude() const {
    return std::sqrt(this->x * this->x + this->y * this->y + this->z * this->z);
}

double Vec3::dot(const Vec3& v) const {
    return this->x * v.x + this->y * v.y + this->z * v.z;
}

Vec3& Vec3::normalize() {
    *this /= this->magnitude();
    return *this;
}
