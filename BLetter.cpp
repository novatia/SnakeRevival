#include "pch.h"
#include "BLetter.h"
#include <string>

using namespace std;
using namespace gamestructure;
using namespace composite;

BLetter::BLetter()
{

}


BLetter::~BLetter()
{

}

wstring BLetter::GetRow(int num)
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

int BLetter::GetWidth()
{
	return 10;
}

int BLetter::GetHeight()
{
	return 7;
}
