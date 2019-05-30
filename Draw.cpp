#include "pch.h"
#include "Draw.h"
#include <string>

using namespace std;
using namespace SnakeRevival;
using namespace composite;

void Draw::SetColor(Colors new_color)
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

void Draw::SetAlignment(Alignments horizontal, Alignments vertical)
{
	m_HorizontalAlignment = horizontal;
	m_VerticalAlignment = vertical;
}

pair<Alignments, Alignments> Draw::GetAlignment()
{
	return pair<Alignments, Alignments>(m_HorizontalAlignment,m_VerticalAlignment);
}

wstring Draw::GetColor()
{
	switch (m_Color) {
	case Blue:return L"\x1B[34m";
	case Red:return L"\x1B[31m";
	case Green:return L"\x1B[32m";
	case Yellow:return L"\x1B[93m";
	case White:return L"\x1B[37m";
	case Purple:return L"\x1B[35m";
	}

	return L"";
}

wstring Draw::GetEndColor()
{
	if (m_Color != None)
		return L"\033[0m";

	return L"";
}
