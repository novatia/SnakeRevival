#pragma once
#include <string>

class Draw
{
public:
	virtual int GetWidth()=0;
	virtual int GetHeight() = 0;
	virtual std::string GetRow(int num) = 0;
};
