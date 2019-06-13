#include "pch.h"

#include "WormBody.h"

using namespace std;
using namespace SnakeRevival;
using namespace composite;

WormBody::WormBody()
{
	m_MaxLenght = 2;
}

WormBody::~WormBody()
{
}

int WormBody::GetWidth()
{
	int width = m_Left + 1;
		
	return width;
}

int WormBody::GetHeight()
{
	return 1;
}

wstring WormBody::GetRow(int r_num)
{
	int num;

	wstring row = L"                                                                              ";
	row = Colorify(row, GetColor(Color::White));

	wstring color = GetColor();
	wstring endcolor = GetEndColor();


	for (std::vector<std::pair<int, int>>::iterator it = m_WormElements.begin(); it != m_WormElements.end(); ++it)
	{
		num = r_num - it->second;

		if (num == 0) {
			row.replace(it->first * 10, 10, color + L"O" + endcolor);
		}
	}

	return row;
}

void SnakeRevival::composite::WormBody::SetSnakePosition(int l, int t)
{
	bool found=false;
	if ( m_WormElements.size() < m_MaxLenght ) {
		for (std::vector<std::pair<int, int>>::iterator it = m_WormElements.begin(); it != m_WormElements.end(); ++it) {
			if (it->first == l && it->second == t)
			{
				found = true;
				break;
			}
		}
			
		if (! found )
			m_WormElements.push_back(std::pair<int, int>(l, t));
	}
	else {
		if (GetSnakeHeadPosition().first != l || GetSnakeHeadPosition().second != t) {
			// remove tail
			m_WormElements.erase(m_WormElements.begin());

			//add head
			m_WormElements.push_back(std::pair<int, int>(l, t));
		}
	}
}


bool SnakeRevival::composite::WormBody::CollisionCheck(int l, int t)
{

	std::pair<int, int> head_position = GetSnakeHeadPosition();
	if (head_position.first == l && head_position.second == t)
		return false;

	for (std::vector<std::pair<int, int>>::iterator it = m_WormElements.begin(); it != m_WormElements.end(); ++it) 
	{
		if (it->first == l && it->second == t)
		{
			return true;
		}
	}

	return false;
}

std::pair<int, int> SnakeRevival::composite::WormBody::GetSnakeHeadPosition()
{
	return m_WormElements.back(); 
}
void SnakeRevival::composite::WormBody::SetSnakeDirection(Direction nextDirection) 
{
	m_SnakeDirection = nextDirection;
}
Direction SnakeRevival::composite::WormBody::GetSnakeDirection() 
{
	return m_SnakeDirection;
}

void SnakeRevival::composite::WormBody::Grow(int value)
{
	m_MaxLenght += value;
}

void SnakeRevival::composite::WormBody::Clear()
{
	m_MaxLenght = 2;
	m_WormElements.clear();
}