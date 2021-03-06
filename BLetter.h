#pragma once
#include "Draw.h"

namespace SnakeRevival {
	namespace composite {
		class BLetter :
			public Draw
		{
		public:
			BLetter();
			~BLetter();

			virtual int GetWidth();
			virtual int GetHeight();
			virtual std::wstring GetRow(int num);
		};
	}
}