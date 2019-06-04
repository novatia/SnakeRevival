#include "pch.h"

#include "WormBody.h"

using namespace std;
using namespace SnakeRevival;
using namespace composite;

WormBody::WormBody()
{
	
}

WormBody::~WormBody()
{
}

int WormBody::GetWidth()
{
	int width = m_Left + 1;
		
	return width;
}

int WormBody::GetHeight()
{
	return 1;
}

wstring WormBody::GetRow(int r_num)
{
	int num = r_num - m_Top;

	if (num < 0)
		return L"";

	wstring row = L"";
	wstring color = GetColor();
	wstring endcolor = GetEndColor();

	switch (num) 
	{
		case 0: row.append(color + L"■" + endcolor);
	}

	return row;
}