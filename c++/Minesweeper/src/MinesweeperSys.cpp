#include "MinesweeperSys.hpp"

#include <algorithm>

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
MinesweeperSys::MinesweeperSys(std::uint8_t row_number, std::uint8_t column_number, std::uint16_t mine){
    // 盤面の大きさを設定
    SetSizeAndMine(row_number, column_number, mine);
}

void MinesweeperSys::SetSizeAndMine(std::uint8_t row_number, std::uint8_t column_number, std::uint16_t mine) noexcept{
    // 大きさを保存
    row = row_number;
    column = column_number;
    // 爆弾の数を変更
    this->mine = std::min(mine, static_cast<std::uint16_t>(row * column - 9));
    // 盤面の大きさを変更
    board.resize(row * column);
    for (auto v : board) {
        v.Reset(CellData::_0);
    }
}
