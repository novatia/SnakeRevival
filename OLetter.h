#pragma once
#include "Draw.h"

namespace SnakeRevival {
	namespace composite {
		class OLetter :
			public Draw
		{
		public:
			OLetter();
			~OLetter();

			virtual int GetWidth();
			virtual int GetHeight();
			virtual std::wstring GetRow(int num);
		};
	}
}