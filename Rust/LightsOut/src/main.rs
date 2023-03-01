struct LightsOutSys {
    length: u8,         // 一辺のライトの数
    size: u16,          // ライトの数
    board: Vec<bool>,   // 盤面
}

impl LightsOutSys {
    // 盤面の作成
    fn create(length: u8) -> LightsOutSys {
        let mut sys = LightsOutSys { length, size: 0, board: Vec::new() };
        sys.set_length(length);
        sys
    }
}

impl LightsOutSys {
    // 大きさを変更
    fn set_length(&mut self, length: u8) {
        self.length = length;
        self.size = (length as u16).pow(2);
        self.board.resize(self.size.into(), false);
    }
}

fn main() {
    let sys = LightsOutSys::create(3);
    println!("{}", sys.length);
    for v in sys.board {
        println!("{}", v);
    }
}
