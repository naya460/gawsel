#pragma once

#include <cstdint>

#include "MinesweeperUI.hpp"

class MinesweeperCUI : public MinesweeperUI {
private:
    std::uint8_t cur_row = 0;
    std::uint8_t cur_column = 0;

    // コマンドを入力
    bool Input() noexcept;
public:
    // コンストラクタ
    MinesweeperCUI() = default;

    // ゲームのメインループを実行
    void Run() noexcept;
    
    // 新しい盤面で開始
    void NewGame(std::uint8_t row_number, std::uint8_t column_number, std::uint16_t mine) noexcept override;

    // 盤面を表示
    void Display() noexcept override;

    // セルを開ける
    bool Open(std::uint16_t position) noexcept override;
    bool Open(std::uint8_t row, std::uint8_t column) noexcept override;

    // 旗を切り替える
    void ToggleFlag(std::uint16_t position) noexcept override;
    void ToggleFlag(std::uint8_t row, std::uint8_t column) noexcept override;
    
    // 爆弾の残り数を表示
    void DisplayRemainingMines() noexcept override;

    // クリアしているか調べる(爆弾の数と開けていないセルの数を比較)
    bool IsSuccess() noexcept override;
};