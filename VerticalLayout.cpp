#include "pch.h"
#include "VerticalLayout.h"
#include <vector>

using namespace std;
using namespace SnakeRevival;
using namespace composite;

VerticalLayout::VerticalLayout()
{

}


VerticalLayout::~VerticalLayout()
{
}

void VerticalLayout::Add(Draw* element)
{
	m_Elements.push_back(element);
}

int VerticalLayout::GetWidth()
{
	//return sum of width;
	int max_width = 0;

	for (auto it = m_Elements.begin(); it < m_Elements.end(); it++)
		if (max_width < (*it)->GetWidth())
			max_width = (*it)->GetWidth();

	return max_width;
}

int VerticalLayout::GetHeight()
{
	int height = 0;

	for (auto it = m_Elements.begin(); it < m_Elements.end(); it++)
		height += (*it)->GetHeight();

	return height;
}


wstring VerticalLayout::GetRow(int row_num)
{
	int num = row_num - m_Top;

	if (num < 0) {
		return L"";
	}

	std::wstring row ;
	int current_row = 0;
	for (auto it = m_Elements.begin(); it < m_Elements.end(); it++) {
		for (int r = 0; r < (*it)->GetHeight(); r++) {
			if (num == r + current_row) {
				return (*it)->GetRow(r);
			}
		}
		current_row += m_Elements.back()->GetHeight();
	}

	return row;
}
