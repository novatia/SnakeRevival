#pragma once
#include "Draw.h"

namespace SnakeRevival {
	namespace composite {
		class NLetter :
			public Draw
		{
		public:
			NLetter();
			~NLetter();

			virtual int GetWidth();
			virtual int GetHeight();
			virtual std::wstring GetRow(int num);
		};
	}
}