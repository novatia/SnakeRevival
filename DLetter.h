#pragma once
#include "Draw.h"

namespace SnakeRevival {
	namespace composite {
		class DLetter :
			public Draw
		{
		public:
			DLetter();
			~DLetter();

			virtual int GetWidth();
			virtual int GetHeight();
			virtual std::wstring GetRow(int num);
		};
	}
}