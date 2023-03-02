mod lights_out_sys;
mod lights_out_ui;
mod lights_out_cui;

use crate::lights_out_ui::LightsOutUI;
use crate::lights_out_cui::LightsOutCUI;

fn main() {
    let mut cui = LightsOutCUI::create();
    cui.new_game(3);
    cui.push(4);
    cui.display();
}