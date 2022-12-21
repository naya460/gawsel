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
    std::uint8_t row_num;
    std::uint8_t column_num;
    // 爆弾の総数
    std::uint16_t mine;

    // 盤面
    std::vector<MinesweeperCell> board;
public:
    // コンストラクタ
    MinesweeperSys(std::uint8_t row_number, std::uint8_t column_number, std::uint16_t mine);

    // 大きさを変更
    void SetSizeAndMine(std::uint8_t row_number, std::uint8_t column_number, std::uint16_t mine) noexcept;

    // ランダムに爆弾を設置
    void Randam() noexcept;

    // セルを取得
    MinesweeperCell GetCell(std::uint16_t pos) noexcept;
    MinesweeperCell GetCell(std::uint8_t row, std::uint8_t column) noexcept;
};
