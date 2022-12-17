#pragma once

#include <cstdint>

#include "LightsOutUI.hpp"

class LightsOutCUI : public LightsOutUI {
public:
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