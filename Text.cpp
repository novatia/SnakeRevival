#include "pch.h"
#include "Text.h"

using namespace std;
using namespace gamestructure;
using namespace composite;

Text::Text(wstring text)
{
	txt = text;
}

Text::~Text()
{
}

int Text::GetWidth()
{
	return txt.size();
}

int Text::GetHeight()
{
	return 1;
}

wstring Text::GetRow(int num)
{

	wstring color = GetColor();
	wstring endcolor = GetEndColor();

	if (num < top)
		return L"";

	if (num == top) 
	{
		if (selected)
			return color + L"> "+txt+L" <"+ endcolor;
		else
			return color + txt+ endcolor;
	}

	return L"";
}
