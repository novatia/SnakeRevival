#pragma once
#include <string>

class Draw
{
public:
	Draw();
	virtual ~Draw();
	virtual int GetWidth() = 0;
	virtual int GetHeight() = 0;
	virtual std::string GetRow(int num) = 0;

	operator std::string() {
		std::string draw;

		int height = GetHeight();		for (int row = 0; row < height; row++) {
			draw += GetRow(row);
			draw += "\n";
		}		return draw;
	}
};

