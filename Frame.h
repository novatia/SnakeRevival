#pragma once
#include "Page.h"
class Frame :
	public Page
{
public:
	Frame();
	virtual ~Frame();

private: 
	Draw *composite;
};

