pub trait LightsOutUI {
    // 新しい盤面で開始
    fn new_game(&mut self, length: u8);
    // 盤面を表示
    fn display(&self);
}