#pragma once
#include "Draw.h"

namespace SnakeRevival {
	namespace composite {
		class QLetter :
			public Draw
		{
		public:
			QLetter();
			~QLetter();

			virtual int GetWidth();
			virtual int GetHeight();
			virtual std::wstring GetRow(int num);
		};
	}
}