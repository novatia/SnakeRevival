#pragma once
#include "Draw.h"
#include <string>

namespace SnakeRevival {
	namespace composite {
		class ILetter :
			public Draw
		{
		public:
			ILetter();
			~ILetter();

			virtual int GetWidth();
			virtual int GetHeight();
			virtual std::wstring GetRow(int num);
		};
	}
}