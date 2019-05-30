#pragma once
#include "Draw.h"
#include <string>

namespace gamestructure {
	namespace composite {
		class Text :
			public Draw
		{
		public:
			int top=0;
			bool selected = false;
			Text(std::wstring text);
			~Text();

			virtual int GetWidth();
			virtual int GetHeight();
			virtual std::wstring GetRow(int num);
		private:
			std::wstring txt;
		};
	}
}