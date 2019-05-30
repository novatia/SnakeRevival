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
	if (num < top)
		return L"";

	if (num == top) 
	{
		if (selected)
			return L"> "+txt+L" <";
		else
			return txt;
	}

	return L"";
}
