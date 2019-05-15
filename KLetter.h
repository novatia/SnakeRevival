#pragma once
#include "Letter.h"
#include <string>

class KLetter :
	public Letter
{
public:
	KLetter();
	~KLetter();
	std::string GetRow(int num);
};
