#pragma once
#include "Draw.h"
#include <vector>

class VerticalLayout :
	public Draw
{
public:
	VerticalLayout();
	virtual ~VerticalLayout();
	void Add(Draw* element);

	virtual int GetWidth();
	virtual int GetHeight();
	virtual std::string GetRow(int num);

	operator std::string() {
		std::string draw;

		int height = GetHeight();

		for (int row = 0; row < height; row++) {
			draw += GetRow(row);
			draw += "\n";
		}

		return draw;
	}

private:
	std::vector<Draw> elements;
};

