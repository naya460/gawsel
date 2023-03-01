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
}

impl LightsOutUI for LightsOutCUI {
    // 新しい盤面で開始
    fn new_game(&mut self, length: u8) {
        self.system.set_length(length);
    }

    // 盤面を表示
    fn display(&self) {
        for i in 0..self.system.get_size() {
            println!("{}", self.system.is_on(i).unwrap());
        }
    }
}