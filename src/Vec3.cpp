#include "Vec3.hpp"

#include <cmath>

Vec3::Vec3(double x, double y, double z) : __x(x), __y(y), __z(z) {}

// TODO: complete rule of 5

Vec3& Vec3::operator+=(const Vec3& v) {
    this->__x += v.__x;
    this->__y += v.__y;
    this->__z += v.__z;
    return *this;
}

Vec3& Vec3::operator-=(const Vec3& v) {
    this->__x -= v.__x;
    this->__y -= v.__y;
    this->__z -= v.__z;
    return *this;
}

Vec3& Vec3::operator*=(double s) {
    this->__x *= s;
    this->__y *= s;
    this->__z *= s;
    return *this;
}

Vec3& Vec3::operator/=(double s) {
    this->__x /= s;
    this->__y /= s;
    this->__z /= s;
    return *this;
}

Vec3& Vec3::operator+=(double s) {
    this->__x += s;
    this->__y += s;
    this->__z += s;
    return *this;
}

Vec3& Vec3::operator-=(double s) {
    this->__x -= s;
    this->__y -= s;
    this->__z -= s;
    return *this;
}

double Vec3::magnitude() const {
    return std::sqrt(this->__x * this->__x + this->__y * this->__y +
                     this->__z * this->__z);
}

double Vec3::dot(const Vec3& v) const {
    return this->__x * v.__x + this->__y * v.__y + this->__z * v.__z;
}

Vec3& Vec3::normalize() {
    *this /= this->magnitude();
    return *this;
}
