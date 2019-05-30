#pragma once
#include "Draw.h"

namespace SnakeRevival {
	namespace composite {
		class SLetter :
			public Draw
		{
		public:
			SLetter();
			~SLetter();

			virtual int GetWidth();
			virtual int GetHeight();
			virtual std::wstring GetRow(int num);
		};
	}
}