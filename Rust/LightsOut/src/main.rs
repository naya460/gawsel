mod lights_out_sys;
use crate::lights_out_sys::LightsOutSys;

fn main() {
    let mut sys = LightsOutSys::create(3);
    sys.push(5).unwrap();
    println!("{}", sys.get_length());
    for i in 0..sys.get_size() {
        println!("{}", sys.is_on(i).unwrap());
    }
}
