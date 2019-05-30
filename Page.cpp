#include "pch.h"
#include "Page.h"

using namespace SnakeRevival;
using namespace composite;

Page::Page()
{

}

Page::~Page()
{

}

std::wstring Page::GetView()
{
		std::wstring draw;

		int height = m_RootObject->GetHeight();

		for (int row = 0; row < height; row++) {
			draw += m_RootObject->GetRow(row);
			draw += L"\n";
		}

		return draw;
}
