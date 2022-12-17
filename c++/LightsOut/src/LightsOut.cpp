#include <iostream>
#include <cstdint>
#include <vector>

class LightsOutSys {
private:
    std::uint8_t length = 0;
    std::vector<bool> board;
public:
    LightsOutSys(std::uint8_t length){
        this->length = length;

        board.resize(length * length);
        for (auto v : board) {
            v = 0;
        }
    }

    std::uint8_t get_length(){
        return length;
    }

    std::uint8_t get_size(){
        return length * length;
    }
};

int main(void){
    LightsOutSys sys(3);
    std::cout << static_cast<size_t>(sys.get_length()) << std::endl;
    std::cout << static_cast<size_t>(sys.get_size()) << std::endl;
    return 0;
}