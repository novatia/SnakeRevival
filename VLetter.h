#pragma once
#include "Draw.h"

namespace SnakeRevival {
	namespace composite {
		class VLetter :
			public Draw
		{
		public:
			VLetter();
			~VLetter();

			virtual int GetWidth();
			virtual int GetHeight();
			virtual std::wstring GetRow(int num);
		};
	}
}