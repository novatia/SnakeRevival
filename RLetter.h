#pragma once
#include "Draw.h"
#include <string>

namespace gamestructure {
	namespace composite {
		class RLetter :
			public Draw
		{
		public:
			RLetter();
			~RLetter();

			virtual int GetWidth();
			virtual int GetHeight();
			virtual std::wstring GetRow(int num);
		};
	}
}