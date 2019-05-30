#pragma once
#include "Draw.h"

namespace SnakeRevival {
	namespace composite {
		class WLetter :
			public Draw
		{
		public:
			WLetter();
			~WLetter();

			virtual int GetWidth();
			virtual int GetHeight();
			virtual std::wstring GetRow(int num);
		};
	}
}