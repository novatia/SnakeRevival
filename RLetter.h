#pragma once
#include "Draw.h"

namespace SnakeRevival {
	namespace composite {
		class RLetter :
			public Draw
		{
		public:
			RLetter();
			~RLetter();

			virtual int GetWidth();
			virtual int GetHeight();
			virtual std::wstring GetRow(int num);
		};
	}
}