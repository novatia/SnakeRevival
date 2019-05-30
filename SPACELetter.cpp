#include "pch.h"
#include "SPACELetter.h"
#include <string>

using namespace std;
using namespace gamestructure;
using namespace composite;

SPACELetter::SPACELetter()
{

}

SPACELetter::~SPACELetter()
{

}

wstring SPACELetter::GetRow(int num)
{
	switch (num) {
	case 0: return L"          ";
	case 1: return L"          ";
	case 2: return L"          ";
	case 3: return L"          ";
	case 4: return L"          ";
	case 5: return L"          ";
	case 6: return L"          ";
	}

	return L"";
}

int SPACELetter::GetWidth()
{
	return 10;
}

int SPACELetter::GetHeight()
{
	return 7;
}
