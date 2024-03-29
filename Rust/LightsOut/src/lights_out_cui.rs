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

use crate:: lights_out_sys::LightsOutSys;
use crate::lights_out_ui::LightsOutUI;

use std::io;

pub struct LightsOutCUI {
    system: LightsOutSys,
}

impl LightsOutCUI {
    // LightsOutCUIを作成
    pub fn create() -> LightsOutCUI {
        let system = LightsOutSys::create(3);
        let cui = LightsOutCUI { system };
        cui
    }

    // ゲームのメインループを実行
    pub fn run(&mut self) {
        loop {
            // 大きさを聞く
            println!("Input board length (2 - 255)");
            let length = self.input(2, 255);
            
            // 新しい盤面を開始
            self.new_game(length);
            println!("\nGame : {}x{}", length, length);

            // クリアまで入力と表示を繰り返す
            while !self.system.check_clear() {
                // 位置を入力するクロージャ
                let input_pos = || -> u16 {
                    // 長さを取得
                    let length = self.system.get_length();
                    // 行を入力
                    println!("Input row (0-{})", length - 1);
                    let row = self.input(0, length - 1) as u16;
                    // 列を入力
                    println!("Input column (0-{})", length - 1);
                    let column = self.input(0, length - 1) as u16;
                    // 位置を計算して返却
                    row * length as u16 + column
                };

                // 表示
                self.display();

                // 入力
                self.push(input_pos());
            }
            
            // 最後に表示
            self.display();

            // もう一度遊ぶか聞く
            println!("Clear");
            println!("0:continue 1:exit");
            if self.input(0, 1) == 1 { break; }
        }
    }

    // 値を制限付きで入力
    fn input(&self, min: u8, max: u8) -> u8 {
        loop {
            // 数値を入力
            let mut num = String::new();
            io::stdin().read_line(&mut num).ok();
            let num: u8 = num.trim().parse().ok().unwrap();
            // 範囲内のとき値を返す
            if min <= num && num <= max { break num; }
        }
    }
}

impl LightsOutUI for LightsOutCUI {
    // 新しい盤面で開始
    fn new_game(&mut self, length: u8) {
        self.system.set_length(length);
        self.system.random();
    }

    // 盤面を表示
    fn display(&self) {
        for i in 0..self.system.get_size() {
            if self.system.is_on(i).unwrap() {
                print!("o ");
            } else {
                print!("_ ");
            }
            if (i + 1) as u8 % self.system.get_length() == 0 {
                print!("\n");
            }
        }
    }

    // ライトを押す (失敗時:false)
    fn push(&mut self, pos: u16) -> bool {
        self.system.push(pos)
    }
}