#include "pch.h"
#include "LayerLayout.h"
#include <vector>

using namespace std;
using namespace gamestructure;
using namespace composite;

int GetSizeNoColours(wstring string) {
	int real_size = string.size();
	int noc_size = 0;
	int ct = count(string.begin(), string.end(), '\x1B');
	ct /= 2;
	noc_size = real_size - COLOR_HEADER * ct;
	return noc_size;
}

wstring MergeStrings(wstring current_row, wstring str, pair<int,int> position, Alignments alignment, int W)
{
	wstring first_string = str;
	wstring second_string = current_row;

	if (GetSizeNoColours(current_row) > GetSizeNoColours(str))
	{
		first_string = current_row;
		second_string = str;
	}

	if (second_string.size() == 0)
		return first_string;

	//need to count colours
	int ct1 = count(first_string.begin(), first_string.end(), '\x1B')/2*COLOR_HEADER;
	int ct2 = count(second_string.begin(), second_string.end(), '\x1B')/2*COLOR_HEADER;

	//adding pad for color tags
	if (ct1 != 0 || ct2 != 0)
		first_string.insert(first_string.size() / 2, ct1+ ct2,' ');

	//center alignment
	int start_index = 0;

	if (alignment == Right) {
		start_index = W;
		start_index -= position.first;
	}
	else {
		if (alignment == Center)
			start_index += first_string.size() / 2 - second_string.size() / 2;

		start_index += position.first;
	}

	first_string.replace(start_index, second_string.size(), second_string);
	return first_string;
}

LayerLayout::LayerLayout()
{

}

LayerLayout::~LayerLayout()
{

}

void LayerLayout::Add(Draw& element, int layer)
{
	vector<Draw*>* current_layer = &elements[layer];

	if (current_layer == nullptr) {
		current_layer = new vector< Draw*>();
		elements.insert(pair<int, vector<Draw*>>(layer, *current_layer));
	}

	current_layer->push_back(&element);
}

int LayerLayout::GetWidth()
{
	int max_width = 0;
	map<int, vector<Draw*>>::iterator it;

	for (it = elements.begin(); it != elements.end(); ++it)
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

	for (it = elements.begin(); it != elements.end(); ++it)
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
	map<int, vector<Draw*>>::reverse_iterator rit;
	for (rit = elements.rbegin(); rit != elements.rend(); ++rit)
	for (vector<Draw*>::reverse_iterator i = rit->second.rbegin(); i != rit->second.rend(); ++i) {
		wstring str = (*i)->GetRow(num);
		current_row = MergeStrings(current_row,str, (*i)->GetPosition() , (*i)->GetAlignment().first ,GetWidth());
	}

	return current_row;
}
