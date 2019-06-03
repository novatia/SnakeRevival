#include "pch.h"
#include "Draw.h"
#include <string>

using namespace std;
using namespace SnakeRevival;
using namespace composite;

void Draw::SetColor(Color new_color)
{
	m_Color = new_color;
}

void Draw::SetPosition(int l,int t)
{
	m_Top = t;
	m_Left = l;
}

std::pair<int, int> Draw::GetPosition()
{
	return std::pair<int, int>(m_Left,m_Top);
}

void Draw::SetAlignment(Alignment horizontal, Alignment vertical)
{
	m_HorizontalAlignment = horizontal;
	m_VerticalAlignment = vertical;
}

pair<Alignment, Alignment> Draw::GetAlignment()
{
	return pair<Alignment, Alignment>(m_HorizontalAlignment,m_VerticalAlignment);
}

wstring Draw::GetColor()
{
	switch (m_Color) {
	case Color::Blue:return L"\x1B[34m";
	case Color::Red:return L"\x1B[31m";
	case Color::Green:return L"\x1B[32m";
	case Color::Yellow:return L"\x1B[93m";
	case Color::White:return L"\x1B[37m";
	case Color::Purple:return L"\x1B[35m";
	}

	return L"";
}

wstring Draw::GetColor(Color m_Color)
{
	switch (m_Color) {
	case Color::Blue:return L"\x1B[34m";
	case Color::Red:return L"\x1B[31m";
	case Color::Green:return L"\x1B[32m";
	case Color::Yellow:return L"\x1B[93m";
	case Color::White:return L"\x1B[37m";
	case Color::Purple:return L"\x1B[35m";
	}

	return L"";
}

wstring Draw::GetEndColor()
{
	if (m_Color != Color::None)
		return L"\033[0m";

	return L"";
}


wstring Draw::Colorify(wstring row, wstring color) {
	wstring new_row = L"";

	
	for (int i = 0; i < row.size(); i++)
	{
		wchar_t ch = row[i];
		wstring ws (&ch,1);
		new_row.append(color);
		new_row.append(ws);
		new_row.append(L"\033[0m");
	}

	/*
	new_row.append(color);
	new_row.append(row);
	new_row.append(L"\033[0m");
	*/
	return new_row;
}