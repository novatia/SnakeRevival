#pragma once
#include "Draw.h"

namespace SnakeRevival {
	namespace composite {
		class CLetter :
			public Draw
		{
		public:
			CLetter();
			~CLetter();

			virtual int GetWidth();
			virtual int GetHeight();
			virtual std::wstring GetRow(int num);
		};
	}
}