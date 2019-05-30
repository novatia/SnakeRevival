#include "pch.h"
#include "ALetter.h"
#include <string>

using namespace std;
using namespace gamestructure;
using namespace composite;

ALetter::ALetter()
{

}


ALetter::~ALetter()
{

}

wstring ALetter::GetRow(int num)
{
	wstring color = GetColor();
	wstring endcolor = GetEndColor();

	switch (num) {
		case 0: return color + L"          " + endcolor;
		case 1: return color + L" ______   "+endcolor;
		case 2: return color + L"/\\  __ \\  " + endcolor;
		case 3: return color + L"\\ \\  __ \\ " + endcolor;
		case 4: return color + L" \\ \\_\\ \\_\\" + endcolor;
		case 5: return color + L"  \\/_/\\/_/" + endcolor;
		case 6: return color + L"          " + endcolor;
	}

	return L"";
}

int ALetter::GetWidth()
{
		return 10;
}

int ALetter::GetHeight()
{
	return 7;
}
