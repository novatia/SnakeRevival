#pragma once
#include "Draw.h"

namespace SnakeRevival {
	namespace composite {
		class XLetter :
			public Draw
		{
		public:
			XLetter();
			~XLetter();

			virtual int GetWidth();
			virtual int GetHeight();
			virtual std::wstring GetRow(int num);
		};
	}
}