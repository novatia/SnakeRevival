#include "pch.h"
#include "HorizontalLayout.h"
#include <vector>

using namespace std;
using namespace gamestructure;
using namespace composite;

HorizontalLayout::HorizontalLayout()
{
}

HorizontalLayout::~HorizontalLayout()
{
}

void HorizontalLayout::Add(Draw* element)
{
	elements.push_back(element);
}

int HorizontalLayout::GetWidth()
{
	int width = 0;

	for (auto it = elements.begin(); it < elements.end(); it++)
		width += (*it)->GetWidth();
	 
	return width;
}

int HorizontalLayout::GetHeight()
{
	//return max height;
	int max_height = 0;

	for (auto it = elements.begin(); it < elements.end(); it++)
		if (max_height < (*it)->GetHeight())
			max_height = (*it)->GetHeight();

	return max_height;

}

wstring HorizontalLayout::GetRow(int num)
{
	wstring row;
	for (auto it = elements.begin(); it < elements.end(); it++)
		row += (*it)->GetRow(num);

	return row;
}
