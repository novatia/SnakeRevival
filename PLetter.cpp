#include "pch.h"
#include "PLetter.h"
#include <string>

using namespace std;
using namespace gamestructure;
using namespace composite;

PLetter::PLetter()
{

}


PLetter::~PLetter()
{

}

wstring PLetter::GetRow(int num)
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

int PLetter::GetWidth()
{
	return 10;
}

int PLetter::GetHeight()
{
	return 7;
}
