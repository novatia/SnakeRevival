#include "pch.h"
#include "ULetter.h"
#include <string>

using namespace std;
using namespace gamestructure;
using namespace composite;

ULetter::ULetter()
{

}


ULetter::~ULetter()
{

}

wstring ULetter::GetRow(int num)
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

int ULetter::GetWidth()
{
	return 10;
}

int ULetter::GetHeight()
{
	return 7;
}
