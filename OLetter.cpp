#include "pch.h"
#include "OLetter.h"
#include <string>

using namespace std;
using namespace gamestructure;
using namespace composite;

OLetter::OLetter()
{

}


OLetter::~OLetter()
{

}

wstring OLetter::GetRow(int num)
{
	switch (num) {
	case 0: return L"          ";
	case 1: return L" ______   ";
	case 2: return L"/\\  __ \\  ";
	case 3: return L"\\ \\ \\/\\ \\ ";
	case 4: return L" \\ \\_____\\";
	case 5: return L"  \\/_____/";
	case 6: return L"          ";
	}

	return L"";
}

int OLetter::GetWidth()
{
	return 10;
}

int OLetter::GetHeight()
{
	return 7;
}
