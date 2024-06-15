///////////////////////////////////////////////////////////////////////////
// C++ code generated with wxFormBuilder (version 4.1.0-0-g733bf3d)
// http://www.wxformbuilder.org/
//
// PLEASE DO *NOT* EDIT THIS FILE!
///////////////////////////////////////////////////////////////////////////

#pragma once

#include <wx/artprov.h>
#include <wx/xrc/xmlres.h>
#include <wx/panel.h>
#include <wx/gdicmn.h>
#include <wx/font.h>
#include <wx/colour.h>
#include <wx/settings.h>
#include <wx/string.h>
#include <wx/stattext.h>
#include <wx/button.h>
#include <wx/bitmap.h>
#include <wx/image.h>
#include <wx/icon.h>
#include <wx/sizer.h>
#include <wx/textctrl.h>
#include <wx/radiobut.h>
#include <wx/frame.h>
#include <wx/wxprec.h>
#include <wx/colordlg.h>
#include <wx/dcbuffer.h>
#include <wx/filefn.h> 

///////////////////////////////////////////////////////////////////////////


///////////////////////////////////////////////////////////////////////////////
/// Class MyFrame1
///////////////////////////////////////////////////////////////////////////////
class MyFrame1 : public wxFrame
{
private:

protected:
	wxPanel* panelNaWykres;
	wxStaticText* textTytul;
	wxStaticText* textFunkcja;
	wxButton* buttonInfo;
	wxTextCtrl* textCtrlFunkcja;
	wxStaticText* textX;
	wxStaticText* textXMin;
	wxTextCtrl* textCtrlXMin;
	wxStaticText* textXMax;
	wxTextCtrl* textCtrlXMax;
	wxStaticText* textY;
	wxStaticText* textYMin;
	wxTextCtrl* textCtrlYMin;
	wxStaticText* textYMax;
	wxTextCtrl* textCtrlYMax;
	wxStaticText* textZ;
	wxStaticText* textZMin;
	wxTextCtrl* textCtrlZMin;
	wxStaticText* textZMax;
	wxTextCtrl* textCtrlZMax;
	wxRadioButton* radioRzut;
	wxRadioButton* radioMapa;
	wxButton* buttonPrint;
	wxButton* buttonSave;
	wxButton* buttonGenerate;

	// Virtual event handlers, override them in your derived class
	virtual void showInfo(wxMouseEvent& event) { event.Skip(); }
	virtual void perspectiveClick(wxMouseEvent& event) { event.Skip(); }
	virtual void outlineClick(wxMouseEvent& event) { event.Skip(); }
	virtual void printClick(wxMouseEvent& event) { event.Skip(); }
	virtual void saveClick(wxMouseEvent& event) { event.Skip(); }
	virtual void generateClick(wxMouseEvent& event) { event.Skip(); }

	virtual void panelRepaint(wxSizeEvent& event) { event.Skip(); }

	virtual void onMouseEnter(wxMouseEvent& event) { event.Skip(); }
	virtual void onMouseMove(wxMouseEvent& event) { event.Skip(); }
	virtual void onMouseLeave(wxMouseEvent& event) { event.Skip(); }
	virtual void onLeftMouseDown(wxMouseEvent& event) { event.Skip(); }
	virtual void onLeftMouseUp(wxMouseEvent& event) { event.Skip(); }


public:

	MyFrame1(wxWindow* parent, wxWindowID id = wxID_ANY, const wxString& title = wxT("plots 3D"), const wxPoint& pos = wxDefaultPosition, const wxSize& size = wxSize(1000, 700), long style = wxDEFAULT_FRAME_STYLE | wxTAB_TRAVERSAL);

	~MyFrame1();

};

