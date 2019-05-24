#pragma once
#include "Draw.h"
#include <string>

class NLetter :
	public Draw
{
public:
	NLetter();
	~NLetter(); 
	
	virtual int GetWidth();
	virtual int GetHeight();
	virtual std::string GetRow(int num);
};
