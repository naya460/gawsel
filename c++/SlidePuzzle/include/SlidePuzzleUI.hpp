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
};