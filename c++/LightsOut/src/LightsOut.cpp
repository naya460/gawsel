#include <iostream>
#include <cstdint>
#include <vector>

class LightsOutSys {
private:
    std::uint8_t length = 0;
    std::uint16_t size = 0;
    std::vector<bool> board;

    void invert(std::uint16_t pos){
        if (pos >= get_size()) {
            throw false;
        }
        board[pos] = ~board[pos];
    }

    void invert(std::uint8_t row, std::uint8_t column){
        invert(column * length + row);
    }
public:
    LightsOutSys(std::uint8_t length){
        this->length = length;
        this->size = length * length;

        board.resize(size);
        for (auto v : board) {
            v = 0;
        }
    }

    std::uint8_t get_length() noexcept{
        return length;
    }

    std::uint16_t get_size() noexcept{
        return length * length;
    }

    bool is_on(std::uint16_t pos){
        if (pos >= get_size()) {
            throw false;
        }
        return board[pos];
    }

    bool is_on(std::uint8_t row, std::uint8_t column){
        return is_on(column * length + row);
    }

    void push(std::uint16_t pos){
        push(pos % length, pos / length);
    }

    void push(std::uint8_t row, std::uint8_t column){
        invert(row, column);
        if (row > 0) invert(row - 1, column);
        if (row < length - 1) invert(row + 1, column);
        if (column > 0) invert(row, column - 1);
        if (column < length - 1) invert(row, column + 1);
    }
};

int main(void){
    LightsOutSys sys(3);
    sys.push(1, 1);
    for (int i = 0; i < sys.get_size(); ++i) {
        std::cout << sys.is_on(i) << " ";
        if ((i + 1) % sys.get_length() == 0) {
            std::cout << std::endl;
        }
    }
    return 0;
}