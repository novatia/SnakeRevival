#include "pch.h"
#include "Frame.h"
#include <string>

using namespace std; 
using namespace SnakeRevival;
using namespace composite;


Frame::Frame()
{
}

Frame::~Frame()
{
}


wstring Frame::GetRow(int num)
{
	wstring row = L"";
	wstring color = GetColor();

	switch (num) {
	case 0: row = L"╔══════════════════════════════════════════════════════════════════════════════╗"; break;
	case 1: row = L"║                                                                              ║"; break;
	case 2: row = L"║                                                                              ║"; break;
	case 3: row = L"║                                                                              ║"; break;
	case 4: row = L"║                                                                              ║"; break;
	case 5: row = L"║                                                                              ║"; break;
	case 6: row = L"║                                                                              ║"; break;
	case 7: row = L"║                                                                              ║"; break;
	case 8: row = L"║                                                                              ║"; break;
	case 9: row = L"║                                                                              ║"; break;
	case 10: row = L"║                                                                              ║"; break;
	case 11: row = L"║                                                                              ║"; break;
	case 12: row = L"║                                                                              ║"; break;
	case 13: row = L"║                                                                              ║"; break;
	case 14: row = L"║                                                                              ║"; break;
	case 15: row = L"║                                                                              ║"; break;
	case 16: row = L"║                                                                              ║"; break;
	case 17: row = L"║                                                                              ║"; break;
	case 18: row = L"║                                                                              ║"; break;
	case 19: row = L"║                                                                              ║"; break;
	case 20: row = L"║                                                                              ║"; break;
	case 21: row = L"║                                                                              ║"; break;
	case 22: row = L"║                                                                              ║"; break;
	case 23: row = L"║                                                                              ║"; break;
	case 24: row = L"╚══════════════════════════════════════════════════════════════════════════════╝"; break;
	}

	if (row != L"")
		row = Draw::Colorify(row, color);

	return row;
}

int Frame::GetWidth()
{
	return 80;
}

int Frame::GetHeight()
{
	return 25;
}
