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
	int num = row_num - m_Top;
	
	switch (num) {
	case 0: return L"\x1B[32m ┌" + to_wstring(m_Value) + L"\033[0m";
	case 1: return L"\x1B[31m███\033[0m";
	case 2: return L"\x1B[31m ▀ \033[0m";
	}

	return L"";
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
