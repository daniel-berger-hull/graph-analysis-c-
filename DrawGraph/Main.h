#pragma once

#include <wx/wxprec.h>
#ifndef WX_PRECOMP
#include <wx/wx.h>
#endif

#include "BasicDrawPane.h"

#define SCREEN_WIDTH  600
#define SCREEN_HEIGHT 400


class MyApp : public wxApp
{
public:
	virtual bool OnInit();

};



class MyFrame : public wxFrame
{
public:
	MyFrame(const wxString& title, const wxPoint& pos, const wxSize& size);

	BasicDrawPane* drawBox = NULL;    // Should  this one not a private field?

private:

	wxMenuBar* buildMenuBar();
	BasicDrawPane* buildDrawPanel(wxFrame* parent);

	void OnHello(wxCommandEvent& event);
	void OnExit(wxCommandEvent& event);
	void OnAbout(wxCommandEvent& event);
	wxDECLARE_EVENT_TABLE();
};
enum
{
	ID_Hello = 1
};
