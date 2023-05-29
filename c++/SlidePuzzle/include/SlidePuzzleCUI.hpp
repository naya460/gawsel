#pragma once

#include <string>

#include "SlidePuzzleUI.hpp"

class SlidePuzzleCUI: public SlidePuzzleUI {
private:
    // 入力
    uint8_t input(std::string str, uint8_t min, uint8_t max) const noexcept;
public:
    // ゲームのメインループを実行
    void run() noexcept;

    // 新しい盤面を開始
    void new_game() noexcept override;

    // 盤面を表示する
    void display() const noexcept override;

    // パネルを移動
    bool slide(uint8_t x, uint8_t y) noexcept override;
    bool slide(uint16_t pos) noexcept override;
};