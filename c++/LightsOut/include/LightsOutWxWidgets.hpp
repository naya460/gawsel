/*
  Copyright 2023 naya460

  Licensed under the Apache License, Version 2.0 (the "License");
  you may not use this file except in compliance with the License.
  You may obtain a copy of the License at

      http://www.apache.org/licenses/LICENSE-2.0

  Unless required by applicable law or agreed to in writing, software
  distributed under the License is distributed on an "AS IS" BASIS,
  WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
  See the License for the specific language governing permissions and
  limitations under the License.
*/

#pragma once

#include <wx/wx.h>

#include "LightsOutUI.hpp"

class LightsOutWxWidgets : public LightsOutUI, public wxFrame{
private:
    // GUIでの最大サイズ
    const std::uint8_t max_len = 10;
    const std::uint16_t max_size = max_len * max_len;

    // 選択している大きさ
    std::uint8_t playing_len = 5;

    // 色の指定
    wxColour light_on{50, 100, 100};
    wxColour light_off{50, 50, 50};

    // ライトの一覧
    std::vector<wxButton*> lights;

    // ボタンの大きさを調整
    void FitButton();
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

    // ボタンが押されたときのイベント
    void PushButton(wxCommandEvent& event);

    // メニューが押されたときのイベント
    void SelectMenu(wxCommandEvent& event);

    // フレームの大きさの変更
    void ResizeWindow(wxSizeEvent& event);
};

class LightsOutApp : public wxApp {
public:
    bool OnInit();
};