#include "pch.h"
#include "ELetter.h"
#include <string>

using namespace std;
using namespace gamestructure;
using namespace composite;

ELetter::ELetter()
{
}


ELetter::~ELetter()
{
}

wstring ELetter::GetRow(int num)
{
	switch (num) {
		case 0: return L"          ";
		case 1: return L" ______   ";
		case 2: return L"/\\  ___\\  ";
		case 3: return L"\\ \\  __\\  ";
		case 4: return L" \\ \\_____\\";
		case 5: return L"  \\/_____/";
		case 6: return L"          ";
	}

	return L"";
}

int ELetter::GetWidth()
{
	return 10;
}

int ELetter::GetHeight()
{
	return 7;
}