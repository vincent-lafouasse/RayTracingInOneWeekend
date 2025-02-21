#pragma once

#include "Color.hpp"
#include "Hittable.hpp"

class Camera final {
   public:
    void render(const Hittable& scene) const;

   private:
    Color ray_color(const Ray& r, const Hittable& scene) const;
};