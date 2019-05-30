#pragma once
#include "Draw.h"

namespace SnakeRevival {
	namespace composite {
		class SPACELetter :
			public Draw
		{
		public:
			SPACELetter();
			~SPACELetter();

			virtual int GetWidth();
			virtual int GetHeight();
			virtual std::wstring GetRow(int num);
		};
	}
}