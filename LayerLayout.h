#pragma once
#include "Draw.h"
#include <vector>
#include <map>
#include <memory>

class LayerLayout :
	public Draw
{
public:
	LayerLayout();
	~LayerLayout();
	void Add(Draw *element,int layer);

	virtual int GetWidth();
	virtual int GetHeight();
	virtual std::string GetRow(int num);

private:
	std::map<int,std::vector< Draw* >> elements;
};
