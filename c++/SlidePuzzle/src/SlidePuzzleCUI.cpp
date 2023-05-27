#include "SlidePuzzleCUI.hpp"

#include <iostream>
#include <iomanip>

void SlidePuzzleCUI::new_game() noexcept {
    // 盤面を初期化
    sys.reset();
}

void SlidePuzzleCUI::display() const noexcept {
    for (int i = 0; i < sys.get_size(); ++i) {
        // 数字を表示
        std::cout << std::setw(2) << sys.get_number(i).value() << " ";
        // 行末のとき改行
        if ((i + 1) % sys.get_length() == 0) {
            std::cout << std::endl;
        }
    }
}

bool SlidePuzzleCUI::slide(uint8_t x, uint8_t y) noexcept {
    return sys.move_number(x, y);
}

bool SlidePuzzleCUI::slide(uint16_t pos) noexcept {
    return sys.move_number(pos);
}