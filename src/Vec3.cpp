#include "Vec3.hpp"

#include <cmath>

Vec3::Vec3(const double x, const double y, const double z)
    : __x(x), __y(y), __z(z) {}

// TODO: complete rule of 5

double Vec3::x() const {
    return __x;
}
double Vec3::y() const {
    return __y;
}
double Vec3::z() const {
    return __z;
}
double& Vec3::x() {
    return this->__x;
};
double& Vec3::y() {
    return this->__y;
};
double& Vec3::z() {
    return this->__z;
};

double Vec3::r() const {
    return this->x();
}
double Vec3::g() const {
    return this->y();
}
double Vec3::b() const {
    return this->z();
}
double& Vec3::r() {
    return this->x();
};
double& Vec3::g() {
    return this->y();
};
double& Vec3::b() {
    return this->z();
};

double Vec3::operator[](const std::size_t i) const {
    switch (i) {
        case 0:
            return this->x();
        case 1:
            return this->y();
        case 2:
            return this->z();
        default:
            throw Vec3::OutOfBoundsException();
    }
}

double& Vec3::operator[](const std::size_t i) {
    switch (i) {
        case 0:
            return this->x();
        case 1:
            return this->y();
        case 2:
            return this->z();
        default:
            throw Vec3::OutOfBoundsException();
    }
}

Vec3 Vec3::operator+(const Vec3& v) const {
    return Vec3(__x + v.__x, __y + v.__y, __z + v.__z);
}

Vec3 Vec3::operator-(const Vec3& v) const {
    return *this + -v;
}

Vec3 Vec3::operator-() const {
    return Vec3(-__x, -__y, -__z);
}

Vec3 Vec3::operator*(const double s) const {
    return Vec3(__x * s, __y * s, __z * s);
}

Vec3 Vec3::operator/(const double s) const {
    if (s == 0.0) {
        throw Vec3::OutOfBoundsException();
    }
    return *this * (1 / s);
}

Vec3 operator*(const double s, const Vec3& v) {
    return v * s;
}

Vec3 operator/(const double s, const Vec3& v) {
    return v / s;
}

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

Vec3& Vec3::operator*=(const double s) {
    this->__x *= s;
    this->__y *= s;
    this->__z *= s;
    return *this;
}

Vec3& Vec3::operator/=(const double s) {
    if (s == 0.0) {
        throw Vec3::DivisionByZeroException();
    }

    this->__x /= s;
    this->__y /= s;
    this->__z /= s;
    return *this;
}

Vec3& Vec3::operator+=(const double s) {
    this->__x += s;
    this->__y += s;
    this->__z += s;
    return *this;
}

Vec3& Vec3::operator-=(const double s) {
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

double Vec3::dot(const Vec3& v1, const Vec3& v2) {
    return v1.dot(v2);
}

Vec3 Vec3::cross(const Vec3& v) const {
    return Vec3(this->y() * v.z() - this->z() * v.y(),
                this->z() * v.x() - this->x() * v.z(),
                this->x() * v.y() - this->y() * v.x());
}

Vec3 Vec3::cross(const Vec3& v1, const Vec3& v2) {
    return v1.cross(v2);
}

Vec3& Vec3::normalize() {
    if (this->magnitude() == 0.0) {
        throw Vec3::DivisionByZeroException();
    }
    *this /= this->magnitude();
    return *this;
}

Vec3 Vec3::normalized() const {
    if (this->magnitude() == 0.0) {
        throw Vec3::DivisionByZeroException();
    }
    return *this / this->magnitude();
}

// uses float comparison, bad ?
bool Vec3::operator==(const Vec3& v) const {
    return __x == v.__x && __y == v.__y && __z == v.__z;
}

bool Vec3::operator!=(const Vec3& v) const {
    return !(*this == v);
}

std::ostream& operator<<(std::ostream& os, const Vec3& v) {
    os << "(" << v.x() << "," << v.y() << "," << v.z() << ")";
    return os;
}
