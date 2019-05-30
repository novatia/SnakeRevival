#include "pch.h"
#include "DLetter.h"
#include <string>

using namespace std;
using namespace gamestructure;
using namespace composite;

DLetter::DLetter()
{

}


DLetter::~DLetter()
{

}

wstring DLetter::GetRow(int num)
{
	switch (num) {
	case 0: return L"          ";
	case 1: return L" _____    ";
	case 2: return L"/\\  __-.  ";
	case 3: return L"\\ \\ \\/\\ \\ ";
	case 4: return L" \\ \\____- ";
	case 5: return L"  \\/____/ ";
	case 6: return L"          ";
	}

	return L"";
}

int DLetter::GetWidth()
{
	return 10;
}

int DLetter::GetHeight()
{
	return 7;
}
