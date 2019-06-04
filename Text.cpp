#include "pch.h"
#include "Text.h"

using namespace std;
using namespace SnakeRevival;
using namespace composite;

Text::Text(wstring text)
{
	m_Text = text;
}

Text::~Text()
{
}

int Text::GetWidth()
{
	return m_Text.size();
}

int Text::GetHeight()
{
	return 1;
}

void SnakeRevival::composite::Text::SetText(std::wstring text)
{
	m_Text = text;
}

wstring Text::GetRow(int num)
{
	wstring row = L"";
	wstring color = GetColor();

	if (num == m_Top)
	{
		if (m_Selected)
			row =  L"> "+ m_Text +L" <";
		else
			row =  m_Text;

		if (row != L"")
			row = Draw::Colorify(row, color);
	}

	return row;
}

void Text::AddActionListener(strategy::IActionListener* ActionListener)
{
	m_ActionListener = ActionListener;
}
