#include "pch.h"
#include "LayerLayout.h"
#include <vector>

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

wstring MergeStrings(wstring current_row, wstring str, pair<int,int> position, Alignment alignment, int W,Color parent_color)
{
	wstring first_string = str;
	wstring second_string = current_row;

	if (GetSizeNoColours(current_row) > GetSizeNoColours(str))
	{
		first_string = current_row;
		second_string = str;
	}

	if (second_string == L"")
		return first_string;

	//need to count colours
	int ct1 = count(first_string.begin(), first_string.end(), '\x1B') / 2 * COLOR_HEADER;
	int ct2 = count(second_string.begin(), second_string.end(), '\x1B') / 2 * COLOR_HEADER;


	if (second_string.size() == 0) {
		if (alignment == Alignment::Right)
			first_string.insert(0, (W-first_string.size() + position.first),' ');

		if (alignment == Alignment::Left) {
			int left_index = (W - first_string.size() + position.first);

			if (left_index < 0)
				left_index = 0;

			first_string.append(left_index, ' ');
		}
		if (alignment == Alignment::Center) {
			int first_size = first_string.size();
			unsigned int left_index = (W - first_size) / 2 + position.first;
			if (left_index < 0)
				left_index = 0;

			first_string.insert(0, left_index, ' ');
		}
		return first_string;
	}


	//adding pad for color tags
	if ( ct2 != 0 )
		first_string.insert(first_string.size() / 2, ct2,' ');

	//center alignment
	int start_index = 0;

	if (alignment == Alignment::Right) {
		start_index = W;
		start_index -= position.first;
	}

	else {
		if (alignment == Alignment::Center)
			start_index += first_string.size() / 2 - second_string.size() / 2;

		start_index += position.first;
	}

	first_string.replace(start_index, second_string.size(), second_string);
	return first_string;
}


wstring EmptyColorifiedString(int size, wstring color ) {
	wstring res_string= L"";
	for (int i = 0; i < size-1;i++)
	{
		res_string += color + L" " + L"\033[0m";
	}

	return res_string;
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
		left_offset = (current_row.size()/10 - row.size() / 10 + position.first);

	if (alignment.first == Alignment::Left) 
		left_offset = (current_row.size() / 10 - row.size() / 10 + position.first);

	if (alignment.first == Alignment::Center) 
		left_offset = (current_row.size() / 10 - row.size() / 10) / 2 + position.first;

	if (alignment.first == Alignment::None)
		left_offset = position.first;

	if (left_offset < 0)
		left_offset = 0;

	//APPLY LEFT ALIGNMENT
	if (alignment.first == Alignment::Right )
		row.append( EmptyColorifiedString(left_offset, draw->GetColor()));

	if (alignment.first == Alignment::Left || alignment.first == Alignment::None)
		row.insert(0, EmptyColorifiedString(left_offset, draw->GetColor()));

	if (alignment.first == Alignment::Center)
		{
			wstring pad = EmptyColorifiedString(left_offset, draw->GetColor());
			row.insert(0, pad);
			row.append(pad);
		}

	int string_index = 0;

	for (int i = 5; i < current_row.size(); i += 10) {
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
			if ((*vit)->GetHeight() > max_height)
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
