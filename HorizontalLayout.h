#pragma once
#include "Draw.h"
class HorizontalLayout :
	public Draw
{
public:
	HorizontalLayout();
	~HorizontalLayout();
	void Add( Draw* element);

private:
	vector<Draw> elements;

};

