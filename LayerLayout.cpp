#include "pch.h"
#include "LayerLayout.h"

using namespace std;
using namespace SnakeRevival;
using namespace composite;

int GetSizeNoColours(wstring string) {
	int real_size = string.size();
	int noc_size = 0;
	int ct = count(string.begin(), string.end(), '\x1B');
	ct /= 2;
	noc_size = real_size - COLOR_HEADER * ct;
	return noc_size;
}

wstring TransparentMergeStrings(wstring current_row, Draw* draw, int row_num)
{
	wstring row = draw->GetRow(row_num);

	if (row == L"")
		return current_row;

	if (current_row == L"")
		return row;

	int left_offset = 0;

	pair<Alignment, Alignment> alignment = draw->GetAlignment();
	pair<int, int> position = draw->GetPosition();

	//CALCULATE LEFT OFFSET FOR ALIGNMENT
	if (alignment.first == Alignment::Right)
		left_offset = (current_row.size()/10 - row.size() / 10 - position.first);

	if (alignment.first == Alignment::Left || alignment.first == Alignment::None)
		left_offset = (position.first);

	if (alignment.first == Alignment::Center) 
		left_offset = (current_row.size() / 10 - row.size() / 10) / 2 + position.first;

	if (left_offset < 0)
		left_offset = 0;

	//APPLY LEFT ALIGNMENT
	if (alignment.first == Alignment::Right||alignment.first == Alignment::Left || alignment.first == Alignment::None)
		row.insert(0, EmptyColorifiedString(left_offset, draw->GetColor()));

	if (alignment.first == Alignment::Center)
		{
			wstring pad = EmptyColorifiedString(left_offset, draw->GetColor());
			row.insert(0, pad);
			row.append(pad);
		}

	int string_index = 0;

	for (unsigned int i = 5; i < current_row.size(); i += 10) {
		wchar_t ch = current_row[i];

		if (i >= row.size())
			break; //MERGED

		if (ch == ' ' && row[i] != ' ') {
			wstring char_block = row.substr(i - 5, 10);
			//copy color and content
			current_row.replace(i-5,10, char_block);
		}
	}

	return current_row;
}



LayerLayout::LayerLayout()
{

}

LayerLayout::~LayerLayout()
{

}

void LayerLayout::Add(Draw& element, int layer)
{
	vector<Draw*>* current_layer = &m_Elements[layer];

	if (current_layer == nullptr) {
		current_layer = new vector< Draw*>();
		m_Elements.insert(pair<int, vector<Draw*>>(layer, *current_layer));
	}

	current_layer->push_back(&element);
}

int LayerLayout::GetWidth()
{
	int max_width = 0;
	map<int, vector<Draw*>>::iterator it;

	for (it = m_Elements.begin(); it != m_Elements.end(); ++it)
	{
		for (vector<Draw*>::iterator vit = it->second.begin(); vit != it->second.end(); ++vit) 
		{
			if ((*vit)->GetWidth() > max_width) 
			{
				max_width = (*vit)->GetWidth();
			}
		}
	}

	//get maximum width
	return max_width;
}

int LayerLayout::GetHeight()
{
	int max_height = 0;
	map<int, vector<Draw*>>::iterator it;

	for (it = m_Elements.begin(); it != m_Elements.end(); ++it)
	{
		for (vector<Draw*>::iterator vit = it->second.begin(); vit != it->second.end(); ++vit)
		{
			int height = (*vit)->GetHeight();
			if (height > max_height)
			{
				max_height = (*vit)->GetHeight();
			}
		}
	}
	//get maximum height
	return max_height;
}

wstring  LayerLayout::GetRow(int num)
{
	wstring current_row = L"";
	map<int, vector<Draw*>>::iterator level_It;
	for (level_It = m_Elements.begin(); level_It != m_Elements.end(); ++level_It)
	{
		for (vector<Draw*>::reverse_iterator i = level_It->second.rbegin(); i != level_It->second.rend(); ++i)
		{
			//current_row = MergeStrings(current_row, str, (*i)->GetPosition(), (*i)->GetAlignment().first, GetWidth(),Color::None);
			current_row = TransparentMergeStrings(current_row, (*i), num);
		}
	}

	return current_row;
}
