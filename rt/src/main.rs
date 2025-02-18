#![allow(unused)]

use cgmath::Vector3;

const DISPLAY_WIDTH: u32 = 1600;
const DISPLAY_HEIGHT: u32 = 900;

fn main() {
    println!("P3");
    println!("{DISPLAY_WIDTH} {DISPLAY_HEIGHT}");
    println!("255");

    for row in 0..DISPLAY_HEIGHT {
        for col in 0..DISPLAY_WIDTH {
            let red: f64 = row as f64 / (DISPLAY_WIDTH as f64 - 1.0);
            let green: f64 = 0.0;
            let blue: f64 = col as f64 / (DISPLAY_HEIGHT as f64 - 1.0);

            let r_byte: u8 = (255.999 * red) as u8;
            let g_byte: u8 = (255.999 * green) as u8;
            let b_byte: u8 = (255.999 * blue) as u8;

            println!("{r_byte} {g_byte} {b_byte}");
        }
    }
}
