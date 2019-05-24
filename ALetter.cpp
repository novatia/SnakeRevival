#include "pch.h"
#include "ALetter.h"
#include <string>

using namespace std;

ALetter::ALetter()
{

}


ALetter::~ALetter()
{

}

string ALetter::GetRow(int num)
{
	switch (num) {
		case 0: return "          ";
		case 1: return " ______   ";
		case 2: return "/\  __ \  ";
		case 3: return "\ \  __ \ ";
		case 4: return " \ \_\ \_\\";
		case 5: return "  \/_/\/_/";
		case 6: return "          ";
	}
}
