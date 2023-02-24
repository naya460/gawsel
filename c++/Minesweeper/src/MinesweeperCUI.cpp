#include "MinesweeperCUI.hpp"

#include <iostream>

bool MinesweeperCUI::Input() noexcept{
    std::string input;
    std::cout << "cmd : ";
    std::cin >> input;
    bool ret = false;
    // 入力された文字を全て解釈
    for (int i = 0; i < input.size(); ++i) {
        switch (input[i]) {
            // 上
            case 'w': case 'k':
                cur_row = std::max(0, cur_row - 1);
                break;
            // 下
            case 's': case 'j':
                cur_row = std::min(system.GetRowNumber() - 1, cur_row + 1);
                break;
            // 左
            case 'a': case 'h':
                cur_column = std::max(0, cur_column - 1);
                break;
            // 右
            case 'd': case 'l':
                cur_column = std::min(system.GetColumnNumber() - 1, cur_column + 1);
                break;
            // 開ける
            case 'e': case 'o':
                ret += Open(cur_row, cur_column);
                break;
            // 旗を立てる
            case 'f': case 'i':
                ToggleFlag(cur_row, cur_column);
                break;
        }
    }
    return ret;
}

void MinesweeperCUI::Run() noexcept{
    // メインループ
    while (true) {
        // モードを選択
        std::cout << "=== Mode Selection ===" << std::endl;
        std::cout << "1. 9x9   : 10" << std::endl;
        std::cout << "2. 16x16 : 40" << std::endl;
        std::cout << "3. 30x16 : 99" << std::endl;
        int mode;
        do {
            std::cout << ">>> ";
            std::cin >> mode;
        } while (mode < 1 || mode > 3);

        // 新しい盤面を開始
        switch (mode) {
            case 1:
                NewGame(9, 9, 10);
                break;
            case 2:
                NewGame(16, 16, 40);
                break;
            case 3:
                NewGame(16, 30, 99);
        }
        
        // クリアまで表示と入力を繰り返す
        while (!IsSuccess()) {
            // 出力
            Display();

            // 入力
            if (Input()) {
                break;
            }
        }

        // 最後に表示
        Display();

        if (IsSuccess()) {
            std::cout << "Clear" << std::endl;
        } else {
            std::cout << "Failed" << std::endl;
        }

        // もう一度遊ぶか聞く
        bool exit = true;
        std::cout << "0:continue 1:exit" << std::endl;
        std::cout << ">>> ";
        std::cin >> exit;
        if (exit == true) break;
    }
}

void MinesweeperCUI::NewGame(std::uint8_t row_number, std::uint8_t column_number, std::uint16_t mine) noexcept{
    system.SetSizeAndMine(row_number, column_number, mine);
    cur_row = cur_column = 0;
}

void MinesweeperCUI::Display() noexcept{
    // 残りの爆弾数を表示
    DisplayRemainingMines();
    // 上側の矢印を表示
    std::cout << "  ";
    for (int i = 0; i < cur_column; ++i) {
        std::cout << "  ";
    }
    std::cout << "v" << std::endl;
    
    // セルを表示
    for (int i = 0; i < system.GetSize(); ++i) {
        // カーソルの場所かどうか調べる
        bool is_target = i / system.GetColumnNumber() == cur_row && i % system.GetColumnNumber() == cur_column;
        // 左側の矢印を表示
        if (i % system.GetColumnNumber() == 0) {
            if (i / system.GetColumnNumber() == cur_row) {
                std::cout << "> ";
            } else {
                std::cout << "  ";
            }
        }
        // カーソルが指定している場所のとき色を変える
        if (is_target) {
            std::cout << "\e[32m";
        }
        // 空いていないとき
        if (system.IsOpen(i) == false) {
            // 旗が立っているとき
            if (system.IsFlagged(i) == true) {
                std::cout << "\e[45m";
                // カーソルが指定している場所のとき色を変える
                if (is_target) {
                    std::cout << "\e[32m";
                }
                std::cout << "P";
            } else {
                std::cout << "\e[46m";
                // カーソルが指定している場所のとき色を変える
                if (is_target) {
                    std::cout << "\e[42m\e[39m";
                }
                std::cout << "Q";
            }
        }
        // 爆弾のとき
        else if (system.GetCellData(i) == CellData::Mine) {
            std::cout << "\e[41m";
            std::cout << "x";
        }
        // 空白のとき
        else if (system.GetCellData(i) == CellData::_0) {
            std::cout << "_";
        }
        // 数字のとき
        else {
            std::cout << static_cast<int>(system.GetCellData(i));
        }
        // 区切り
        std::cout << "\e[0m";
        std::cout << " ";
        if ((i + 1) % system.GetColumnNumber() == 0) {
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

void MinesweeperCUI::DisplayRemainingMines() noexcept{
    std::cout << "Remaining mines : " << static_cast<int>(system.GetRemainingMines()) << std::endl;
}

bool MinesweeperCUI::IsSuccess() noexcept{
    return system.IsSuccess();
}
