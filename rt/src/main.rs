#![allow(unused)]

mod ray;
mod vec3;

use crate::ray::Ray;
use crate::vec3::Color;
use crate::vec3::Point3;
use crate::vec3::Vec3;

use cgmath::InnerSpace;

const TARGET_ASPECT_RATIO: f64 = 16.0 / 9.0;
const TARGET_HEIGHT: u32 = 600;

const WHITE: Color = Color::new(1.0, 1.0, 1.0);
const RED: Color = Color::new(1.0, 0.0, 0.0);
const LIGHT_BLUE: Color = Color::new(0.5, 0.7, 1.0);

fn ray_color(ray: &Ray) -> Color {
    if (hit_sphere(Point3::new(0.0, 0.0, -1.0), 0.5, &ray)) {
        return RED;
    }

    let unit_direction = ray.direction.normalize();
    let a: f64 = 0.5 * (unit_direction.y + 1.0);

    (1.0 - a) * WHITE + a * LIGHT_BLUE
}

fn hit_sphere(center: Point3, radius: f64, ray: &Ray) -> bool {
    let oc = center - ray.origin;
    let a = ray.direction.dot(ray.direction);
    let b = -2.0 * ray.direction.dot(oc);
    let c = oc.dot(oc) - radius * radius;
    let discriminant = b * b - 4.0 * a * c;

    (discriminant >= 0.0)
}

fn main() {
    let display_height: u32 = TARGET_HEIGHT;
    let display_width: u32 = (TARGET_HEIGHT as f64 * TARGET_ASPECT_RATIO) as u32;
    write_ppm_header(display_width, display_height);

    let viewport_height: f64 = 2.0; // arbitrary
    let viewport_width: f64 = viewport_height * display_width as f64 / display_height as f64;

    let camera = Point3::new(0.0, 0.0, 0.0);
    let fov: f64 = 1.0;

    let viewport_center = camera + Point3::new(0.0, 0.0, -fov);
    let viewport_u = Vec3::new(viewport_width, 0.0, 0.0);
    let viewport_v = Vec3::new(0.0, -viewport_height, 0.0);

    let pixel_delta_u = viewport_u / display_width as f64;
    let pixel_delta_v = viewport_v / display_height as f64;

    let viewport_top_left = viewport_center - 0.5 * (viewport_u + viewport_v);
    let pixel00 = viewport_top_left + 0.5 * (pixel_delta_u + pixel_delta_v);

    for row in 0..display_height {
        log_progress(row as f32 / (display_height as f32 - 1.0));
        for col in 0..display_width {
            let pixel = pixel00 + col as f64 * pixel_delta_u + row as f64 * pixel_delta_v;
            let ray = Ray::new(camera, pixel - camera);

            let color = ray_color(&ray);
            write_color(&color);
        }
    }
}

fn write_ppm_header(width: u32, height: u32) {
    println!("P3");
    println!("{width} {height}");
    println!("255");
}

fn write_color(color: &Color) {
    let r_byte: u8 = (255.999 * color[0]) as u8;
    let g_byte: u8 = (255.999 * color[1]) as u8;
    let b_byte: u8 = (255.999 * color[2]) as u8;

    println!("{r_byte} {g_byte} {b_byte}");
}

fn log_progress(advancement: f32) {
    let bar_len = 30;
    let increment = 1.0 / bar_len as f32;
    let advancement: usize = (advancement / increment) as usize;

    eprintln!(
        "[{}{}]",
        "*".repeat(advancement),
        " ".repeat(bar_len - advancement - 1)
    );
}
