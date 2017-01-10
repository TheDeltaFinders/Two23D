#ifndef TWO23DMAIN_H
#define TWO23DMAIN_H

#include <wx/menu.h>
#include <wx/statusbr.h>
#include <wx/frame.h>


class MainFrame: public wxFrame
{
    public:
        MainFrame(wxWindow* parent,wxWindowID id = -1);
        virtual ~MainFrame();

    private:
        void OnQuit(wxCommandEvent& event);
        void OnAbout(wxCommandEvent& event);

        static const long idMenuQuit;
        static const long idMenuAbout;
        static const long ID_ONLYSBAR;

        wxStatusBar* OnlySBar;
        void CreateMenu();
        void CreateStatusBar();

        DECLARE_EVENT_TABLE()
};
#endif // TWO23DMAIN_H
