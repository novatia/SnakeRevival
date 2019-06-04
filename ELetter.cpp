#include "pch.h"
#include "ELetter.h"
#include <string>

using namespace std;
using namespace SnakeRevival;
using namespace composite;

ELetter::ELetter()
{
}


ELetter::~ELetter()
{
}

wstring ELetter::GetRow(int num)
{
	wstring row = L"";
	wstring color = GetColor();

	switch (num) {
		case 0: row =  L"          "; break;
		case 1: row =  L" ______   "; break;
		case 2: row =  L"/\\  ___\\  "; break;
		case 3: row =  L"\\ \\  __\\  "; break;
		case 4: row =  L" \\ \\_____\\"; break;
		case 5: row =  L"  \\/_____/"; break;
		case 6: row =  L"          "; break;
	}

	if (row != L"")
		row = Draw::Colorify(row, color);

	return row;
}

int ELetter::GetWidth()
{
	return 10;
}

int ELetter::GetHeight()
{
	return 7;
}