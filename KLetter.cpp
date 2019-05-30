#include "pch.h"
#include "KLetter.h"
#include <string>

using namespace std;
using namespace gamestructure;
using namespace composite;

KLetter::KLetter()
{
}


KLetter::~KLetter()
{
}

wstring KLetter::GetRow(int num)
{
	switch (num) {
		case 0: return L"          ";
		case 1: return L" __  __   ";
		case 2: return L"/\\ \\/ /   ";
		case 3: return L"\\ \\  _\"-. ";
		case 4: return L" \\ \\_\\ \\_\\";
		case 5: return L"  \\/_/\\/_/";
		case 6: return L"          ";
	}

	return L"";
}

int KLetter::GetWidth()
{
	return 10;
}

int KLetter::GetHeight()
{
	return 7;
}
