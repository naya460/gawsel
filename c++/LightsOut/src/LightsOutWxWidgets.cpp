#include "LightsOutWxWidgets.hpp"

#include <wx/wx.h>

void LightsOutWxWidgets::Fit(){
    // サイズを計算
    int x, y, len;
    frame->GetClientSize(&x, &y);
    len = std::min(x, y);
    len = std::max(50, len / system.get_length());

    // ボタンのサイズをを変更
    for (int i = 0; i < max_size; ++i) {
        frame->GetSizer()->SetItemMinSize(i, wxSize(len, len));
        frame->GetSizer()->Layout();
        if (i % max_len >= system.get_length() || i / max_len >= system.get_length()) {
            frame->GetSizer()->Show(i, false);
        } else {
            frame->GetSizer()->Show(i, true);
        }
    }
}

LightsOutWxWidgets::LightsOutWxWidgets(){
    // フレームを作成
    frame = new wxFrame(NULL, wxID_ANY, "Lights Out");

    // 盤面を作成
    wxFlexGridSizer *grid_sizer = new wxFlexGridSizer(max_len, max_len, 0, 0);
    for (int i = 0; i < max_size; ++i) {
        wxButton *button = new wxButton(frame, wxID_ANY);
        button->SetMinSize(wxSize(50, 50));
        grid_sizer->Add(button, wxEXPAND | wxSHAPED);
    }
    frame->SetSizer(grid_sizer);
    frame->SetSize(500, 500);
    NewGame(5);

    frame->Show();
}

LightsOutWxWidgets::~LightsOutWxWidgets(){
    frame->Destroy();
}

void LightsOutWxWidgets::NewGame(std::uint8_t length) noexcept{
    system.set_length(length);
    Fit();
    system.random();
};

void LightsOutWxWidgets::Display() noexcept{
    return;
}

bool LightsOutWxWidgets::Push(std::uint16_t position) noexcept{
    return false;
}

bool LightsOutWxWidgets::Push(std::uint8_t row, std::uint8_t column) noexcept{
    return false;
}

bool LightsOutWxWidgets::IsSuccess() noexcept{
    return false;
}

bool LightsOutApp::OnInit(){
    LightsOutWxWidgets *gui = new LightsOutWxWidgets();
    return true;
}