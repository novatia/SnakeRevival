#pragma once
#include "DisplayBuffer.h"

namespace SnakeRevival {
	class Display
	{
	public:
		Display();
		~Display();

		void PresentDisplay();
		void WriteNextDisplay(const std::wstring& input);

	private:
		void Swap();

		DisplayBuffer views[2];
		DisplayBuffer* currentView_;
		DisplayBuffer* nextView_;
	};
}