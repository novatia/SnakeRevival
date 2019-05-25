#pragma once

class DisplayBuffer
{
public:
	void printBuffer();
	void writeBuffer(std::string&);
	void clearBuffer();

	DisplayBuffer();
	~DisplayBuffer();

private:
	int width;
	int height;
	std::string buffer;

};
