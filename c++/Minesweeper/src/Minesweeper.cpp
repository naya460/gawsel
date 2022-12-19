#include <cstdint>
#include <vector>

class MinesweeperSys {
private:
    // 盤面の行数と列数
    std::uint8_t row;
    std::uint8_t column;

    // 盤面
    std::vector<bool> board;
public:
    MinesweeperSys(std::uint8_t row_number, std::uint8_t column_number){
        row = row_number;
        column = column_number;
        board.resize(row * column);
        for (auto v : board) {
            v = false;
        }
    }
};

int main(void){
    MinesweeperSys sys{9, 9};
    return 0;
}