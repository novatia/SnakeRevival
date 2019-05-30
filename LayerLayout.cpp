#include "pch.h"
#include "LayerLayout.h"
#include <vector>

using namespace std;
using namespace gamestructure;
using namespace composite;

wstring MergeStrings(wstring current_row, wstring str) {
	wstring first_string = str;
	wstring second_string = current_row;

	if (current_row.size() > str.size())
	{
		first_string = current_row;
		second_string = str;
	}

	if (second_string.size() == 0)
		return first_string;

	int start_index = first_string.size() / 2 - second_string.size() / 2;

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
		current_row = MergeStrings(current_row,str);
	}

	return current_row;
}
