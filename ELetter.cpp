#include "pch.h"
#include "ELetter.h"
#include <string>

using namespace std;

ELetter::ELetter()
{
}


ELetter::~ELetter()
{
}

string ELetter::GetRow(int num)
{
	switch (num) {
		case 0: return "          ";
		case 1: return " ______  ";
		case 2: return "/\  ___\  ";
		case 3: return "\ \  __\  ";
		case 4: return " \ \_____\\";
		case 5: return "  \/_____/";
		case 6: return "          ";
	}
}