#include "wxGUI/AUISplittedPanel.h"
#include "wxGUI/LoginPanel.h"

#include <wx/string.h>
#include <wx/intl.h>

const long AUISplittedPanel::ID_LeftAUINBook = wxNewId();
const long AUISplittedPanel::ID_CenterAUINBook = wxNewId();
const long AUISplittedPanel::ID_RightAUINBook = wxNewId();

BEGIN_EVENT_TABLE(AUISplittedPanel,wxPanel)
END_EVENT_TABLE()

AUISplittedPanel::AUISplittedPanel(wxWindow* parent,wxWindowID id,
        const wxPoint& pos,const wxSize& size)
{
    //Ctor
    //Create the Panel
	Create(parent, wxID_ANY, wxDefaultPosition, wxDefaultSize, 0, _T("wxID_ANY"));
	MainAUIManager = new wxAuiManager(this, wxAUI_MGR_DEFAULT);

	LeftAUINBook = new wxAuiNotebook(this, ID_LeftAUINBook, wxPoint(23,167),
           wxSize(200,-1), wxAUI_NB_DEFAULT_STYLE);
	LeftAUINBook->SetMinSize(wxSize(200,-1));
	MainAUIManager->AddPane(LeftAUINBook, wxAuiPaneInfo().Name(_T("LeftPane")).
            DefaultPane().CaptionVisible(false).CloseButton(false).
            Left().BestSize(wxSize(200,-1)).MinSize(wxSize(200,-1)));

	CenterAUINBook = new wxAuiNotebook(this, ID_CenterAUINBook, wxPoint(92,135),
            wxDefaultSize, wxAUI_NB_DEFAULT_STYLE);
	MainAUIManager->AddPane(CenterAUINBook, wxAuiPaneInfo().Name(_T("CenterPane")).
            DefaultPane().Caption(_("Pane caption")).CaptionVisible(false).
            CloseButton(false).Row(1).Center().Movable(false));

	RightAUINBook = new wxAuiNotebook(this, ID_RightAUINBook, wxPoint(272,5), 
            wxSize(200,-1), wxAUI_NB_DEFAULT_STYLE);
	RightAUINBook->SetMinSize(wxSize(200,-1));
	MainAUIManager->AddPane(RightAUINBook, wxAuiPaneInfo().Name(_T("RightPane")).
            DefaultPane().Caption(_("Pane caption")).CaptionVisible().Row(2).
            Right().BestSize(wxSize(200,-1)).MinSize(wxSize(200,-1)));
	MainAUIManager->Update();

    LoginPanel* LoginDummyPage = new LoginPanel(this);
    LoginPanel* NewLoginDummyPage = new LoginPanel(this);
    CenterAUINBook->AddPage(LoginDummyPage,_("Login Page"));
    CenterAUINBook->AddPage(NewLoginDummyPage,_("Login Page Two"));

	Connect(ID_CenterAUINBook,wxEVT_COMMAND_AUINOTEBOOK_PAGE_CLOSE,
            (wxObjectEventFunction)&AUISplittedPanel::OnCenterAUINBookPageClose);
}

AUISplittedPanel::~AUISplittedPanel()
{
}

void AUISplittedPanel::OnCenterAUINBookPageClose(wxAuiNotebookEvent& event)
{
}
