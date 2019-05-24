#pragma once
#include <string>

class Draw
{
public:
	Draw();
	virtual ~Draw();

	virtual int GetWidth() {
		return 0;
	}

	virtual int GetHeight() {
		return 0;
	}

	virtual std::string GetRow(int num) {
		return "";
	}

	operator std::string() {
		std::string draw;

		int height = GetHeight();

		for (int row = 0; row < height; row++) {
			draw += GetRow(row);
			draw += "\n";
		}

		return draw;
	}
};

