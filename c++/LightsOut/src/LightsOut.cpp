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

#ifdef WX_WIDGETS
#include "LightsOutWxWidgets.hpp"

IMPLEMENT_APP(LightsOutApp)

#endif // WX_WIDGETS