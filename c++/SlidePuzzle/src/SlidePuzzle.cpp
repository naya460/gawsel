#include <iostream>

#include "SlidePuzzleSys.hpp"

int main(void) {
    SlidePuzzleSys sys;
    for (int i = 0; i < sys.get_size(); ++i) {
        printf("%2d ", sys.get_number(i));
        if ((i + 1) % sys.get_length() == 0) {
            putchar('\n');
        }
    }
    return 0;
}