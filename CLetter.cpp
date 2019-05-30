#include "pch.h"
#include "CLetter.h"
#include <string>

using namespace std;
using namespace gamestructure;
using namespace composite;

CLetter::CLetter()
{

}


CLetter::~CLetter()
{

}

wstring CLetter::GetRow(int num)
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

int CLetter::GetWidth()
{
	return 10;
}

int CLetter::GetHeight()
{
	return 7;
}
