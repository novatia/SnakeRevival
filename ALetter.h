#pragma once
#include "Letter.h"
#include <string>

class ALetter :
	public Letter
{
public:
	ALetter();
	~ALetter();
	std::string GetRow(int num);
};
