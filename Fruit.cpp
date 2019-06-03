#include "pch.h"
#include "Fruit.h"
#include <string>

using namespace std;
using namespace SnakeRevival;
using namespace composite;

Fruit::Fruit()
{
	m_Value = rand() % 9 + 1;
}


Fruit::~Fruit()
{

}

wstring Fruit::GetRow(int row_num)
{
	wstring row = L"";
	wstring red_color = L"\x1B[31m";
	wstring green_color = L"\x1B[32m";

	int num = row_num - m_Top;
	
	switch (num) {
	case 0: row = Draw::Colorify(L" ┌" + to_wstring(m_Value), green_color); break;
	case 1: row = Draw::Colorify(L"███", red_color); break;
	case 2: row = Draw::Colorify(L" ▀ ", red_color); break;
	}

	return row;
}

int Fruit::GetValue()
{
	return m_Value;
}

int Fruit::GetWidth()
{
	return 3;
}

int Fruit::GetHeight()
{
	return 3;
}
