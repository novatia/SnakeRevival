#include "pch.h"
#include "DLetter.h"

using namespace std;
using namespace SnakeRevival;
using namespace composite;

DLetter::DLetter()
{

}


DLetter::~DLetter()
{

}

wstring DLetter::GetRow(int num)
{
	wstring row = L"";
	wstring color = GetColor();

	switch (num) {
	case 0: row = L"          "; break;
	case 1: row = L" _____    "; break;
	case 2: row = L"/\\  __-.  "; break;
	case 3: row = L"\\ \\ \\/\\ \\ "; break;
	case 4: row = L" \\ \\____- "; break;
	case 5: row = L"  \\/____/ "; break;
	case 6: row = L"          "; break;
	}

	if (row != L"")
		row = Draw::Colorify(row, color);

	return row;
}

int DLetter::GetWidth()
{
	return 10;
}

int DLetter::GetHeight()
{
	return 7;
}
