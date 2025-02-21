#include <iostream>
#include "Camera.hpp"
#include "Scene.hpp"
#include "Sphere.hpp"

namespace Config {
constexpr double DISPLAY_ASPECT_RATIO = 16.0 / 9.0;
constexpr uint32_t DISPLAY_WIDTH = 600;
};  // namespace Config

int main() {
    const Camera camera(Config::DISPLAY_WIDTH, Config::DISPLAY_ASPECT_RATIO);

    std::shared_ptr<Hittable> sphere =
        std::make_shared<Sphere>(Point3(0, 0, -1), 0.5);
    std::shared_ptr<Hittable> grass =
        std::make_shared<Sphere>(Point3(0, -100.5, -1), 100);

    Scene scene;
    scene.add(std::move(sphere));
    scene.add(std::move(grass));
    scene.add(std::make_shared<Sphere>(Point3(-1, 0, -1), 0.5));
    scene.add(std::make_shared<Sphere>(Point3(1, 0, -1), 0.5));

    camera.render(scene);
}
