#pragma once

#include "SlidePuzzleSys.hpp"

class SlidePuzzleUI {
protected:
    SlidePuzzleSys sys;
public:
    // 新しい盤面を開始
    virtual void new_game() noexcept = 0;

    // 盤面を表示する
    virtual void display() const noexcept = 0;
    
    // パネルを移動
    virtual bool slide(uint8_t x, uint8_t y) noexcept = 0;
    virtual bool slide(uint16_t pos) noexcept = 0;
};