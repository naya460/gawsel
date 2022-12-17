#include "LightsOutCUI.hpp"

#include <iostream>

// 新しい盤面で開始
void LightsOutCUI::NewGame(std::uint8_t length) noexcept{
    system.set_length(length);
    system.random();
}

// 盤面を表示
void LightsOutCUI::Display() noexcept{
    // 大きさを取得
    std::uint8_t length = system.get_length();
    std::uint16_t size = system.get_size();
    // 表示
    for (std::uint16_t i = 0; i < size; ++i) {
        std::cout << ((system.is_on(i))? "o" : "_") << " ";
        // 列の最後のとき改行
        if ((i + 1) % length == 0) {
            std::cout << std::endl;
        }
    }
}

// ライトを押す
bool LightsOutCUI::Push(std::uint16_t position) noexcept{
    try {
        system.push(position);
    }
    catch (bool exception) {
        return false;
    }
    return true;
}

bool LightsOutCUI::Push(std::uint8_t row, std::uint8_t column) noexcept{
    try {
        system.push(row, column);        
    }
    catch (bool exception) {
        return false;
    }
    return true;
}

bool LightsOutCUI::IsSuccess() noexcept{
    return system.check_clear();
}