#include "MinesweeperSys.hpp"

// === MinesweeperCell ===
void MinesweeperCell::Reset(std::uint8_t num){
    open = false;
    this->num = num;
}

std::uint8_t MinesweeperCell::GetNum(){
    return num;
}

bool MinesweeperCell::IsOpen(){
    return open;
}

void MinesweeperCell::Open(){
    open = true;
}

// === MinesweeperSys ===
void MinesweeperSys::SetSize(std::uint8_t row_number, std::uint8_t column_number){
    // 大きさを保存
    row = row_number;
    column = column_number;
    // 盤面の大きさを変更
    board.resize(row * column);
    for (auto v : board) {
        v.Reset(0);
    }
}

MinesweeperSys::MinesweeperSys(std::uint8_t row_number, std::uint8_t column_number){
    // 盤面の大きさを設定
    SetSize(row_number, column_number);
}