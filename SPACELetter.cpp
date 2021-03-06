#include "pch.h"
#include "SPACELetter.h"
#include <string>

using namespace std;
using namespace SnakeRevival;
using namespace composite;

SPACELetter::SPACELetter()
{

}

SPACELetter::~SPACELetter()
{

}

wstring SPACELetter::GetRow(int num)
{
	wstring row = L"";
	wstring color = GetColor();

	switch (num) {
	case 0: row = L"          "; break;
	case 1:  row = L"          "; break;
	case 2:  row = L"          "; break;
	case 3:  row = L"          "; break;
	case 4:  row = L"          "; break;
	case 5:  row = L"          "; break;
	case 6:  row = L"          "; break;
	}

	if (row != L"")
		row = Draw::Colorify(row, color);

	return row;
}

int SPACELetter::GetWidth()
{
	return 10;
}

int SPACELetter::GetHeight()
{
	return 7;
}
