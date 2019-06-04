#include "pch.h"
#include "DisplayBuffer.h"

using namespace SnakeRevival;

void HideCursor()
{
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
	HideCursor();
}

DisplayBuffer::~DisplayBuffer()
{

}

void DisplayBuffer::printBuffer() {
	SetZero();

	DWORD Written;
	HANDLE 	m_Screen = GetStdHandle(STD_OUTPUT_HANDLE);
	WriteConsole(m_Screen, buffer.c_str(), buffer.size(), &Written, NULL);
}

void DisplayBuffer::writeBuffer(const std::wstring& input) {
	buffer.assign(input);
}

void DisplayBuffer::clearBuffer() {
	buffer.clear();
}