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

		int height = GetHeight();
			draw += GetRow(row);
			draw += "\n";
		}
	}
};
