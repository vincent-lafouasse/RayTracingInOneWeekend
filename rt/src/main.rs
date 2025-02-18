#![allow(unused)]

mod vec3;

use crate::vec3::Color;

const DISPLAY_WIDTH: u32 = 1600;
const DISPLAY_HEIGHT: u32 = 900;

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

fn write_color(color: &Color) {
    let r_byte: u8 = (255.999 * color[0]) as u8;
    let g_byte: u8 = (255.999 * color[1]) as u8;
    let b_byte: u8 = (255.999 * color[2]) as u8;

    println!("{r_byte} {g_byte} {b_byte}");
}

fn main() {
    println!("P3");
    println!("{DISPLAY_WIDTH} {DISPLAY_HEIGHT}");
    println!("255");

    for row in 0..DISPLAY_HEIGHT {
        log_progress(row as f32 / (DISPLAY_HEIGHT as f32 - 1.0));
        for col in 0..DISPLAY_WIDTH {
            let red: f64 = row as f64 / (DISPLAY_WIDTH as f64 - 1.0);
            let green: f64 = 0.0;
            let blue: f64 = col as f64 / (DISPLAY_HEIGHT as f64 - 1.0);

            let color = Color::new(red, green, blue);
            write_color(&color);
        }
    }
}
