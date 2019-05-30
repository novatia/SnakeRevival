#pragma once
#include "Draw.h"
#include <string>

namespace gamestructure {
	namespace composite {
		class XLetter :
			public Draw
		{
		public:
			XLetter();
			~XLetter();

			virtual int GetWidth();
			virtual int GetHeight();
			virtual std::wstring GetRow(int num);
		};
	}
}