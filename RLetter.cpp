#include "pch.h"
#include "RLetter.h"
#include <string>

using namespace std;
using namespace SnakeRevival;
using namespace composite;

RLetter::RLetter()
{

}


RLetter::~RLetter()
{

}

wstring RLetter::GetRow(int num)
{
	wstring row = L"";
	wstring color = GetColor();

	switch (num) {
	case 0: row =  L"         "; break;
	case 1: row =  L" ______  "; break;
	case 2: row =  L"/\\  == \\ "; break;
	case 3: row =  L"\\ \\  __< "; break;
	case 4: row =  L" \\ \\_\\ \\_\\"; break;
	case 5: row =  L"  \\/_/ /_/"; break;
	case 6: row =  L"         "; break;
	}

	if (row != L"")
		row = Draw::Colorify(row, color);

	return row;
}

int RLetter::GetWidth()
{
	return 11;
}

int RLetter::GetHeight()
{
	return 7;
}
