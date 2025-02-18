#![allow(unused)]

mod ray;
mod vec3;

use crate::vec3::Color;

const TARGET_ASPECT_RATIO: f64 = 16.0 / 9.0;
const TARGET_HEIGHT: u32 = 600;

fn main() {
    let display_height: u32 = TARGET_HEIGHT;
    let display_width: u32 = (TARGET_HEIGHT as f64 * TARGET_ASPECT_RATIO) as u32;
    write_ppm_header(display_width, display_height);

    for row in 0..display_height {
        log_progress(row as f32 / (display_height as f32 - 1.0));
        for col in 0..display_width {
            let red: f64 = row as f64 / (display_width as f64 - 1.0);
            let green: f64 = 0.0;
            let blue: f64 = col as f64 / (display_height as f64 - 1.0);

            let color = Color::new(red, green, blue);
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
