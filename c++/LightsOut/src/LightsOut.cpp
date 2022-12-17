#include <iostream>

#include "LightsOutSys.hpp"

int main(void){
    LightsOutSys sys(3);
    for (int i = 0; i < sys.get_size(); ++i) {
        std::cout << sys.is_on(i) << " ";
        if ((i + 1) % sys.get_length() == 0) {
            std::cout << std::endl;
        }
    }
    return 0;
}