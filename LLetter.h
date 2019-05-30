#pragma once
#include "Draw.h"

namespace SnakeRevival {
	namespace composite {
		class LLetter :
			public Draw
		{
		public:
			LLetter();
			~LLetter();

			virtual int GetWidth();
			virtual int GetHeight();
			virtual std::wstring GetRow(int num);
		};
	}
}