#include "pch.h"
#include "SLetter.h"
#include <string>

using namespace std;
using namespace SnakeRevival;
using namespace composite;

SLetter::SLetter()
{
}


SLetter::~SLetter()
{

}

wstring SLetter::GetRow(int num)
{

	wstring color = GetColor();
	wstring endcolor = GetEndColor();

	switch (num) 
	{
		case 0: return color + L"          " + endcolor;
		case 1: return color + L" ______   " + endcolor;;
		case 2: return color + L"/\\  ___\\  " + endcolor;;
		case 3: return color + L"\\ \\___  \\ " + endcolor;;
		case 4: return color + L" \\/\\_____\\" + endcolor;;
		case 5: return color + L"  \\/_____/" + endcolor;;
		case 6: return color + L"          " + endcolor;
	}

	return L"";
}

int SLetter::GetWidth()
{
	return 10;
}

int SLetter::GetHeight()
{
	return 7;
}