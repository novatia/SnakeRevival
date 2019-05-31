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

wstring Text::GetRow(int num)
{

	wstring color = GetColor();
	wstring endcolor = GetEndColor();

	if (num < m_Top)
		return L"";

	if (num == m_Top)
	{
		if (m_Selected)
			return color + L"> "+ m_Text +L" <"+ endcolor;
		else
			return color + m_Text + endcolor;
	}

	return L"";
}

void Text::AddActionListener(strategy::IActionListener* ActionListener)
{
	m_ActionListener = ActionListener;
}
