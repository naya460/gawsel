struct LightsOutSys {
    length: u8,         // 一辺のライトの数
    board: Vec<bool>,   // 盤面
}

fn main() {
    let mut sys = LightsOutSys {
        length: 3u8,
        board: Vec::new(),
    };
    println!("{}", sys.length);
    for _i in 0..sys.length {
        sys.board.push(false);
    }
}
