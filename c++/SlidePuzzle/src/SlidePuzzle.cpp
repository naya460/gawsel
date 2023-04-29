#include <iostream>

#include "SlidePuzzleSys.hpp"

int main(void) {
    SlidePuzzleSys sys;
    sys.move_number(3);
    sys.move_number(0);
    sys.move_number(12);
    sys.move_number(15);
    for (int i = 0; i < sys.get_size(); ++i) {
        printf("%2d ", sys.get_number(i));
        if ((i + 1) % sys.get_length() == 0) {
            putchar('\n');
        }
    }
    return 0;
}