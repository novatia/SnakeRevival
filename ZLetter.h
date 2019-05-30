#pragma once
#include "Draw.h"

namespace SnakeRevival {
	namespace composite {
		class ZLetter :
			public Draw
		{
		public:
			ZLetter();
			~ZLetter();

			virtual int GetWidth();
			virtual int GetHeight();
			virtual std::wstring GetRow(int num);
		};
	}
}