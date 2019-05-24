#pragma once
#include "Draw.h"
#include <string>

class ALetter :
	public Draw
{
public:
	ALetter();
	~ALetter();

	virtual int GetWidth();
	virtual int GetHeight();
	virtual std::string GetRow(int num);
};
