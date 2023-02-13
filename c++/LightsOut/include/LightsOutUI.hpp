#pragma once

#include <cstdint>

#include "LightsOutSys.hpp"

class LightsOutUI {
protected:
    LightsOutSys system;
public:
    // 新しい盤面で開始
    virtual void NewGame(std::uint8_t length) noexcept = 0;

    // 盤面を表示
    virtual void Display() noexcept = 0;

    // ライトを押す（失敗時：false）
    virtual bool Push(std::uint16_t position) noexcept = 0;
    virtual bool Push(std::uint8_t row, std::uint8_t column) noexcept = 0;

    // すべてoffにできているか確認
    virtual bool IsSuccess() noexcept = 0;
};