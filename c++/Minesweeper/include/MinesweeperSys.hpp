#pragma once

#include <cstdint>
#include <vector>

#include "MinesweeperCell.hpp"

class Direction {
private:
    std::int8_t horizontal;
    std::int8_t vertical;
public:
    // デフォルトコンストラクタ
    Direction() = default;
    // コンストラクタ (引数はSetDirectionと同じ)
    Direction(std::int8_t horizontal, std::int8_t vertical);

    // 位置を変更
    // horizontal : 負:左  0:中央  正:右
    // vertical   : 負:下  0:中央  正:上
    void SetDirection(std::int8_t horizontal, std::int8_t vertical);

    // 水平方向の向きを取得
    // 左:-1  中央:0  右:1
    std::int8_t GetHorizontal();

    // 垂直方向の向きを取得
    // 下:-1  中央:0  上:1
    std::int8_t GetVertical();
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

    // その方向が存在するか調べる
    bool CheckDirection(Direction dir, std::uint16_t pos) noexcept;
    
    // 特定の方向の座標を計算
    std::uint16_t CalcDirectionPos(Direction dir, std::uint16_t pos) noexcept;

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

    // セルの爆弾や数字を取得
    CellData GetCellData(std::uint16_t pos) noexcept;
    CellData GetCellData(std::uint8_t row, std::uint8_t column) noexcept;

    // 開ける（爆弾のときtrueを返却。存在しない場所はfalseの例外を投げる）
    bool Open(std::uint16_t pos);
    bool Open(std::uint8_t row, std::uint8_t column);

    // 開いているか確認
    bool IsOpen(std::uint16_t pos) noexcept;
    bool IsOpen(std::uint8_t row, std::uint8_t column) noexcept;

    // 旗を切り換える（存在しない場所はfalseの例外を投げる）
    void ToggleFlag(std::uint16_t pos);
    void ToggleFlag(std::uint8_t row, std::uint8_t column);

    // 旗が立っているか確認
    bool IsFlagged(std::uint16_t pos) noexcept;
    bool IsFlagged(std::uint8_t row, std::uint8_t column) noexcept;

    // 爆弾の残り数を取得
    std::uint16_t GetRemainingMines() noexcept;

    // クリアしているか確認
    bool IsSuccess() noexcept;
};
