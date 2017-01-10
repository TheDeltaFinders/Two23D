#ifndef NEWPANEL_H
#define NEWPANEL_H

#include <wx/panel.h>
#include <wx/aui/aui.h>

class AUISplittedPanel: public wxPanel
{
    public:

        AUISplittedPanel(wxWindow* parent,wxWindowID id=wxID_ANY,
                const wxPoint& pos=wxDefaultPosition,const wxSize& size=wxDefaultSize);
        virtual ~AUISplittedPanel();

        wxAuiNotebook* RightAUINBook;
        wxAuiNotebook* CenterAUINBook;
        wxAuiNotebook* LeftAUINBook;
        wxAuiManager* MainAUIManager;

    protected:

        static const long ID_LeftAUINBook;
        static const long ID_CenterAUINBook;
        static const long ID_RightAUINBook;

    private:

        void OnCenterAUINBookPageClose(wxAuiNotebookEvent& event);

        DECLARE_EVENT_TABLE()
};

#endif
