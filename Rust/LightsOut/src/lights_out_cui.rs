use crate:: lights_out_sys::LightsOutSys;
use crate::lights_out_ui::LightsOutUI;

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
        self.new_game(3);
        self.push(4);
        self.display();
    }
}

impl LightsOutUI for LightsOutCUI {
    // 新しい盤面で開始
    fn new_game(&mut self, length: u8) {
        self.system.set_length(length);
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