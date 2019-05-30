#include "pch.h"
#include "DisplayBuffer.h"

using namespace SnakeRevival;

void HideCursor() {
	_setmode(_fileno(stdout), _O_U16TEXT);
	HANDLE out = GetStdHandle(STD_OUTPUT_HANDLE);
	CONSOLE_CURSOR_INFO     cursorInfo;
	GetConsoleCursorInfo(out, &cursorInfo);
	cursorInfo.bVisible = false; // set the cursor visibility
	SetConsoleCursorInfo(out, &cursorInfo);
}

void SetZero() {
	COORD coord;
	coord.X = 0;
	coord.Y = 0;
	SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), coord);
}

DisplayBuffer::DisplayBuffer()
{
}


DisplayBuffer::~DisplayBuffer()
{
}

void DisplayBuffer::printBuffer() {
	HideCursor();
	SetZero();
	std::wcout << buffer;
}

void DisplayBuffer::writeBuffer(const std::wstring& input) {
	buffer.assign(input);
}
void DisplayBuffer::clearBuffer() {
	buffer.clear();
}
