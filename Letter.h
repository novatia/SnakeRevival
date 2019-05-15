#pragma once
#include "Draw.h"
class Letter :
	public Draw
{
public:
	Letter();
	virtual ~Letter();
	virtual int GetWidth();
	virtual int GetHeight();
};

