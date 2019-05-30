#include "pch.h"
#include "Frame.h"
#include <string>

using namespace std; 
using namespace SnakeRevival;
using namespace composite;


Frame::Frame()
{
}

Frame::~Frame()
{
}


wstring Frame::GetRow(int num)
{
	wstring color = GetColor();
	wstring endcolor = GetEndColor();

	switch (num) {
	case 0: return  color + L"╔═════════════════════════════════════════════════════════════════════════════╗" + endcolor;
	case 1: return  color + L"║                                                                             ║" + endcolor;
	case 2: return  color + L"║                                                                             ║" + endcolor;
	case 3: return  color + L"║                                                                             ║" + endcolor;
	case 4: return  color + L"║                                                                             ║" + endcolor;
	case 5: return  color + L"║                                                                             ║" + endcolor;
	case 6: return  color + L"║                                                                             ║" + endcolor;
	case 7: return  color + L"║                                                                             ║" + endcolor;
	case 8: return  color + L"║                                                                             ║" + endcolor;
	case 9: return  color + L"║                                                                             ║" + endcolor;
	case 10: return color + L"║                                                                             ║" + endcolor;
	case 11: return color + L"║                                                                             ║" + endcolor;
	case 12: return color + L"║                                                                             ║" + endcolor;
	case 13: return color + L"║                                                                             ║" + endcolor;
	case 14: return color + L"║                                                                             ║" + endcolor;
	case 15: return color + L"║                                                                             ║" + endcolor;
	case 16: return color + L"║                                                                             ║" + endcolor;
	case 17: return color + L"║                                                                             ║" + endcolor;
	case 18: return color + L"║                                                                             ║" + endcolor;
	case 19: return color + L"║                                                                             ║" + endcolor;
	case 20: return color + L"║                                                                             ║" + endcolor;
	case 21: return color + L"║                                                                             ║" + endcolor;
	case 22: return color + L"║                                                                             ║" + endcolor;
	case 23: return color + L"║                                                                             ║" + endcolor;
	case 24: return color + L"╚═════════════════════════════════════════════════════════════════════════════╝" + endcolor;
	}

	return L"";
}

int Frame::GetWidth()
{
	return 80;
}

int Frame::GetHeight()
{
	return 25;
}
