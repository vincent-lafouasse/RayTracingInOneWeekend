#pragma once

#include "Vec3.hpp"

class Ray final {
   public:
    Ray() = default;
    Ray(const Vec3& origin, const Vec3& direction);
    Ray& operator=(const Ray&);
    Ray(const Ray&) = default;
    ~Ray() = default;

    Point3 origin() const;
    Vec3 direction() const;
    Point3 at(double t) const;

    class NullDirectionException final : public std::runtime_error {
       public:
        explicit NullDirectionException(const char* what)
            : runtime_error(what) {};
        NullDirectionException()
            : NullDirectionException("Direction vector is null") {};
    };

   private:
    Point3 __origin;
    Vec3 __direction;
};