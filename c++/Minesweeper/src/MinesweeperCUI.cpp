#include "MinesweeperCUI.hpp"

#include <iostream>

void MinesweeperCUI::Run() noexcept{
    NewGame(9, 9, 10);

    // メインループ
    while (true) {
        // 出力
        Display();

        // 開ける場所を入力
        int row, column;
        std::cout << "row : ";
        std::cin >> row;
        std::cout << "column : ";
        std::cin >> column;

        // 開ける
        system.Open(row, column);
    }
}

// 新しい盤面で開始
void MinesweeperCUI::NewGame(std::uint8_t row_number, std::uint8_t column_number, std::uint16_t mine) noexcept{
    system.SetSizeAndMine(row_number, column_number, mine);
}

// 盤面を表示
void MinesweeperCUI::Display() noexcept{
    for (int i = 0; i < 9 * 9; ++i) {
        // 空いていないとき
        if (system.GetCell(i).IsOpen() == false) {
            std::cout << "Q";
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