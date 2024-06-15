///////////////////////////////////////////////////////////////////////////
// C++ code generated with wxFormBuilder (version 4.1.0-0-g733bf3d)
// http://www.wxformbuilder.org/
//
// PLEASE DO *NOT* EDIT THIS FILE!
///////////////////////////////////////////////////////////////////////////

#include "GUI.h"

///////////////////////////////////////////////////////////////////////////

MyFrame1::MyFrame1(wxWindow* parent, wxWindowID id, const wxString& title, const wxPoint& pos, const wxSize& size, long style) : wxFrame(parent, id, title, pos, size, style)
{
	this->SetSizeHints(wxDefaultSize, wxDefaultSize);

	wxBoxSizer* sizerPodzialOkna;
	sizerPodzialOkna = new wxBoxSizer(wxHORIZONTAL);

	panelNaWykres = new wxPanel(this, wxID_ANY, wxDefaultPosition, wxSize(700, 700), wxTAB_TRAVERSAL);
	panelNaWykres->SetBackgroundColour(wxSystemSettings::GetColour(wxSYS_COLOUR_MENU));

	//ruch mysza
	panelNaWykres->Bind(wxEVT_ENTER_WINDOW, &MyFrame1::onMouseEnter, this);
	panelNaWykres->Bind(wxEVT_MOTION, &MyFrame1::onMouseMove, this);
	panelNaWykres->Bind(wxEVT_LEAVE_WINDOW, &MyFrame1::onMouseLeave, this);
	panelNaWykres->Bind(wxEVT_LEFT_DOWN, &MyFrame1::onLeftMouseDown, this);
	panelNaWykres->Bind(wxEVT_LEFT_UP, &MyFrame1::onLeftMouseUp, this);

	sizerPodzialOkna->Add(panelNaWykres, 1, wxEXPAND | wxALL, 5);

	wxBoxSizer* sizerMenu;
	sizerMenu = new wxBoxSizer(wxVERTICAL);

	textTytul = new wxStaticText(this, wxID_ANY, wxT("plots 3D"), wxDefaultPosition, wxDefaultSize, wxALIGN_CENTER_HORIZONTAL);
	textTytul->Wrap(-1);
	textTytul->SetFont(wxFont(28, wxFONTFAMILY_DECORATIVE, wxFONTSTYLE_NORMAL, wxFONTWEIGHT_NORMAL, false, wxT("Showcard Gothic")));
	textTytul->SetForegroundColour(wxColour(255, 255, 255));

	sizerMenu->Add(textTytul, 0, wxALL | wxALIGN_CENTER_HORIZONTAL, 25);

	wxBoxSizer* sizerFunkcja;
	sizerFunkcja = new wxBoxSizer(wxHORIZONTAL);

	textFunkcja = new wxStaticText(this, wxID_ANY, wxT("function"), wxPoint(-1, -1), wxDefaultSize, wxALIGN_CENTER_HORIZONTAL);
	textFunkcja->Wrap(-1);
	textFunkcja->SetFont(wxFont(16, wxFONTFAMILY_DECORATIVE, wxFONTSTYLE_NORMAL, wxFONTWEIGHT_NORMAL, false, wxT("Showcard Gothic")));
	textFunkcja->SetForegroundColour(wxColour(255, 255, 255));

	sizerFunkcja->Add(textFunkcja, 0, wxALIGN_CENTER_VERTICAL | wxALL, 5);

	buttonInfo = new wxButton(this, wxID_ANY, wxT("?"), wxDefaultPosition, wxSize(20, 20), 0);
	buttonInfo->SetLabelMarkup(wxT("?"));
	buttonInfo->SetFont(wxFont(10, wxFONTFAMILY_DECORATIVE, wxFONTSTYLE_NORMAL, wxFONTWEIGHT_NORMAL, false, wxT("Showcard Gothic")));
	buttonInfo->SetForegroundColour(wxColour(255, 0, 0));
	buttonInfo->SetBackgroundColour(wxColour(255, 255, 255));

	sizerFunkcja->Add(buttonInfo, 0, wxALL, 5);


	sizerMenu->Add(sizerFunkcja, 1, wxALIGN_CENTER_HORIZONTAL | wxALL, 5);

	textCtrlFunkcja = new wxTextCtrl(this, wxID_ANY, wxT("x^2 + y^2"), wxDefaultPosition, wxSize(260, 30), wxTE_AUTO_URL | wxTE_CENTER | wxTE_PROCESS_ENTER);
	textCtrlFunkcja->SetFont(wxFont(12, wxFONTFAMILY_SWISS, wxFONTSTYLE_NORMAL, wxFONTWEIGHT_NORMAL, false, wxT("@Arial Unicode MS")));

	sizerMenu->Add(textCtrlFunkcja, 0, wxALIGN_CENTER_HORIZONTAL | wxALL, 5);

	textX = new wxStaticText(this, wxID_ANY, wxT("x axis"), wxPoint(-1, -1), wxSize(-1, -1), wxALIGN_CENTER_HORIZONTAL);
	textX->Wrap(-1);
	textX->SetFont(wxFont(16, wxFONTFAMILY_DECORATIVE, wxFONTSTYLE_NORMAL, wxFONTWEIGHT_NORMAL, false, wxT("Showcard Gothic")));
	textX->SetForegroundColour(wxColour(255, 255, 255));

	sizerMenu->Add(textX, 0, wxALIGN_CENTER_HORIZONTAL | wxALL, 5);

	wxBoxSizer* sizerX;
	sizerX = new wxBoxSizer(wxHORIZONTAL);

	textXMin = new wxStaticText(this, wxID_ANY, wxT("min"), wxDefaultPosition, wxDefaultSize, wxALIGN_CENTER_HORIZONTAL);
	textXMin->Wrap(-1);
	textXMin->SetFont(wxFont(12, wxFONTFAMILY_DECORATIVE, wxFONTSTYLE_NORMAL, wxFONTWEIGHT_NORMAL, false, wxT("Showcard Gothic")));
	textXMin->SetForegroundColour(wxColour(255, 255, 255));

	sizerX->Add(textXMin, 0, wxALL, 5);

	textCtrlXMin = new wxTextCtrl(this, wxID_ANY, wxT("-10"), wxDefaultPosition, wxSize(50, -1), wxTE_AUTO_URL | wxTE_CENTER | wxTE_PROCESS_ENTER);
	textCtrlXMin->SetFont(wxFont(9, wxFONTFAMILY_SWISS, wxFONTSTYLE_NORMAL, wxFONTWEIGHT_NORMAL, false, wxT("@Arial Unicode MS")));
	textCtrlXMin->SetMinSize(wxSize(70, -1));

	sizerX->Add(textCtrlXMin, 0, wxALL, 5);

	textXMax = new wxStaticText(this, wxID_ANY, wxT("max"), wxDefaultPosition, wxDefaultSize, 0);
	textXMax->Wrap(-1);
	textXMax->SetFont(wxFont(12, wxFONTFAMILY_DECORATIVE, wxFONTSTYLE_NORMAL, wxFONTWEIGHT_NORMAL, false, wxT("Showcard Gothic")));
	textXMax->SetForegroundColour(wxColour(255, 255, 255));

	sizerX->Add(textXMax, 0, wxALL, 5);

	textCtrlXMax = new wxTextCtrl(this, wxID_ANY, wxT("10"), wxDefaultPosition, wxDefaultSize, wxTE_AUTO_URL | wxTE_CENTER | wxTE_PROCESS_ENTER);
	textCtrlXMax->SetFont(wxFont(9, wxFONTFAMILY_SWISS, wxFONTSTYLE_NORMAL, wxFONTWEIGHT_NORMAL, false, wxT("@Arial Unicode MS")));
	textCtrlXMax->SetMinSize(wxSize(70, -1));

	sizerX->Add(textCtrlXMax, 0, wxALL, 5);


	sizerMenu->Add(sizerX, 1, wxALIGN_CENTER_HORIZONTAL, 5);

	textY = new wxStaticText(this, wxID_ANY, wxT("y axis"), wxPoint(-1, -1), wxSize(-1, -1), wxALIGN_CENTER_HORIZONTAL);
	textY->Wrap(-1);
	textY->SetFont(wxFont(16, wxFONTFAMILY_DECORATIVE, wxFONTSTYLE_NORMAL, wxFONTWEIGHT_NORMAL, false, wxT("Showcard Gothic")));
	textY->SetForegroundColour(wxColour(255, 255, 255));

	sizerMenu->Add(textY, 0, wxALIGN_CENTER_HORIZONTAL | wxALL, 5);

	wxBoxSizer* sizerY;
	sizerY = new wxBoxSizer(wxHORIZONTAL);

	textYMin = new wxStaticText(this, wxID_ANY, wxT("min"), wxDefaultPosition, wxDefaultSize, 0);
	textYMin->Wrap(-1);
	textYMin->SetFont(wxFont(12, wxFONTFAMILY_DECORATIVE, wxFONTSTYLE_NORMAL, wxFONTWEIGHT_NORMAL, false, wxT("Showcard Gothic")));
	textYMin->SetForegroundColour(wxColour(255, 255, 255));

	sizerY->Add(textYMin, 0, wxALL, 5);

	textCtrlYMin = new wxTextCtrl(this, wxID_ANY, wxT("-10"), wxDefaultPosition, wxSize(50, -1), wxTE_AUTO_URL | wxTE_CENTER | wxTE_PROCESS_ENTER);
	textCtrlYMin->SetFont(wxFont(9, wxFONTFAMILY_SWISS, wxFONTSTYLE_NORMAL, wxFONTWEIGHT_NORMAL, false, wxT("@Arial Unicode MS")));
	textCtrlYMin->SetMinSize(wxSize(70, -1));

	sizerY->Add(textCtrlYMin, 0, wxALL, 5);

	textYMax = new wxStaticText(this, wxID_ANY, wxT("max"), wxDefaultPosition, wxDefaultSize, 0);
	textYMax->Wrap(-1);
	textYMax->SetFont(wxFont(12, wxFONTFAMILY_DECORATIVE, wxFONTSTYLE_NORMAL, wxFONTWEIGHT_NORMAL, false, wxT("Showcard Gothic")));
	textYMax->SetForegroundColour(wxColour(255, 255, 255));

	sizerY->Add(textYMax, 0, wxALL, 5);

	textCtrlYMax = new wxTextCtrl(this, wxID_ANY, wxT("10"), wxDefaultPosition, wxDefaultSize, wxTE_AUTO_URL | wxTE_CENTER | wxTE_PROCESS_ENTER);
	textCtrlYMax->SetFont(wxFont(9, wxFONTFAMILY_SWISS, wxFONTSTYLE_NORMAL, wxFONTWEIGHT_NORMAL, false, wxT("@Arial Unicode MS")));
	textCtrlYMax->SetMinSize(wxSize(70, -1));

	sizerY->Add(textCtrlYMax, 0, wxALL, 5);


	sizerMenu->Add(sizerY, 1, wxALIGN_CENTER_HORIZONTAL, 5);

	textZ = new wxStaticText(this, wxID_ANY, wxT("z axis"), wxPoint(-1, -1), wxSize(-1, -1), wxALIGN_CENTER_HORIZONTAL);
	textZ->Wrap(-1);
	textZ->SetFont(wxFont(16, wxFONTFAMILY_DECORATIVE, wxFONTSTYLE_NORMAL, wxFONTWEIGHT_NORMAL, false, wxT("Showcard Gothic")));
	textZ->SetForegroundColour(wxColour(255, 255, 255));

	sizerMenu->Add(textZ, 0, wxALIGN_CENTER_HORIZONTAL | wxALL, 5);

	wxBoxSizer* sizerZ;
	sizerZ = new wxBoxSizer(wxHORIZONTAL);

	textZMin = new wxStaticText(this, wxID_ANY, wxT("min"), wxDefaultPosition, wxDefaultSize, 0);
	textZMin->Wrap(-1);
	textZMin->SetFont(wxFont(12, wxFONTFAMILY_DECORATIVE, wxFONTSTYLE_NORMAL, wxFONTWEIGHT_NORMAL, false, wxT("Showcard Gothic")));
	textZMin->SetForegroundColour(wxColour(255, 255, 255));

	sizerZ->Add(textZMin, 0, wxALL, 5);

	textCtrlZMin = new wxTextCtrl(this, wxID_ANY, wxT("-10"), wxDefaultPosition, wxSize(50, -1), wxTE_AUTO_URL | wxTE_CENTER | wxTE_PROCESS_ENTER);
	textCtrlZMin->SetFont(wxFont(9, wxFONTFAMILY_SWISS, wxFONTSTYLE_NORMAL, wxFONTWEIGHT_NORMAL, false, wxT("@Arial Unicode MS")));
	textCtrlZMin->SetMinSize(wxSize(70, -1));

	sizerZ->Add(textCtrlZMin, 0, wxALL, 5);

	textZMax = new wxStaticText(this, wxID_ANY, wxT("max"), wxDefaultPosition, wxDefaultSize, 0);
	textZMax->Wrap(-1);
	textZMax->SetFont(wxFont(12, wxFONTFAMILY_DECORATIVE, wxFONTSTYLE_NORMAL, wxFONTWEIGHT_NORMAL, false, wxT("Showcard Gothic")));
	textZMax->SetForegroundColour(wxColour(255, 255, 255));

	sizerZ->Add(textZMax, 0, wxALL, 5);

	textCtrlZMax = new wxTextCtrl(this, wxID_ANY, wxT("10"), wxDefaultPosition, wxDefaultSize, wxTE_AUTO_URL | wxTE_CENTER | wxTE_PROCESS_ENTER);
	textCtrlZMax->SetFont(wxFont(9, wxFONTFAMILY_SWISS, wxFONTSTYLE_NORMAL, wxFONTWEIGHT_NORMAL, false, wxT("@Arial Unicode MS")));
	textCtrlZMax->SetMinSize(wxSize(70, -1));

	sizerZ->Add(textCtrlZMax, 0, wxALL, 5);


	sizerMenu->Add(sizerZ, 1, wxALIGN_CENTER_HORIZONTAL, 5);

	radioRzut = new wxRadioButton(this, wxID_ANY, wxT("perspective view "), wxDefaultPosition, wxSize(-1, -1), 0);
	radioRzut->SetValue(true);
	radioRzut->SetFont(wxFont(12, wxFONTFAMILY_DECORATIVE, wxFONTSTYLE_NORMAL, wxFONTWEIGHT_NORMAL, false, wxT("Showcard Gothic")));
	radioRzut->SetForegroundColour(wxColour(255, 255, 255));

	sizerMenu->Add(radioRzut, 0, wxALIGN_CENTER_HORIZONTAL | wxALL, 5);

	radioMapa = new wxRadioButton(this, wxID_ANY, wxT("outline map "), wxDefaultPosition, wxSize(-1, -1), 0);
	radioMapa->SetFont(wxFont(12, wxFONTFAMILY_DECORATIVE, wxFONTSTYLE_NORMAL, wxFONTWEIGHT_NORMAL, false, wxT("Showcard Gothic")));
	radioMapa->SetForegroundColour(wxColour(255, 255, 255));

	sizerMenu->Add(radioMapa, 0, wxALIGN_CENTER_HORIZONTAL | wxALL, 5);

	wxBoxSizer* sizerButtons;
	sizerButtons = new wxBoxSizer(wxHORIZONTAL);

	buttonPrint = new wxButton(this, wxID_ANY, wxT("Print"), wxDefaultPosition, wxSize(100, 40), 0);
	buttonPrint->SetLabelMarkup(wxT("Print"));
	buttonPrint->SetFont(wxFont(14, wxFONTFAMILY_DECORATIVE, wxFONTSTYLE_NORMAL, wxFONTWEIGHT_NORMAL, false, wxT("Showcard Gothic")));
	buttonPrint->SetForegroundColour(wxColour(255, 128, 0));
	buttonPrint->SetBackgroundColour(wxColour(255, 255, 255));

	sizerButtons->Add(buttonPrint, 0, wxALL | wxALIGN_CENTER_VERTICAL, 10);

	buttonSave = new wxButton(this, wxID_ANY, wxT("Save"), wxDefaultPosition, wxSize(100, 40), 0);
	buttonSave->SetLabelMarkup(wxT("Save"));
	buttonSave->SetFont(wxFont(14, wxFONTFAMILY_DECORATIVE, wxFONTSTYLE_NORMAL, wxFONTWEIGHT_NORMAL, false, wxT("Showcard Gothic")));
	buttonSave->SetForegroundColour(wxColour(255, 128, 0));
	buttonSave->SetBackgroundColour(wxColour(255, 255, 255));

	sizerButtons->Add(buttonSave, 0, wxALL, 10);


	sizerMenu->Add(sizerButtons, 1, wxALIGN_CENTER_HORIZONTAL, 5);

	buttonGenerate = new wxButton(this, wxID_ANY, wxT("Generate"), wxDefaultPosition, wxSize(220, 60), 0);
	buttonGenerate->SetLabelMarkup(wxT("Generate"));
	buttonGenerate->SetFont(wxFont(24, wxFONTFAMILY_DECORATIVE, wxFONTSTYLE_NORMAL, wxFONTWEIGHT_NORMAL, false, wxT("Showcard Gothic")));
	buttonGenerate->SetForegroundColour(wxColour(0, 128, 255));
	buttonGenerate->SetBackgroundColour(wxColour(255, 255, 255));

	sizerMenu->Add(buttonGenerate, 0, wxALIGN_CENTER_HORIZONTAL | wxALL, 10);


	sizerPodzialOkna->Add(sizerMenu, 1, wxALIGN_CENTER_VERTICAL, 5);


	this->SetSizer(sizerPodzialOkna);
	this->Layout();

	this->Centre(wxBOTH);

	// Connect Events
	buttonInfo->Connect(wxEVT_COMMAND_BUTTON_CLICKED, wxMouseEventHandler(MyFrame1::showInfo), NULL, this);
	radioRzut->Connect(wxEVT_RADIOBUTTON, wxMouseEventHandler(MyFrame1::perspectiveClick), NULL, this);
	radioMapa->Connect(wxEVT_RADIOBUTTON, wxMouseEventHandler(MyFrame1::outlineClick), NULL, this);
	buttonPrint->Connect(wxEVT_COMMAND_BUTTON_CLICKED, wxMouseEventHandler(MyFrame1::printClick), NULL, this);
	buttonSave->Connect(wxEVT_COMMAND_BUTTON_CLICKED, wxMouseEventHandler(MyFrame1::saveClick), NULL, this);
	buttonGenerate->Connect(wxEVT_COMMAND_BUTTON_CLICKED, wxMouseEventHandler(MyFrame1::generateClick), NULL, this);

	panelNaWykres->Connect(wxEVT_UPDATE_UI, wxSizeEventHandler(MyFrame1::panelRepaint), NULL, this);
}

MyFrame1::~MyFrame1()
{
	// Disconnect Events
	buttonInfo->Disconnect(wxEVT_COMMAND_BUTTON_CLICKED, wxMouseEventHandler(MyFrame1::showInfo), NULL, this);
	radioRzut->Disconnect(wxEVT_RADIOBUTTON, wxMouseEventHandler(MyFrame1::perspectiveClick), NULL, this);
	radioMapa->Disconnect(wxEVT_RADIOBUTTON, wxMouseEventHandler(MyFrame1::outlineClick), NULL, this);
	buttonPrint->Disconnect(wxEVT_COMMAND_BUTTON_CLICKED, wxMouseEventHandler(MyFrame1::printClick), NULL, this);
	buttonSave->Disconnect(wxEVT_COMMAND_BUTTON_CLICKED, wxMouseEventHandler(MyFrame1::saveClick), NULL, this);
	buttonGenerate->Disconnect(wxEVT_COMMAND_BUTTON_CLICKED, wxMouseEventHandler(MyFrame1::generateClick), NULL, this);

	panelNaWykres->Connect(wxEVT_UPDATE_UI, wxSizeEventHandler(MyFrame1::panelRepaint), NULL, this);

}
