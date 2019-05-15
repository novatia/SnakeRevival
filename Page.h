#pragma once
#include "Draw.h"
class Page :
	public Draw
{
public:
	Page();
	virtual ~Page();
	virtual int GetWidth();
	virtual int GetHeight();
};
