#include "Vec3.hpp"

#include <cmath>

Vec3::Vec3(const double x, const double y, const double z)
    : x_coordinate(x), y_coordinate(y), z_coordinate(z) {}

// TODO: complete rule of 5

double Vec3::x() const {
    return this->x_coordinate;
}
double Vec3::y() const {
    return this->y_coordinate;
}
double Vec3::z() const {
    return this->z_coordinate;
}
double& Vec3::x() {
    return this->x_coordinate;
};
double& Vec3::y() {
    return this->y_coordinate;
};
double& Vec3::z() {
    return this->z_coordinate;
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
    return {this->x() + v.x(), this->y() + v.y(), this->z() + v.z()};
}

Vec3 Vec3::operator-(const Vec3& v) const {
    return *this + -v;
}

Vec3 Vec3::operator-() const {
    return {-this->x(), -this->y(), -this->z()};
}

Vec3 Vec3::operator*(const double s) const {
    return {this->x() * s, this->y() * s, this->z() * s};
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
    this->x() += v.x();
    this->y() += v.y();
    this->z() += v.z();
    return *this;
}

Vec3& Vec3::operator-=(const Vec3& v) {
    this->x() -= v.x();
    this->y() -= v.y();
    this->z() -= v.z();
    return *this;
}

Vec3& Vec3::operator*=(const double s) {
    this->x() *= s;
    this->y() *= s;
    this->z() *= s;
    return *this;
}

Vec3& Vec3::operator/=(const double s) {
    if (s == 0.0) {
        throw Vec3::DivisionByZeroException();
    }

    this->x() /= s;
    this->y() /= s;
    this->z() /= s;
    return *this;
}

Vec3& Vec3::operator+=(const double s) {
    this->x() += s;
    this->y() += s;
    this->z() += s;
    return *this;
}

Vec3& Vec3::operator-=(const double s) {
    this->x() -= s;
    this->y() -= s;
    this->z() -= s;
    return *this;
}

double Vec3::magnitude() const {
    return std::sqrt(this->dot(*this));
}

double Vec3::dot(const Vec3& v) const {
    return this->x() * v.x() + this->y() * v.y() + this->z() * v.z();
}

double Vec3::dot(const Vec3& v1, const Vec3& v2) {
    return v1.dot(v2);
}

Vec3 Vec3::cross(const Vec3& v) const {
    return {this->y() * v.z() - this->z() * v.y(),
            this->z() * v.x() - this->x() * v.z(),
            this->x() * v.y() - this->y() * v.x()};
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
    return this->x() == v.x() && this->y() == v.y() && this->z() == v.z();
}

bool Vec3::operator!=(const Vec3& v) const {
    return !(*this == v);
}

std::ostream& operator<<(std::ostream& os, const Vec3& v) {
    os << "(" << v.x() << "," << v.y() << "," << v.z() << ")";
    return os;
}
