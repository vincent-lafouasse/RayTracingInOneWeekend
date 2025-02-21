#pragma once

#include "Hittable.hpp"

#include <memory>
#include <vector>

class Scene final : public Hittable {
   public:
    Scene() = default;
    ~Scene() override = default;

    void add(std::shared_ptr<Hittable> object);
    void clear();
    HitRecord hit(const Ray& ray, Interval range) const override;

   private:
    std::vector<std::shared_ptr<Hittable>> objects;
};