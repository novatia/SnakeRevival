#pragma once
#include "Draw.h"

namespace SnakeRevival {
	namespace composite {
		class ULetter :
			public Draw
		{
		public:
			ULetter();
			~ULetter();

			virtual int GetWidth();
			virtual int GetHeight();
			virtual std::wstring GetRow(int num);
		};
	}
}