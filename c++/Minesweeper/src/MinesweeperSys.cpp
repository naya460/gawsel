#include "MinesweeperSys.hpp"

// === MinesweeperCell ===
void MinesweeperCell::Reset(CellData data){
    open = false;
    this->data = data;
}

CellData MinesweeperCell::GetData(){
    return data;
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
        v.Reset(CellData::_0);
    }
}

MinesweeperSys::MinesweeperSys(std::uint8_t row_number, std::uint8_t column_number){
    // 盤面の大きさを設定
    SetSize(row_number, column_number);
}