#pragma once

#include <cstdint>
#include <string>

#include "LightsOutUI.hpp"

class LightsOutCUI : public LightsOutUI {
private:
    // 値が範囲内か調べる
    bool Inside(std::uint16_t min, std::uint16_t target, std::uint16_t max) noexcept;

    // 制限付きの値を入力
    std::uint16_t Input(std::string str, std::uint16_t min, std::uint16_t max);
public:
    // ゲームのメインループを実行
    void Run() noexcept;

    // 新しい盤面で開始
    void NewGame(std::uint8_t length) noexcept override;

    // 盤面を表示
    void Display() noexcept override;

    // ライトを押す
    bool Push(std::uint16_t position) noexcept override;
    bool Push(std::uint8_t row, std::uint8_t column) noexcept override;

    // すべてoffにできているか確認
    bool IsSuccess() noexcept override;
};