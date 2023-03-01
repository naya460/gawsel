pub struct LightsOutSys {
    pub length: u8,         // 一辺のライトの数
    pub size: u16,          // ライトの数
    pub board: Vec<bool>,   // 盤面
}

impl LightsOutSys {
    // 盤面の作成
    pub fn create(length: u8) -> LightsOutSys {
        let mut sys = LightsOutSys { length, size: 0, board: Vec::new() };
        sys.set_length(length);
        sys
    }

    // 大きさを変更
    pub fn set_length(&mut self, length: u8) {
        self.length = length;
        self.size = (length as u16).pow(2);
        self.board.resize(self.size.into(), false);
    }
}