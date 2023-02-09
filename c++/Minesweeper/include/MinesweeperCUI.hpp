#pragma once

#include <cstdint>

#include "MinesweeperUI.hpp"

class MinesweeperCUI : public MinesweeperUI {
public:
    // コンストラクタ
    MinesweeperCUI() = default;

    // ゲームのメインループを実行
    void Run() noexcept;
    
    // 新しい盤面で開始
    void NewGame(std::uint8_t row_number, std::uint8_t column_number, std::uint16_t mine) noexcept override;

    // 盤面を表示
    void Display() noexcept override;
};