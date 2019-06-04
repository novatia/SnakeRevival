#include "pch.h"
#include "OLetter.h"
#include <string>

using namespace std;
using namespace SnakeRevival;
using namespace composite;

OLetter::OLetter()
{

}


OLetter::~OLetter()
{

}

wstring OLetter::GetRow(int num)
{
	wstring row = L"";
	wstring color = GetColor();

	switch (num) {
	case 0: row =  L"          "; break;
	case 1: row =  L" ______   "; break;
	case 2: row =  L"/\\  __ \\  "; break;
	case 3: row =  L"\\ \\ \\/\\ \\ "; break;
	case 4: row =  L" \\ \\_____\\"; break;
	case 5: row =  L"  \\/_____/"; break;
	case 6: row =  L"          "; break;
	}

	if (row != L"")
		row = Draw::Colorify(row, color);

	return row;
}

int OLetter::GetWidth()
{
	return 11;
}

int OLetter::GetHeight()
{
	return 7;
}
