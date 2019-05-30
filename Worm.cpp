#include "pch.h"
#include "Worm.h"

using namespace std;
using namespace gamestructure;
using namespace composite;

Worm::Worm()
{
	
}

Worm::~Worm()
{
}

int Worm::GetWidth()
{
	return width;
}

int Worm::GetHeight()
{
	return height;
}

wstring Worm::GetRow(int num)
{
	return L"";
}

void gamestructure::composite::Worm::AddElement(int left, int top)
{
	elements.push_back( pair<int, int>(left, top) );
}
