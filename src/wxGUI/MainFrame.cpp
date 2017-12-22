#include "wxGUI/MainFrame.h"
#include <iostream>
#include <wx/msgdlg.h>

#include<wx/sizer.h>
#include <wx/string.h>
#include <wx/intl.h>

#include <wxGUI/LoginPanel.h>
#include <wxGUI/AUISplittedPanel.h>

const long MainFrame::idMenuQuit = wxNewId();
const long MainFrame::idMenuAbout = wxNewId();
const long MainFrame::ID_ONLYSBAR = wxNewId();


BEGIN_EVENT_TABLE(MainFrame,wxFrame)
END_EVENT_TABLE()

MainFrame::MainFrame(wxWindow* parent,wxWindowID id)
{
    //Its the constructor stupid
    Create(parent, id, wxEmptyString, wxDefaultPosition, 
            wxDefaultSize, wxDEFAULT_FRAME_STYLE, _T("id"));
    CreateMenu();
    CreateStatusBar();
    auto CenterFlag = wxALIGN_CENTER_VERTICAL|wxALIGN_CENTER_HORIZONTAL;

    wxFlexGridSizer* OutermostGridSizer = new wxFlexGridSizer(wxEXPAND);
    AUISplittedPanel* SplittedPanel= new AUISplittedPanel(this);
    OutermostGridSizer->Add(SplittedPanel,1,wxALL|CenterFlag,5);
    SetSizer(OutermostGridSizer);


    Connect(idMenuQuit,wxEVT_COMMAND_MENU_SELECTED,(wxObjectEventFunction)&MainFrame::OnQuit);
    Connect(idMenuAbout,wxEVT_COMMAND_MENU_SELECTED,(wxObjectEventFunction)&MainFrame::OnAbout);
}
void MainFrame::CreateMenu()
{

    wxMenuBar* OnlyMBar = new wxMenuBar();
    wxMenu* FileMenu = new wxMenu();
    wxMenuItem* QuitMItem = new wxMenuItem(FileMenu, idMenuQuit, _("Quit\tAlt-F4"), 
            _("Quit the application"), wxITEM_NORMAL);
    FileMenu->Append(QuitMItem);

    OnlyMBar->Append(FileMenu, _("&File"));
    // help Menu starts 
    wxMenu* HelpMenu = new wxMenu();
    wxMenuItem* AboutMItem= new wxMenuItem(HelpMenu, idMenuAbout, _("About\tF1"), 
            _("Show info about this application"), wxITEM_NORMAL);
    HelpMenu->Append(AboutMItem);
    OnlyMBar->Append(HelpMenu, _("Help"));
    SetMenuBar(OnlyMBar);
}

void MainFrame::CreateStatusBar()
{
    OnlySBar = new wxStatusBar(this, ID_ONLYSBAR, 0, _T("ID_ONLYSBAR"));
    int __wxStatusBarWidths_1[1] = { -1 };
    int __wxStatusBarStyles_1[1] = { wxSB_NORMAL };
    OnlySBar->SetFieldsCount(1,__wxStatusBarWidths_1);
    OnlySBar->SetStatusStyles(1,__wxStatusBarStyles_1);
    SetStatusBar(OnlySBar);
    OnlySBar->SetStatusText("Menu Created; App Initialized");
}

MainFrame::~MainFrame()
{

}

void MainFrame::OnQuit(wxCommandEvent& event)
{
    Close();
}

void MainFrame::OnAbout(wxCommandEvent& event)
{
    std::string msg = "Helo Build";
    wxMessageBox(msg, _("Welcome to..."));
}
