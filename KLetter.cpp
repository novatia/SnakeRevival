#include "pch.h"
#include "KLetter.h"
#include <string>

using namespace std;
using namespace SnakeRevival;
using namespace composite;

KLetter::KLetter()
{
}


KLetter::~KLetter()
{
}

wstring KLetter::GetRow(int num)
{
	wstring row = L"";
	wstring color = GetColor();

	switch (num) {
		case 0: row =  L"         "; break;
		case 1: row =  L" __  __  "; break;
		case 2: row =  L"/\\ \\/ /  "; break;
		case 3: row =  L"\\ \\  _\"-."; break;
		case 4: row = L" \\ \\_\\ \\_\\"; break;
		case 5: row = L"  \\/_/\\/_/"; break;
		case 6: row =  L"         "; break;
	}

	if (row != L"")
		row = Draw::Colorify(row, color);

	return row;
}

int KLetter::GetWidth()
{
		return 10;
}

int KLetter::GetHeight()
{
	return 7;
}
