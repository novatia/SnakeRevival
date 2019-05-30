#pragma once
#include "Draw.h"
#include <string>

namespace gamestructure {
	namespace composite {

		class KLetter :
			public Draw
		{
		public:
			KLetter();
			~KLetter();

			virtual int GetWidth();
			virtual int GetHeight();
			virtual std::wstring GetRow(int num);
		};
	}
}