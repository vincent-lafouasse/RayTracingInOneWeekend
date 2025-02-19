#include "Scene.hpp"

void Scene::add(std::shared_ptr<Hittable> object) {
    this->objects.push_back(std::move(object));
}

void Scene::clear() {
    this->objects.clear();
}
