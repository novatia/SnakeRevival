#include "pch.h"
#include "NLetter.h"
#include <string>

using namespace std;
using namespace SnakeRevival;
using namespace composite;

NLetter::NLetter()
{
}


NLetter::~NLetter()
{
}

wstring NLetter::GetRow(int num)
{
	wstring row = L"";
	wstring color = GetColor();

	switch (num) {
		case 0: row =  L"         "; break;
		case 1: row =  L" __   __  "; break;
		case 2: row =  L"/\\ \" - .\\ "; break;
		case 3: row =  L"\\ \\ \\-.  \\"; break;
		case 4: row =  L" \\ \\_\\\\\"\\_\\"; break;
		case 5: row =  L"  \\/_/ \\/_/"; break;
		case 6: row =  L"         "; break;
	}

	if(row != L"")
		row = Draw::Colorify(row, color);

	return row;
}

int NLetter::GetWidth()
{
		return 10;
}

int NLetter::GetHeight()
{
	return 7;
}