#pragma once
#include "Draw.h"
#include <string>

class SLetter :
	public Draw
{
public:
	SLetter();
	~SLetter();

	virtual int GetWidth();
	virtual int GetHeight();
	virtual std::string GetRow(int num);
};
