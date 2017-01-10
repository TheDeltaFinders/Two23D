#include "wxGUI/LoginPanel.h"

#include <wx/string.h>
#include <wx/intl.h>
#include <wx/sizer.h>
#include <wx/gbsizer.h>

BEGIN_EVENT_TABLE(LoginPanel,wxPanel)
	//
END_EVENT_TABLE()
const long LoginPanel::ID_ENTERBUTTON= wxNewId();
const long LoginPanel::ID_BUTTON2 = wxNewId();
const long LoginPanel::ID_LEDPANEL1 = wxNewId();


LoginPanel::LoginPanel(wxWindow* parent,wxWindowID id)
{
	Create(parent, id, wxDefaultPosition, wxDefaultSize, wxTAB_TRAVERSAL, _T("id"));

	wxStaticBoxSizer* OutermostSBSizer= new wxStaticBoxSizer(wxVERTICAL|wxEXPAND, this, _("Hello World"));

	EnterButton = new wxButton(this, ID_ENTERBUTTON, _("Press"), 
            wxDefaultPosition, wxDefaultSize, 0, wxDefaultValidator, _T("ID_ENTERBUTTON"));

    OutermostSBSizer->Add(EnterButton);
    OutermostSBSizer->Add(EnterButton);

	SetSizer(OutermostSBSizer);
	Layout();
}

LoginPanel::~LoginPanel()
{
}


