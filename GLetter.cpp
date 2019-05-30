#include "pch.h"
#include "GLetter.h"
#include <string>

using namespace std;
using namespace gamestructure;
using namespace composite;

GLetter::GLetter()
{

}


GLetter::~GLetter()
{

}

wstring GLetter::GetRow(int num)
{
	switch (num) {
	case 0: return L"          ";
	case 1: return L" ______   ";
	case 2: return L"/\\  ___\\  ";
	case 3: return L"\\ \\ \\__ \\ ";
	case 4: return L" \\ \\_____\\";
	case 5: return L"  \\/_____/";
	case 6: return L"          ";
	}

	return L"";
}

int GLetter::GetWidth()
{
	return 10;
}

int GLetter::GetHeight()
{
	return 7;
}
