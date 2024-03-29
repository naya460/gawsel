/*
  Copyright 2023 naya460

  Licensed under the Apache License, Version 2.0 (the "License");
  you may not use this file except in compliance with the License.
  You may obtain a copy of the License at

      http://www.apache.org/licenses/LICENSE-2.0

  Unless required by applicable law or agreed to in writing, software
  distributed under the License is distributed on an "AS IS" BASIS,
  WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
  See the License for the specific language governing permissions and
  limitations under the License.
*/

use rand::Rng;
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
        // 範囲外のときfalseを返す
        if pos >= self.size { return false; }

        // ライトを反転するクロージャ (失敗時:false)
        let mut invert = |pos: u16| -> bool {
            if pos >= self.size { return false; }
            let pos = pos as usize;
            self.board[pos] = !self.board[pos];
            true
        };

        // 座標を計算
        let row = pos / self.length as u16;
        let column = pos % self.length as u16;
        let length = self.length as u16;
        
        // 反転
        invert(pos);
        if row != 0             { invert(pos - length); }
        if row != length - 1    { invert(pos + length); }
        if column != 0          { invert(pos - 1); }
        if column != length - 1 { invert(pos + 1); }
        true
    }

    // ランダムに生成
    pub fn random(&mut self) {
        let mut rng = rand::thread_rng();
        for i in 0..self.size {
            let num: i8 = rng.gen();
            if num % 2 == 1 {
                self.push(i);
            }
        }
    }

    // クリアしているか確認
    pub fn check_clear(&self) -> bool {
        let mut clear = true;
        for i in 0..self.size {
            if self.board[i as usize] != false {
                clear = false;
            }
        }
        clear
    }
}