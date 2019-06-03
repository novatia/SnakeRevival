#include "pch.h"
#include "LLetter.h"
#include <string>

using namespace std;
using namespace SnakeRevival;
using namespace composite;

LLetter::LLetter()
{

}


LLetter::~LLetter()
{

}

wstring LLetter::GetRow(int num)
{
	wstring row = L"";
	wstring color = GetColor();

	switch (num) {
	case 0: row =  L"         "; break;
	case 1: row =  L" ______  "; break;
	case 2: row =  L"/\\  __ \\ "; break;
	case 3: row =  L"\\ \\  __ \\"; break;
	case 4: row =  L" \\ \\_\\ \\_\\"; break;
	case 5: row =  L"  \\/_/\\/_/"; break;
	case 6: row =  L"         "; break;
	}

	if (row != L"")
		row = Draw::Colorify(row, color);

	return row;
}

int LLetter::GetWidth()
{
	return 10;
}

int LLetter::GetHeight()
{
	return 7;
}
