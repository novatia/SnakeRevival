#include "pch.h"
#include "Fruit.h"

using namespace std;
using namespace SnakeRevival;
using namespace composite;

Fruit::Fruit()
{
	RandomValue();
}

Fruit::~Fruit()
{

}

wstring Fruit::GetRow(int r_num)
{
	int num = r_num - m_Top;

	if (num < 0)
		return L"";

	wstring row = L"";
	wstring red_color = L"\x1B[31m";
	wstring green_color = L"\x1B[32m";

	//wstring c = GetColor(Color::White);
	//wstring leftPad = EmptyColorifiedString(m_Left, c);
	//row.insert(0, leftPad);


	switch (num) {
	case 0: row.append(Draw::Colorify(L" ┌" + to_wstring(m_Value), green_color)); break;
	case 1: row.append(Draw::Colorify(L"███", red_color)); break;
	case 2: row.append(Draw::Colorify(L" ▀ ", red_color)); break;
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

void Fruit::RandomValue() {
	m_Value = rand() % (10 - 1 + 1) + 1;
}