#pragma once

namespace SnakeRevival {
	class DisplayBuffer
	{
	public:
		void printBuffer();
		void writeBuffer(const std::wstring&);
		void clearBuffer();

		DisplayBuffer();
		~DisplayBuffer();

	private:
		int width;
		int height;
		std::wstring buffer;
	};
}