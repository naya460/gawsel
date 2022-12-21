#include "MinesweeperSys.hpp"

#include <iostream>

int main(void){
    MinesweeperSys sys{9, 9, 10};
    sys.Randam();

    for (int i = 0; i < 9 * 9; ++i) {
        std::cout << static_cast<int>(sys.GetCell(i).GetData()) << "\t";
        if (i % 9 == 8) {
            std::cout << std::endl;
        }
    }
    return 0;
}