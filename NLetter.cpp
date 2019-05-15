#include "pch.h"
#include "NLetter.h"
#include <string>

using namespace std;

NLetter::NLetter()
{
}


NLetter::~NLetter()
{
}

string NLetter::GetRow(int num)
{
	switch (num) {
		case 0: return "          ";
		case 1: return " __   __  ";
		case 2: return "/\ \" - .\ ";
		case 3: return "\ \ \-.  \\";
		case 4: return " \ \_\\\"\_\\";
		case 5: return "  \/_/ \/_/";
		case 6: return "          ";
	}
}