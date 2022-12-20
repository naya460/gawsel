#pragma once

#include <cstdint>
#include <vector>

class MinesweeperSys {
private:
    // 盤面の行数と列数
    std::uint8_t row;
    std::uint8_t column;

    // 盤面
    std::vector<bool> board;

    // 大きさを変更
    void SetSize(std::uint8_t row_number, std::uint8_t column_number);
public:
    // コンストラクタ
    MinesweeperSys(std::uint8_t row_number, std::uint8_t column_number);
};
