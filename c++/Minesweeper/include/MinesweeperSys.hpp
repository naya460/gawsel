#pragma once

#include <cstdint>
#include <vector>

class MinesweeperCell {
private:
    bool open = false;      // セルが空いているか
    std::uint8_t num = 0;   // セルの番号
public:
    // コンストラクタ
    MinesweeperCell() = default;

    // セルの初期化
    void Reset(std::uint8_t num);

    // 数字を取得
    std::uint8_t GetNum();

    // 空いているか確認
    bool IsOpen();

    // 開ける
    void Open();
};

class MinesweeperSys {
private:
    // 盤面の行数と列数
    std::uint8_t row;
    std::uint8_t column;

    // 盤面
    std::vector<MinesweeperCell> board;

    // 大きさを変更
    void SetSize(std::uint8_t row_number, std::uint8_t column_number);
public:
    // コンストラクタ
    MinesweeperSys(std::uint8_t row_number, std::uint8_t column_number);
};
