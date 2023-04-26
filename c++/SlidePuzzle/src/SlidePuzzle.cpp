#include <iostream>

#include "SlidePuzzleSys.hpp"

int main(void) {
    SlidePuzzleSys sys;
    sys.move_number(11);
    sys.move_number(10);
    sys.move_number(14);
    sys.move_number(15);
    for (int i = 0; i < sys.get_size(); ++i) {
        printf("%2d ", sys.get_number(i));
        if ((i + 1) % sys.get_length() == 0) {
            putchar('\n');
        }
    }
    return 0;
}