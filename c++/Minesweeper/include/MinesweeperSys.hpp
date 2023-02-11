#pragma once

#include <cstdint>
#include <vector>

#include "MinesweeperCell.hpp"

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
    bool CheckSide(Direction side, Direction dir) noexcept;

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
    MinesweeperSys();
    MinesweeperSys(std::uint8_t row_number, std::uint8_t column_number, std::uint16_t mine);

    // 大きさを変更
    void SetSizeAndMine(std::uint8_t row_number, std::uint8_t column_number, std::uint16_t mine) noexcept;

    // 大きさの取得
    std::uint8_t GetRowNumber() noexcept;
    std::uint8_t GetColumnNumber() noexcept;
    std::uint16_t GetSize() noexcept;

    // 盤面を初期化
    void Reset() noexcept;

    // セルを取得
    MinesweeperCell GetCell(std::uint16_t pos) noexcept;
    MinesweeperCell GetCell(std::uint8_t row, std::uint8_t column) noexcept;

    // 開ける（爆弾のときtrueを返却。存在しない場所はfalseの例外を投げる）
    bool Open(std::uint16_t pos);
    bool Open(std::uint8_t row, std::uint8_t column);

    // 旗を切り換える（存在しない場所はfalseの例外を投げる）
    void ToggleFlag(std::uint16_t pos);
    void ToggleFlag(std::uint8_t row, std::uint8_t column);

    // 爆弾の残り数を取得
    std::uint16_t GetRemainingMines() noexcept;

    // クリアしているか確認
    bool IsSuccess() noexcept;
};
