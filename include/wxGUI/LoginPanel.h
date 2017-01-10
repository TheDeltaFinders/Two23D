#ifndef LOGINPANEL_H
#define LOGINPANEL_H

#include <wx/panel.h>
#include <wx/button.h>

class LoginPanel :public wxPanel
{
    public:

		LoginPanel(wxWindow* parent,wxWindowID id=wxID_ANY);
		virtual ~LoginPanel();
        static const long ID_ENTERBUTTON;
        static const long ID_BUTTON2;
        static const long ID_LEDPANEL1;

        wxPanel* Panel1;
        wxButton* EnterButton;
        wxButton* Button2;

	protected:

	private:

		DECLARE_EVENT_TABLE()
};

#endif // LOGINPANEL_H
