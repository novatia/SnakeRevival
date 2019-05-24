#include "pch.h"
#include "HorizontalLayout.h"
#include <vector>

using namespace std;

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
		width += (*it)->GetHeight();
	 
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

std::string HorizontalLayout::GetRow(int num)
{
	std::string row;
	for (auto it = elements.begin(); it < elements.end(); it++)
		row += (*it)->GetRow(num);

	return row;
}
