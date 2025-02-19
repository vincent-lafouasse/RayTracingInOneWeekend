#include "Scene.hpp"

HitRecord Scene::hit(const Ray& ray, double t_min, double t_max) const {
    HitRecord out = HitRecord::None();
    double closest = t_max;

    for (const std::shared_ptr<Hittable>& object : this->objects) {
        HitRecord rec = object->hit(ray, t_min, closest);
        if (rec) {
            closest = rec.t;
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
