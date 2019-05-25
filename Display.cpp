#include "pch.h"
#include "Display.h"


Display::Display(): currentView_(&views[0]), nextView_(&views[1])
{
}


Display::~Display()
{
}

/*
I need to give this method a bunch of data which gives:
the coordinates of the upper left corner and the width and the height of the object to draw
*/
void Display::WriteNextDisplay(const std::string& input) {
	nextView_->writeBuffer(input);
}
void Display::PresentDisplay() {

	Swap();
	currentView_->printBuffer();	
}

void Display::Swap() {
	DisplayBuffer* tempView_ =currentView_;
	currentView_ = nextView_;
	nextView_ = tempView_;
	nextView_->clearBuffer();
}