#pragma once

#include <cstdint>
#include <vector>

// 番号や爆弾の一覧
enum class CellData {
    Mine = -1,
    _0 = 0,
    _1, _2, _3, _4,
    _5, _6, _7, _8,
};

class MinesweeperCell {
private:
    bool open = false;              // セルが空いているか
    CellData data = CellData::_0;   // 番号や爆弾
public:
    // コンストラクタ
    MinesweeperCell() = default;

    // セルの初期化
    void Reset(CellData data);

    // 番号や爆弾を返す
    CellData GetData();

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
