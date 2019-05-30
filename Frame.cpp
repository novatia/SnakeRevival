#include "pch.h"
#include "Frame.h"
#include <string>

using namespace std; 
using namespace gamestructure;
using namespace composite;


Frame::Frame()
{
}

Frame::~Frame()
{
}


wstring Frame::GetRow(int num)
{
	switch (num) {
	case 0: return  L"╔═════════════════════════════════════════════════════════════════════════════╗";
	case 1: return  L"║                                                                             ║";
	case 2: return  L"║                                                                             ║";
	case 3: return  L"║                                                                             ║";
	case 4: return  L"║                                                                             ║";
	case 5: return  L"║                                                                             ║";
	case 6: return  L"║                                                                             ║";
	case 7: return  L"║                                                                             ║";
	case 8: return  L"║                                                                             ║";
	case 9: return  L"║                                                                             ║";
	case 10: return L"║                                                                             ║";
	case 11: return L"║                                                                             ║";
	case 12: return L"║                                                                             ║";
	case 13: return L"║                                                                             ║";
	case 14: return L"║                                                                             ║";
	case 15: return L"║                                                                             ║";
	case 16: return L"║                                                                             ║";
	case 17: return L"║                                                                             ║";
	case 18: return L"║                                                                             ║";
	case 19: return L"║                                                                             ║";
	case 20: return L"║                                                                             ║";
	case 21: return L"║                                                                             ║";
	case 22: return L"║                                                                             ║";
	case 23: return L"║                                                                             ║";
	case 24: return L"╚═════════════════════════════════════════════════════════════════════════════╝";
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
