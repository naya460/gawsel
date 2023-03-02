pub struct LightsOutSys {
    length: u8,         // 一辺のライトの数
    size: u16,          // ライトの数
    board: Vec<bool>,   // 盤面
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

    // 一辺のライトの数を取得
    pub fn get_length(&self) -> u8 { self.length }
    
    // ライトの数を取得
    pub fn get_size(&self) -> u16 { self.size }

    // ライトが光っているか確認
    pub fn is_on(&self, pos: u16) -> Result<bool, u8> { 
        if pos >= self.size { return Err(1); }
        Ok(self.board[pos as usize])
    }

    // ライトを押す (失敗時:false)
    pub fn push(&mut self, pos: u16) -> bool {
        if pos >= self.size { return false; }
        let pos = pos as usize;
        self.board[pos] = !self.board[pos];
        true
    }
}