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
        // 大きさを聞く
        println!("Input board length (2 - 255)");
        let length = self.input(2, 255);
        
        // 新しい盤面を開始
        self.new_game(length);
        println!("\nGame : {}x{}", length, length);

        self.push(4);
        self.display();
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