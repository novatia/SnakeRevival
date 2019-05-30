#include "pch.h"
#include "MLetter.h"
#include <string>

using namespace std;
using namespace gamestructure;
using namespace composite;

MLetter::MLetter()
{

}


MLetter::~MLetter()
{

}

wstring MLetter::GetRow(int num)
{
	switch (num) {
	case 0: return L"            ";
	case 1: return L" __    __   ";
	case 2: return L"/\\\ \\\" - . / \\  ";
	case 3: return L"\\ \\ \\-./\\ \\ ";
	case 4: return L" \\ \\_\\ \\ \\_\\";
	case 5: return L"  \\/_/  \\/_/";
	case 6: return L"            ";
	}

	return L"";
}

int MLetter::GetWidth()
{
	return 13;
}

int MLetter::GetHeight()
{
	return 7;
}
