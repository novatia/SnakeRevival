#pragma once
#include "Draw.h"

namespace SnakeRevival {
	namespace composite {
		class ALetter :
			public Draw
		{
		public:
			ALetter();
			~ALetter();

			virtual int GetWidth();
			virtual int GetHeight();
			virtual std::wstring GetRow(int num);
		};
	}
}