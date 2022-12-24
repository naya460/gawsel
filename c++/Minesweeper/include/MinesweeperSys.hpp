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

// 方向の一覧
enum class Direction {
    UL, U, UR,  // 左上、上、右上
    L, C, R,    // 左、中央、右
    BL, B, BR,  // 左下、下、右下
};

class MinesweeperCell {
private:
    bool open = false;              // セルが空いているか
    CellData data = CellData::_0;   // 番号や爆弾
    bool flag = false;              // 旗が立っているか
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

    // 旗を切り替える
    void ToggleFlag();

    // 旗の状態を調べる（true:旗が立っている）
    bool IsFlagged();
};

class MinesweeperSys {
private:
    // 盤面の行数と列数
    std::uint8_t row_num;
    std::uint8_t column_num;
    // 爆弾の総数
    std::uint16_t mine;

    // 開始しているか
    bool started = false;

    // 盤面
    std::vector<MinesweeperCell> board;

    // 特定の辺か調べる（対応するsideは、U,B,L,Rのみ。他は必ずfalse）
    bool CheckSide(Direction side, Direction dir, std::uint16_t pos) noexcept;

    // その方向が存在するか調べる
    bool CheckDirection(Direction dir, std::uint16_t pos) noexcept;

    // 特定の方向の数字を加算
    void AddDirectionNum(Direction dir, std::uint16_t pos) noexcept;

    // 周りの数字を加算
    void AddCellNum(std::uint16_t pos) noexcept;

    // ランダムに爆弾を設置
    void Random(std::uint16_t pos) noexcept;
public:
    // コンストラクタ
    MinesweeperSys(std::uint8_t row_number, std::uint8_t column_number, std::uint16_t mine);

    // 大きさを変更
    void SetSizeAndMine(std::uint8_t row_number, std::uint8_t column_number, std::uint16_t mine) noexcept;

    // 盤面を初期化
    void Reset() noexcept;

    // セルを取得
    MinesweeperCell GetCell(std::uint16_t pos) noexcept;
    MinesweeperCell GetCell(std::uint8_t row, std::uint8_t column) noexcept;

    // 開ける（爆弾のときtrue、存在しない場所はfalseの例外を投げる）
    bool Open(std::uint16_t pos);
    bool Open(std::uint8_t row, std::uint8_t column);
};