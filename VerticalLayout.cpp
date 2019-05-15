#include "pch.h"
#include "VerticalLayout.h"
#include <vector>

using namespace std;

VerticalLayout::VerticalLayout()
{

}


VerticalLayout::~VerticalLayout()
{
}

void VerticalLayout::Add(Draw* element)
{
	elements.push_back(*element);
}
