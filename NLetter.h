#pragma once
#include "Letter.h"
#include <string>

class NLetter :
	public Letter
{
public:
	NLetter();
	~NLetter();
	std::string GetRow(int num);
};
