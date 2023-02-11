#include "MinesweeperCUI.hpp"

#include <iostream>

void MinesweeperCUI::Input() noexcept{
    std::string input;
    std::cout << "cmd : ";
    std::cin >> input;
    // 入力された文字を全て解釈
    for (int i = 0; i < input.size(); ++i) {
        switch (input[i]) {
            // 上
            case 'w': case 'k':
                cur_row = std::max(0, cur_row - 1);
                break;
            // 下
            case 's': case 'j':
                cur_row = std::min(8, cur_row + 1);
                break;
            // 左
            case 'a': case 'h':
                cur_column = std::max(0, cur_column - 1);
                break;
            // 右
            case 'd': case 'l':
                cur_column = std::min(8, cur_column + 1);
                break;
            // 開ける
            case 'e': case 'o':
                Open(cur_row, cur_column);
                break;
            // 旗を立てる
            case 'f': case 'i':
                ToggleFlag(cur_row, cur_column);
                break;
        }
    }
}

void MinesweeperCUI::Run() noexcept{
    NewGame(9, 9, 10);

    // メインループ
    while (true) {
        // 出力
        Display();

        // 入力
        Input();
    }
}

void MinesweeperCUI::NewGame(std::uint8_t row_number, std::uint8_t column_number, std::uint16_t mine) noexcept{
    system.SetSizeAndMine(row_number, column_number, mine);
}

void MinesweeperCUI::Display() noexcept{
    // 上側の矢印を表示
    std::cout << "  ";
    for (int i = 0; i < cur_column; ++i) {
        std::cout << "   ";
    }
    std::cout << "v" << std::endl;
    
    // セルを表示
    for (int i = 0; i < 9 * 9; ++i) {
        // 左側の矢印を表示
        if (i % 9 == 0) {
            if (i / 9 == cur_row) {
                std::cout << "> ";
            } else {
                std::cout << "  ";
            }
        }
        // 空いていないとき
        if (system.GetCell(i).IsOpen() == false) {
            // 旗が立っているとき
            if (system.GetCell(i).IsFlagged() == true) {
                std::cout << "P";
            } else {
                std::cout << "Q";
            }
        }
        // 爆弾のとき
        else if (system.GetCell(i).GetData() == CellData::Mine) {
            std::cout << "x";
        }
        // 空白のとき
        else if (system.GetCell(i).GetData() == CellData::_0) {
            std::cout << "_";
        }
        // 数字のとき
        else {
            std::cout << static_cast<int>(system.GetCell(i).GetData());
        }
        // 区切り
        std::cout << "  ";
        if (i % 9 == 8) {
            std::cout << std::endl;
        }
    }
}

bool MinesweeperCUI::Open(std::uint16_t position) noexcept{
    try {
        return system.Open(position);
    } catch (bool exception) {
        std::cerr << "invalid position" << std::endl;
        exit(1);
    }
}

bool MinesweeperCUI::Open(std::uint8_t row, std::uint8_t column) noexcept{
    try {
        return system.Open(row, column);
    } catch (bool exception) {
        std::cerr << "invalid position" << std::endl;
        exit(1);
    }
}

void MinesweeperCUI::ToggleFlag(std::uint16_t position) noexcept{
    try {
        system.ToggleFlag(position);
    } catch (bool exception) {
        std::cerr << "invalid position" << std::endl;
    }
}

void MinesweeperCUI::ToggleFlag(std::uint8_t row, std::uint8_t column) noexcept{
    try {
        system.ToggleFlag(row, column);
    } catch (bool exception) {
        std::cerr << "invalid position" << std::endl;
    }
}
