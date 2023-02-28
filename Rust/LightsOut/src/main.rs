struct LightsOutSys {
    length: u8,         // 一辺のライトの数
    board: Vec<bool>,   // 盤面
}

impl LightsOutSys {
    // 盤面の作成
    fn create(length: u8) -> LightsOutSys {
        let board = vec![false; (length * length).into()];
        let sys = LightsOutSys {
            length,
            board,
        };
        sys
    }
}

fn main() {
    let sys = LightsOutSys::create(3);
    println!("{}", sys.length);
    for v in sys.board {
        println!("{}", v);
    }
}
