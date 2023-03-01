mod lights_out_sys;
use crate::lights_out_sys::LightsOutSys;

fn main() {
    let sys = LightsOutSys::create(3);
    println!("{}", sys.length);
    for v in sys.board {
        println!("{}", v);
    }
}
