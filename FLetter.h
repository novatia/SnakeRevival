#pragma once
#include "Draw.h"
#include <string>

namespace gamestructure {
	namespace composite {
		class FLetter :
			public Draw
		{
		public:
			FLetter();
			~FLetter();

			virtual int GetWidth();
			virtual int GetHeight();
			virtual std::wstring GetRow(int num);
		};
	}
}