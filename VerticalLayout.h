#pragma once
#include "Draw.h"

class VerticalLayout :
	public Draw
{
public:
	VerticalLayout();
	virtual ~VerticalLayout();
	void Add(Draw* element);

private:
	vector<Draw> elements;
};

