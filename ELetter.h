#pragma once
#include "Letter.h"
#include <string>

class ELetter :
	public Letter
{
public:
	ELetter();
	~ELetter();
	std::string GetRow(int num);
};
