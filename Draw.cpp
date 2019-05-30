#include "pch.h"
#include "Draw.h"
#include <string>

using namespace std;
using namespace gamestructure;
using namespace composite;

void gamestructure::composite::Draw::SetColor(Colors new_color)
{
	color = new_color;
}

void gamestructure::composite::Draw::SetPosition(int l,int t)
{
	top = t;
	left = l;
}

std::pair<int, int> gamestructure::composite::Draw::GetPosition()
{
	return std::pair<int, int>(left,top);
}

void gamestructure::composite::Draw::SetAlignment(Alignments horizontal, Alignments vertical)
{
	horizontal_alignment = horizontal;
	vertical_alignment = vertical;
}

pair<Alignments, Alignments> gamestructure::composite::Draw::GetAlignment()
{
	return pair<Alignments, Alignments>(horizontal_alignment,vertical_alignment);
}

wstring gamestructure::composite::Draw::GetColor()
{
	switch (color) {
	case Blue:return L"\x1B[34m";
	case Red:return L"\x1B[31m";
	case Green:return L"\x1B[32m";
	case Yellow:return L"\x1B[93m";
	case White:return L"\x1B[37m";
	case Purple:return L"\x1B[35m";
	}

	return L"";
}

wstring gamestructure::composite::Draw::GetEndColor()
{
	if (color != None)
		return L"\033[0m";

	return L"";
}
