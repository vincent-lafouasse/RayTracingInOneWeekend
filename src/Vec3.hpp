#pragma once
#include <ostream>

struct Vec3 {
    Vec3() = default;
    Vec3(double x, double y, double z);
    Vec3(const Vec3& v) = default;
    Vec3& operator=(const Vec3& v) = default;
    ~Vec3() = default;

    Vec3 operator+(const Vec3& v) const;
    Vec3 operator-(const Vec3& v) const;
    Vec3 operator-() const;

    Vec3& operator+=(const Vec3& v);
    Vec3& operator-=(const Vec3& v);

    Vec3& operator*=(double s);
    Vec3& operator/=(double s);
    Vec3& operator+=(double s);
    Vec3& operator-=(double s);

    double magnitude() const;
    double dot(const Vec3& v) const;
    Vec3 cross(const Vec3& v) const;
    Vec3& normalize();

    double x() const;
    double y() const;
    double z() const;
    double& x();
    double& y();
    double& z();
    double r() const;
    double g() const;
    double b() const;
    double& r();
    double& g();
    double& b();

    double operator[](std::size_t i) const;
    double& operator[](std::size_t i);

    bool operator==(const Vec3& v) const;
    bool operator!=(const Vec3& v) const;

    friend std::ostream& operator<<(std::ostream& os, const Vec3& v);

    class DivisionByZeroException : public std::runtime_error {
       public:
        DivisionByZeroException(const char* what) : runtime_error(what) {};
        DivisionByZeroException()
            : DivisionByZeroException("Division by zero") {};
    };
    class OutOfBoundsException : public std::runtime_error {
       public:
        OutOfBoundsException(const char* what) : runtime_error(what) {};
        OutOfBoundsException() : OutOfBoundsException("Out of bounds") {};
    };

   private:
    double __x;
    double __y;
    double __z;
};

using Point3 = Vec3;
using Color = Vec3;
