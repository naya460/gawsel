#pragma once

#include <cstdint>

#include "MinesweeperSys.hpp"

class MinesweeperUI {
protected:
    MinesweeperSys system;
public:
    // 新しい盤面で開始
    virtual void NewGame(std::uint8_t row_number, std::uint8_t column_number, std::uint16_t mine) noexcept = 0;

    // 盤面を表示
    virtual void Display() noexcept = 0;
};