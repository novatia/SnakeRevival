#include "pch.h"
#include "HLetter.h"
#include <string>

using namespace std;
using namespace SnakeRevival;
using namespace composite;

HLetter::HLetter()
{

}


HLetter::~HLetter()
{

}

wstring HLetter::GetRow(int num)
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

int HLetter::GetWidth()
{
	return 10;
}

int HLetter::GetHeight()
{
	return 7;
}
