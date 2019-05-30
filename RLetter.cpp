#include "pch.h"
#include "RLetter.h"
#include <string>

using namespace std;
using namespace gamestructure;
using namespace composite;

RLetter::RLetter()
{

}


RLetter::~RLetter()
{

}

wstring RLetter::GetRow(int num)
{
	switch (num) {
	case 0: return L"          ";
	case 1: return L" ______   ";
	case 2: return L"/\\  == \\  ";
	case 3: return L"\\ \\  __<  ";
	case 4: return L" \\ \\_\\ \\_\\";
	case 5: return L"  \\/_/ /_/";
	case 6: return L"          ";
	}

	return L"";
}

int RLetter::GetWidth()
{
	return 11;
}

int RLetter::GetHeight()
{
	return 7;
}
