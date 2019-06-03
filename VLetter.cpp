#include "pch.h"
#include "VLetter.h"
#include <string>

using namespace std;
using namespace SnakeRevival;
using namespace composite;

VLetter::VLetter()
{

}


VLetter::~VLetter()
{

}

wstring VLetter::GetRow(int num)
{
	wstring row = L"";
	wstring color = GetColor();

	switch (num) {
	case 0: row =  L"       "; break;
	case 1: row =  L" __   __"; break;
	case 2: row =  L"/\\ \\ / /"; break;
	case 3: row =  L"\\ \\ \\'/"; break;
	case 4: row =  L" \\ \\__|"; break;
	case 5: row =  L"  \\/_/ "; break;
	case 6: row =  L"       "; break;
	}

	if (row != L"")
		row = Draw::Colorify(row, color);

	return row;
}

int VLetter::GetWidth()
{
	return 8;
}

int VLetter::GetHeight()
{
	return 7;
}
