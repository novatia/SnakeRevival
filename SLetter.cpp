#include "pch.h"
#include "SLetter.h"
#include <string>

using namespace std;

SLetter::SLetter()
{
}


SLetter::~SLetter()
{
}

string SLetter::GetRow(int num)
{
	switch (num) {
	case 0: return "          ";
	case 1: return " ______   ";
	case 2: return "/\\  ___\\  ";
	case 3: return "\\ \\___  \\ ";
	case 4: return " \\/\\_____\\";
	case 5: return "  \\/_____/";
	case 6: return "          ";
	}
}

int SLetter::GetWidth()
{
	return 10;
}

int SLetter::GetHeight()
{
	return 7;
}