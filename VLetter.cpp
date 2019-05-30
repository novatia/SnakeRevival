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

	wstring color = GetColor();
	wstring endcolor = GetEndColor();

	switch (num) {
	case 0: return color + L"        " + endcolor;
	case 1: return color + L" __   __" + endcolor;
	case 2: return color + L"/\\ \\ / /" + endcolor;
	case 3: return color + L"\\ \\ \\'/ " + endcolor;
	case 4: return color + L" \\ \\__| " + endcolor;
	case 5: return color + L"  \\/_/  " + endcolor;
	case 6: return color + L"        " + endcolor;
	}

	return L"";
}

int VLetter::GetWidth()
{
	return 8;
}

int VLetter::GetHeight()
{
	return 7;
}
