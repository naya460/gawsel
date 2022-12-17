#include "LightsOutWxWidgets.hpp"

bool LightsOutApp::OnInit(){
    wxFrame *frame = new wxFrame(NULL, wxID_ANY, wxT("Lights Out"));
    frame->Show();
    return true;
}