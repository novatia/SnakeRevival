#pragma once
#include "Draw.h"
#include <string>

namespace gamestructure {
	namespace composite {
		class PLetter :
			public Draw
		{
		public:
			PLetter();
			~PLetter();

			virtual int GetWidth();
			virtual int GetHeight();
			virtual std::wstring GetRow(int num);
		};
	}
}