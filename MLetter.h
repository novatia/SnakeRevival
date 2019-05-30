#pragma once
#include "Draw.h"
#include <string>

namespace gamestructure {
	namespace composite {
		class MLetter :
			public Draw
		{
		public:
			MLetter();
			~MLetter();

			virtual int GetWidth();
			virtual int GetHeight();
			virtual std::wstring GetRow(int num);
		};
	}
}