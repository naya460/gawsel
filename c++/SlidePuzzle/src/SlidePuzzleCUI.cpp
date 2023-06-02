#include "SlidePuzzleCUI.hpp"

#include <iostream>
#include <iomanip>

uint8_t SlidePuzzleCUI::input(std::string str, uint8_t min, uint8_t max) const noexcept {
    int num;
    while (true) {
        std::cout << str;
        std::cin >> num;
        // 範囲内のときループを抜ける
        if (min <= num && num <= max) break;
        // 範囲外のとき
        std::cout << "Try again..." << std::endl;
    }
    return num;
}

void SlidePuzzleCUI::run() noexcept {
    sys.randomize();

    while (true) {
        // 出力
        display();

        // クリアしていたら終了
        if (sys.check_clear()) {
            std::cout << "Clear!!" << std::endl;

            int c;
            std::cout << "Continue : 0, exit : 1" << std::endl << ">> ";
            std::cin >> c;
            if (c) break;

            sys.randomize();
            continue;
        }

        // 入力
        uint8_t x, y;

        x = input("x : ", 0, sys.get_length() - 1);
        y = input("y : ", 0, sys.get_length() - 1);

        slide(x, y);
    }
}

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