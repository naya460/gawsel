mod lights_out_sys;
use crate::lights_out_sys::LightsOutSys;

fn main() {
    let sys = LightsOutSys::create(3);
    println!("{}", sys.get_length());
    for i in 0..sys.get_size() {
        println!("{}", sys.is_on(i).unwrap());
    }
}
