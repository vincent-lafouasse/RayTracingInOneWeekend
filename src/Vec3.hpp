#pragma once

struct Vec3 {
    Vec3();
    Vec3(double x, double y, double z);
    Vec3(const Vec3& v);
    Vec3& operator=(const Vec3& v);

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

    double x;
    double y;
    double z;
};
