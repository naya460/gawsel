#pragma once

#include <cstdint>

#include "MinesweeperUI.hpp"

class MinesweeperCUI : public MinesweeperUI {
private:
    std::uint8_t cur_row = 0;
    std::uint8_t cur_column = 0;

    // コマンドを入力
    void Input() noexcept;
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
};