#pragma once

#include "SlidePuzzleUI.hpp"

class SlidePuzzleCUI: public SlidePuzzleUI {
public:
    // 新しい盤面を開始
    void new_game() noexcept override;

    // 盤面を表示する
    void display() const noexcept override;
};