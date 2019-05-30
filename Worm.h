#pragma once
#include "Draw.h"
#include <string>
#include <vector>

namespace gamestructure {
	namespace composite {
		class Worm :
			public Draw
		{
		public:
			int top = 0;
			bool selected = false;
			Worm(std::wstring text);
			~Worm();

			virtual int GetWidth();
			virtual int GetHeight();
			virtual std::wstring GetRow(int num);
			void AddElement(int left, int top);
		private:
			std::wstring txt;
			int width;
			int height;
			std::vector<std::pair<int, int>> elements;
		};
	}
}