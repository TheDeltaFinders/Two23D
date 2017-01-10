#include "wxGUI/Two23DApp.h"

#include "wxGUI/MainFrame.h"

#include <wx/image.h>


IMPLEMENT_APP(Two23DApp);

bool Two23DApp::OnInit()
{
    bool wxsOK = true;
    wxInitAllImageHandlers();
    if ( wxsOK )
    {
    	MainFrame* Frame = new MainFrame(0);
    	Frame->Show();
    	SetTopWindow(Frame);
    }
    return wxsOK;
}
