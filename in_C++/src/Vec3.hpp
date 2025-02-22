#pragma once
#include <ostream>

struct Vec3 final {
    Vec3() = default;
    Vec3(double x, double y, double z);
    Vec3(const Vec3& v) = default;
    Vec3& operator=(const Vec3& v) = default;
    ~Vec3() = default;

    Vec3 operator+(const Vec3& v) const;
    Vec3 operator-(const Vec3& v) const;
    Vec3 operator-() const;

    Vec3 operator*(double s) const;
    Vec3 operator/(double s) const;

    Vec3& operator+=(const Vec3& v);
    Vec3& operator-=(const Vec3& v);

    Vec3& operator*=(double s);
    Vec3& operator/=(double s);
    Vec3& operator+=(double s);
    Vec3& operator-=(double s);

    double magnitude() const;
    double dot(const Vec3& v) const;
    static double dot(const Vec3& v1, const Vec3& v2);
    Vec3 cross(const Vec3& v) const;
    static Vec3 cross(const Vec3& v1, const Vec3& v2);
    Vec3& normalize();
    Vec3 normalized() const;

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

    class DivisionByZeroException final : public std::runtime_error {
       public:
        explicit DivisionByZeroException(const char* what)
            : runtime_error(what) {};
        DivisionByZeroException()
            : DivisionByZeroException("Division by zero") {};
    };
    class OutOfBoundsException final : public std::runtime_error {
       public:
        explicit OutOfBoundsException(const char* what)
            : runtime_error(what) {};
        OutOfBoundsException() : OutOfBoundsException("Out of bounds") {};
    };

   private:
    double x_coordinate;
    double y_coordinate;
    double z_coordinate;
};

using Point3 = Vec3;

Vec3 operator*(double s, const Vec3& v);
Vec3 operator/(double s, const Vec3& v);
