#include "pch.h"
#include "DisplayBuffer.h"


DisplayBuffer::DisplayBuffer()
{
}


DisplayBuffer::~DisplayBuffer()
{
}
void DisplayBuffer::printBuffer() {

	std::cout << buffer;

}
void DisplayBuffer::writeBuffer(std::string& input) {
	buffer.assign(input);
}
void DisplayBuffer::clearBuffer() {
	buffer.clear();

}
