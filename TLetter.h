#pragma once
#include "Draw.h"
#include <string>

namespace gamestructure {
	namespace composite {
		class TLetter :
			public Draw
		{
		public:
			TLetter();
			~TLetter();

			virtual int GetWidth();
			virtual int GetHeight();
			virtual std::wstring GetRow(int num);
		};
	}
}