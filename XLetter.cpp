#include "pch.h"
#include "XLetter.h"
#include <string>

using namespace std;
using namespace SnakeRevival;
using namespace composite;

XLetter::XLetter()
{

}


XLetter::~XLetter()
{

}

wstring XLetter::GetRow(int num)
{
	wstring row = L"";
	wstring color = GetColor();

	switch (num) {
	case 0: row =  L"         "; break;
	case 1: row =  L" ______  "; break;
	case 2: row =  L"/\\  __ \\ "; break;
	case 3: row =  L"\\ \\  __ \\"; break;
	case 4: row =  L" \\ \\_\\ \\_\\"; break;
	case 5: row =  L"  \\/_/\\/_/"; break;
	case 6: row =  L"         "; break;
	}

	if (row != L"")
		row = Draw::Colorify(row, color);

	return row;
}

int XLetter::GetWidth()
{
	return 10;
}

int XLetter::GetHeight()
{
	return 7;
}
