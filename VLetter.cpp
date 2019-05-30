#include "pch.h"
#include "VLetter.h"
#include <string>

using namespace std;
using namespace gamestructure;
using namespace composite;

VLetter::VLetter()
{

}


VLetter::~VLetter()
{

}

wstring VLetter::GetRow(int num)
{
	switch (num) {
	case 0: return L"        ";
	case 1: return L" __   __";
	case 2: return L"/\\ \\ / /";
	case 3: return L"\\ \\ \\'/ ";
	case 4: return L" \\ \\__| ";
	case 5: return L"  \\/_/  ";
	case 6: return L"        ";
	}

	return L"";
}

int VLetter::GetWidth()
{
	return 8;
}

int VLetter::GetHeight()
{
	return 7;
}
