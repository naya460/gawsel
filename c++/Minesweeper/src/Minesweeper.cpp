#include "MinesweeperSys.hpp"

#include <iostream>

int main(void){
    MinesweeperSys sys{9, 9, 10};
    sys.Randam();

    for (int i = 0; i < 9 * 9; ++i) {
        // 爆弾のとき
        if (sys.GetCell(i).GetData() == CellData::Mine) {
            std::cout << "x";
        }
        // 空白のとき
        else if (sys.GetCell(i).GetData() == CellData::_0) {
            std::cout << "_";
        }
        // 数字のとき
        else {
            std::cout << static_cast<int>(sys.GetCell(i).GetData());
        }
        // 区切り
        std::cout << "  ";
        if (i % 9 == 8) {
            std::cout << std::endl;
        }
    }
    return 0;
}