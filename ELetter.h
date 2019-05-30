#pragma once
#include "Draw.h"
#include <string>

namespace SnakeRevival {
	namespace composite {
		class ELetter :
			public Draw
		{
		public:
			ELetter();
			~ELetter();

			virtual int GetWidth();
			virtual int GetHeight();
			virtual std::wstring GetRow(int num);
		};
	}
}