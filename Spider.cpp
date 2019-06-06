#include "pch.h"
#include "Spider.h"

using namespace std;
using namespace SnakeRevival;
using namespace composite;

Spider::Spider()
{
}

Spider::~Spider()
{

}

wstring Spider::GetRow(int r_num)
{
	int num = r_num - m_Top;

	if (num < 0)
		return L"";

	wstring row = L"";

	switch (num) {
		case 0: row.append(Draw::Colorify(L"  //  \\\\  " , GetColor())); break;
		case 1: row.append(Draw::Colorify(L" _\\\\()//_ " , GetColor())); break;
		case 2: row.append(Draw::Colorify(L"/ //  \\\\ \\", GetColor())); break;
		case 3: row.append(Draw::Colorify(L" | \\__/ | ", GetColor())); break;
	}

	return row;
}


int Spider::GetWidth()
{
	return 10;
}

int Spider::GetHeight()
{
	return 4;
}