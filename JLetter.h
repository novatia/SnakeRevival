#pragma once
#include "Draw.h"
#include <string>

namespace gamestructure {
	namespace composite {
		class JLetter :
			public Draw
		{
		public:
			JLetter();
			~JLetter();

			virtual int GetWidth();
			virtual int GetHeight();
			virtual std::wstring GetRow(int num);
		};
	}
}