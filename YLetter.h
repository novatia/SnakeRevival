#pragma once
#include "Draw.h"

namespace SnakeRevival {
	namespace composite {
		class YLetter :
			public Draw
		{
		public:
			YLetter();
			~YLetter();

			virtual int GetWidth();
			virtual int GetHeight();
			virtual std::wstring GetRow(int num);
		};
	}
}