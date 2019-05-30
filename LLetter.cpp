#include "pch.h"
#include "LLetter.h"
#include <string>

using namespace std;
using namespace gamestructure;
using namespace composite;

LLetter::LLetter()
{

}


LLetter::~LLetter()
{

}

wstring LLetter::GetRow(int num)
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

int LLetter::GetWidth()
{
	return 10;
}

int LLetter::GetHeight()
{
	return 7;
}
