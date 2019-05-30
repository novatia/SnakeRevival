#include "pch.h"
#include "TLetter.h"
#include <string>

using namespace std;
using namespace gamestructure;
using namespace composite;

TLetter::TLetter()
{

}


TLetter::~TLetter()
{

}

wstring TLetter::GetRow(int num)
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

int TLetter::GetWidth()
{
	return 10;
}

int TLetter::GetHeight()
{
	return 7;
}
