#pragma once
#include "Draw.h"
#include <string>

class KLetter :
	public Draw
{
public:
	KLetter();
	~KLetter();

	virtual int GetWidth();
	virtual int GetHeight();
	virtual std::string GetRow(int num);
};
