#pragma once
#include "DisplayBuffer.h"

using namespace std;

class Display
{
public:
	Display();
	~Display();

	void PresentDisplay();
	void WriteNextDisplay(std::string& input);
	
private:
	void Swap();

	DisplayBuffer views[2];
	DisplayBuffer* currentView_;
	DisplayBuffer* nextView_;
};

