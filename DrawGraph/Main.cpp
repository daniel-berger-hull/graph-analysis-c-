#include "Main.h"


wxBEGIN_EVENT_TABLE(MyFrame, wxFrame)
	EVT_MENU(ID_Hello, MyFrame::OnHello)
	EVT_MENU(wxID_EXIT, MyFrame::OnExit)
	EVT_MENU(wxID_ABOUT, MyFrame::OnAbout)
wxEND_EVENT_TABLE()

wxIMPLEMENT_APP(MyApp);


bool MyApp::OnInit()
{
	MyFrame* frame = new MyFrame("Drawing Graph", wxPoint(50, 50), wxSize(SCREEN_WIDTH, SCREEN_HEIGHT));
    frame->Show(true);
    return true;
}


MyFrame::MyFrame(const wxString& title, const wxPoint& pos, const wxSize& size)
    : wxFrame(NULL, wxID_ANY, title, pos, size)
{
	buildMenuBar();	
	buildDrawPanel(this);

	SetStatusText("Drawing Graph!");  
}


wxMenuBar* MyFrame::buildMenuBar()
{
	wxMenu* menuFile = new wxMenu;
	menuFile->Append(ID_Hello, "&Hello...\tCtrl-H",
		"Help string shown in status bar for this menu item");
	menuFile->AppendSeparator();
	menuFile->Append(wxID_EXIT);
	wxMenu* menuHelp = new wxMenu;
	menuHelp->Append(wxID_ABOUT);
	wxMenuBar* menuBar = new wxMenuBar;
	menuBar->Append(menuFile, "&File");
	menuBar->Append(menuHelp, "&Help");
	SetMenuBar(menuBar);
	CreateStatusBar();
	SetStatusText("Welcome to wxWidgets!");

	return menuBar;
}


BasicDrawPane* MyFrame::buildDrawPanel(wxFrame* parent)
{
	drawBox = new BasicDrawPane(parent);
	drawBox->SetSize({ 300,200 });

	wxBoxSizer* sizer = new wxBoxSizer(wxVERTICAL);
	sizer->Add(drawBox, 1, wxEXPAND);

	parent->SetSizer(sizer);
	parent->SetAutoLayout(true);

	return drawBox;
}


void MyFrame::OnExit(wxCommandEvent& event)
{
    Close(true);
}

void MyFrame::OnAbout(wxCommandEvent& event)
{
    wxMessageBox("This is a wxWidgets' Hello world sample",
        "About Hello World", wxOK | wxICON_INFORMATION);
}
void MyFrame::OnHello(wxCommandEvent& event)
{
    wxLogMessage("Hello world from wxWidgets!");
}