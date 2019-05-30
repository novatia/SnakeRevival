#include "pch.h"
#include "SLetter.h"
#include <string>

using namespace std;
using namespace gamestructure;
using namespace composite;

SLetter::SLetter()
{
}


SLetter::~SLetter()
{
}

wstring SLetter::GetRow(int num)
{
	switch (num) 
	{
		case 0: return L"          ";
		case 1: return L" ______   ";
		case 2: return L"/\\  ___\\  ";
		case 3: return L"\\ \\___  \\ ";
		case 4: return L" \\/\\_____\\";
		case 5: return L"  \\/_____/";
		case 6: return L"          ";
	}

	return L"";
}

int SLetter::GetWidth()
{
	return 10;
	//return 29;
}

int SLetter::GetHeight()
{
	return 7;
}