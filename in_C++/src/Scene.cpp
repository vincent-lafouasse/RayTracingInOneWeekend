#include "Scene.hpp"

HitRecord Scene::hit(const Ray& ray, Interval range) const {
    HitRecord out = HitRecord::None();

    for (const std::shared_ptr<Hittable>& object : this->objects) {
        HitRecord rec = object->hit(ray, range);
        if (rec) {
            range.max = rec.t;
            out = rec;
        }
    }

    return out;
}

void Scene::add(std::shared_ptr<Hittable> object) {
    this->objects.push_back(std::move(object));
}

void Scene::clear() {
    this->objects.clear();
}
