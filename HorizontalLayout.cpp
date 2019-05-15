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
	elements.push_back(*element);
}
