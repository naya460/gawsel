#pragma once

#include <wx/wx.h>

#include "LightsOutUI.hpp"

class LightsOutWxWidgets : public LightsOutUI {
private:
    const std::uint8_t max_len = 10;
    const std::uint16_t max_size = max_len * max_len;

    wxFrame *frame;

    // ボタンの大きさを調整
    void Fit();
public:
    // コンストラクタ
    LightsOutWxWidgets();

    // デストラクタ
    ~LightsOutWxWidgets();

    // 新しい盤面で開始
    void NewGame(std::uint8_t length) noexcept override;

    // 盤面を表示
    void Display() noexcept override;

    // ライトを押す（失敗時：false）
    bool Push(std::uint16_t position) noexcept override;
    bool Push(std::uint8_t row, std::uint8_t column) noexcept override;

    // すべてoffにできているか確認
    bool IsSuccess() noexcept override;
};

class LightsOutApp : public wxApp {
public:
    bool OnInit();
};