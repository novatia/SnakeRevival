#include "pch.h"
#include "GLetter.h"
#include <string>

using namespace std;
using namespace gamestructure;
using namespace composite;

GLetter::GLetter()
{

}


GLetter::~GLetter()
{

}

wstring GLetter::GetRow(int num)
{

	wstring color = GetColor();
	wstring endcolor = GetEndColor();

	switch (num) {
	case 0: return color + L"          " + endcolor;
	case 1: return color + L" ______   " + endcolor;
	case 2: return color + L"/\\  ___\\  " + endcolor;
	case 3: return color + L"\\ \\ \\__ \\ " + endcolor;
	case 4: return color + L" \\ \\_____\\" + endcolor;
	case 5: return color + L"  \\/_____/" + endcolor;
	case 6: return color + L"          " + endcolor;
	}

	return L"";
}

int GLetter::GetWidth()
{
	return 10;
}

int GLetter::GetHeight()
{
	return 7;
}
