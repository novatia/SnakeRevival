#pragma once
#include "Draw.h"
#include <string>

class ELetter :
	public Draw
{
public:
	ELetter();
	~ELetter();

	virtual int GetWidth();
	virtual int GetHeight();
	virtual std::string GetRow(int num);
};
