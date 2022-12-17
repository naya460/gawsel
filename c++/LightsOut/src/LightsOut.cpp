#include <iostream>
#include <cstdint>

#ifdef CUI

#include "LightsOutCUI.hpp"

int main(void){
    LightsOutCUI cui;
    cui.Run();
    return 0;
}

#endif // CUI