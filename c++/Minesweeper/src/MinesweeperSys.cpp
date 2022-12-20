#include "MinesweeperSys.hpp"

void MinesweeperSys::SetSize(std::uint8_t row_number, std::uint8_t column_number){
    row = row_number;
    column = column_number;
    board.resize(row * column);
    for (auto v : board) {
        v = false;
    }
}

MinesweeperSys::MinesweeperSys(std::uint8_t row_number, std::uint8_t column_number){
    // 盤面の大きさを設定
    SetSize(row_number, column_number);
}