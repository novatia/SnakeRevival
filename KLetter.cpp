#include "pch.h"
#include "KLetter.h"
#include <string>

using namespace std;

KLetter::KLetter()
{
}


KLetter::~KLetter()
{
}

string KLetter::GetRow(int num)
{
	switch (num) {
		case 0: return "          ";
		case 1: return " __  __   ";
		case 2: return "/\ \/ /  ";
		case 3: return "\ \  _\" - . ";
		case 4: return " \ \_\ \_\\";
		case 5: return "  \/_/\/_/";
		case 6: return "          ";
	}
}