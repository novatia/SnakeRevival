#include "pch.h"
#include "DLetter.h"
#include <string>

using namespace std;
using namespace gamestructure;
using namespace composite;

DLetter::DLetter()
{

}


DLetter::~DLetter()
{

}

wstring DLetter::GetRow(int num)
{

	wstring color = GetColor();
	wstring endcolor = GetEndColor();

	switch (num) {
	case 0: return color + L"          " + endcolor;
	case 1: return color + L" _____    " + endcolor;
	case 2: return color + L"/\\  __-.  " + endcolor;
	case 3: return color + L"\\ \\ \\/\\ \\ " + endcolor;
	case 4: return color + L" \\ \\____- " + endcolor;
	case 5: return color + L"  \\/____/ " + endcolor;
	case 6: return color + L"          " + endcolor;
	}

	return L"";
}

int DLetter::GetWidth()
{
	return 10;
}

int DLetter::GetHeight()
{
	return 7;
}
