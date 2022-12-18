#include "LightsOutWxWidgets.hpp"

#include <wx/wx.h>

void LightsOutWxWidgets::FitButton(){
    // サイズを計算
    int x, y, len;
    GetClientSize(&x, &y);
    len = std::min(x, y);
    len = std::max(50, len / system.get_length());

    // ボタンのサイズをを変更
    for (int i = 0; i < max_size; ++i) {
        GetSizer()->SetItemMinSize(i, wxSize(len, len));
        GetSizer()->Layout();
        if (i % max_len >= system.get_length() || i / max_len >= system.get_length()) {
            GetSizer()->Show(i, false);
        } else {
            GetSizer()->Show(i, true);
        }
    }
}

LightsOutWxWidgets::LightsOutWxWidgets() : wxFrame(NULL, wxID_ANY, "Lights Out"){
    // 盤面を作成
    wxFlexGridSizer *grid_sizer = new wxFlexGridSizer(max_len, max_len, 0, 0);
    for (int i = 0; i < max_size; ++i) {
        wxButton *button = new wxButton(this, wxID_ANY);
        lights.insert(lights.begin() + i, button);
        button->SetMinSize(wxSize(50, 50));
        button->Bind(wxEVT_BUTTON, &LightsOutWxWidgets::PushButton, this);
        grid_sizer->Add(button, wxEXPAND | wxSHAPED);
    }
    SetSizer(grid_sizer);
    SetSize(500, 500);
    NewGame(5);

    Show();
}

LightsOutWxWidgets::~LightsOutWxWidgets(){
    Destroy();
}

void LightsOutWxWidgets::NewGame(std::uint8_t length) noexcept{
    system.set_length(length);
    FitButton();
    system.random();
    Display();
};

void LightsOutWxWidgets::Display() noexcept{
    std::uint16_t size = system.get_size();
    std::uint8_t length = system.get_length();
    for (int i = 0; i < size; ++i) {
        wxButton *b = lights[i % length * max_len + i / length];
        if (system.is_on(i)) {
            b->SetBackgroundColour(light_on);
        } else {
            b->SetBackgroundColour(light_off);
        }
    }
}

bool LightsOutWxWidgets::Push(std::uint16_t position) noexcept{
    try {
        system.push(position);
    }
    catch (bool b) {
        return false;
    }
    return true;
}

bool LightsOutWxWidgets::Push(std::uint8_t row, std::uint8_t column) noexcept{
    try {
        system.push(row, column);
    }
    catch (bool b) {
        return false;
    }
    return true;
}

bool LightsOutWxWidgets::IsSuccess() noexcept{
    return false;
}

void LightsOutWxWidgets::PushButton(wxCommandEvent& event){
    wxWindowID id = event.GetId();
    std::uint16_t size = system.get_size();
    std::uint8_t length = system.get_length();
    for (int i = 0; i < size; ++i) {
        if (lights[i % length * max_len + i / length]->GetId() == id) {
            Push(i);
        }
    }
    Display();
}

bool LightsOutApp::OnInit(){
    LightsOutWxWidgets *gui = new LightsOutWxWidgets();
    return true;
}