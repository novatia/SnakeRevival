#pragma once
#include "Draw.h"

namespace SnakeRevival {
	namespace composite {
		class HLetter :
			public Draw
		{
		public:
			HLetter();
			~HLetter();

			virtual int GetWidth();
			virtual int GetHeight();
			virtual std::wstring GetRow(int num);
		};
	}
}