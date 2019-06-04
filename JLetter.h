#pragma once
#include "Draw.h"

namespace SnakeRevival {
	namespace composite {
		class JLetter :
			public Draw
		{
		public:
			JLetter();
			~JLetter();

			virtual int GetWidth();
			virtual int GetHeight();
			virtual std::wstring GetRow(int num);
		};
	}
}