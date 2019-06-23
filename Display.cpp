#include "pch.h"
#include "Display.h"
#include "constants.h"

using namespace SnakeRevival;

//std::wstring Display::m_Performance;
//: currentView_(new DisplayBuffer()), nextView_(new DisplayBuffer())
Display::Display() : currentView_(&views[0]), nextView_(&views[1])
{

	//ENABLE ANSI ESCAPE CODE
	HANDLE  hOut = GetStdHandle(STD_OUTPUT_HANDLE);
	DWORD dwMode = 0;

	if (!GetConsoleMode(hOut, &dwMode))
	{
		 std::cout << GetLastError();
		 return;
	}
	dwMode |= ENABLE_VIRTUAL_TERMINAL_PROCESSING;
	SetConsoleMode(hOut, dwMode);

	//_setmode(_fileno(stdout), _O_U8TEXT);
	//_setmode(_fileno(stdout), _O_TEXT);
//	setvbuf(stdout, 0, _IOLBF, 20025);

	SetConsoleCP(0);
	SetConsoleOutputCP(0);

	//std::wcout.sync_with_stdio(false);
	std::ios_base::sync_with_stdio(false);
}

Display::~Display()
{
	

}

/*
I need to give this method a bunch of data which gives:
the coordinates of the upper left corner and the width and the height of the object to draw
*/
void Display::WriteNextDisplay(const std::wstring& input)
{
	nextView_->writeBuffer(input);
}
/*
std::wstring SnakeRevival::Display::GetPerformance()
{
	return m_Performance;
}
*/

void Display::PresentDisplay()
{
	Swap();
	//std::chrono::time_point < std::chrono::steady_clock> t1 = std::chrono::high_resolution_clock::now();
	currentView_->printBuffer();	
	//std::chrono::time_point < std::chrono::steady_clock> t2 = std::chrono::high_resolution_clock::now();
	//m_Performance = log_progress(t2 - t1);
}

void Display::Swap()
{
	DisplayBuffer* tempView_ =currentView_;
	currentView_ = nextView_;
	nextView_ = tempView_;
	nextView_->clearBuffer();
}