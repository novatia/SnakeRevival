#pragma once
#include "Draw.h"

namespace SnakeRevival {
	namespace composite {
		class WormBody :
			public Draw
		{
		public:
			int top = 0;
			bool selected = false;
			WormBody();
			~WormBody();

			virtual int GetWidth();
			virtual int GetHeight();
			virtual std::wstring GetRow(int num);
		};
	}
}