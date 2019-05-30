#include "pch.h"
#include "NLetter.h"
#include <string>

using namespace std;
using namespace SnakeRevival;
using namespace composite;

NLetter::NLetter()
{
}


NLetter::~NLetter()
{
}

wstring NLetter::GetRow(int num)
{

	wstring color = GetColor();
	wstring endcolor = GetEndColor();

	switch (num) {
		case 0: return color + L"          " + endcolor;
		case 1: return color + L" __   __   " + endcolor;
		case 2: return color + L"/\\ \" - .\\  " + endcolor;
		case 3: return color + L"\\ \\ \\-.  \\ " + endcolor;
		case 4: return color + L" \\ \\_\\\\\"\\_\\" + endcolor;
		case 5: return color + L"  \\/_/ \\/_/" + endcolor;
		case 6: return color + L"          " + endcolor;
	}

	return L"";
}

int NLetter::GetWidth()
{
		return 10;
}

int NLetter::GetHeight()
{
	return 7;
}