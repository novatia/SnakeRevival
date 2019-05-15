#pragma once
#include "Letter.h"
#include <string>

class SLetter :
	public Letter
{
public:
	SLetter();
	~SLetter();
	std::string GetRow(int num);
};
