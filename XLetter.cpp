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

	wstring color = GetColor();
	wstring endcolor = GetEndColor();

	switch (num) {
	case 0: return color + L"          " + endcolor;
	case 1: return color + L" ______   " + endcolor;
	case 2: return color + L"/\\  __ \\  " + endcolor;
	case 3: return color + L"\\ \\  __ \\ " + endcolor;
	case 4: return color + L" \\ \\_\\ \\_\\" + endcolor;
	case 5: return color + L"  \\/_/\\/_/" + endcolor;
	case 6: return color + L"          " + endcolor;
	}

	return L"";
}

int XLetter::GetWidth()
{
	return 10;
}

int XLetter::GetHeight()
{
	return 7;
}
