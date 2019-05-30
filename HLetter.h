#pragma once
#include "Draw.h"
#include <string>

namespace gamestructure {
	namespace composite {
		class HLetter :
			public Draw
		{
		public:
			HLetter();
			~HLetter();

			virtual int GetWidth();
			virtual int GetHeight();
			virtual std::wstring GetRow(int num);
		};
	}
}