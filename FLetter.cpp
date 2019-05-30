#include "pch.h"
#include "FLetter.h"
#include <string>

using namespace std;
using namespace gamestructure;
using namespace composite;

FLetter::FLetter()
{

}


FLetter::~FLetter()
{

}

wstring FLetter::GetRow(int num)
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

int FLetter::GetWidth()
{
	return 10;
}

int FLetter::GetHeight()
{
	return 7;
}
