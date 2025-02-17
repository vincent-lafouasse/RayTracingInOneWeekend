#pragma once

#include "Vec3.hpp"

class Ray {
   public:
    Ray() = default;
    Ray(const Vec3& origin, const Vec3& direction);
    Ray& operator=(const Ray&);
    Ray(const Ray&) = default;
    ~Ray() = default;

    Point3 origin() const;
    Vec3 direction() const;

    class NullDirectionException : public std::runtime_error {
       public:
        NullDirectionException(const char* what) : runtime_error(what) {};
        NullDirectionException()
            : NullDirectionException("Direction vector is null") {};
    };

   private:
    Point3 __origin;
    Vec3 __direction;
};