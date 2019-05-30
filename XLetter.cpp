#include "pch.h"
#include "XLetter.h"
#include <string>

using namespace std;
using namespace gamestructure;
using namespace composite;

XLetter::XLetter()
{

}


XLetter::~XLetter()
{

}

wstring XLetter::GetRow(int num)
{
	switch (num) {
	case 0: return L"          ";
	case 1: return L" ______   ";
	case 2: return L"/\\  __ \\  ";
	case 3: return L"\\ \\  __ \\ ";
	case 4: return L" \\ \\_\\ \\_\\";
	case 5: return L"  \\/_/\\/_/";
	case 6: return L"          ";
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
