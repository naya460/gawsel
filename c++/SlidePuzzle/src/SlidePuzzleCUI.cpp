#include "SlidePuzzleCUI.hpp"

#include <iostream>
#include <iomanip>

void SlidePuzzleCUI::new_game() const noexcept {
    
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