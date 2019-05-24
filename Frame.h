#pragma once
#include "Page.h"
class Frame :
	public Draw
{
public:
	Frame();
	virtual ~Frame();

	virtual int GetWidth();
	virtual int GetHeight();
	virtual std::string GetRow(int num);
};

