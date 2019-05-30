#pragma once
#include "Draw.h"
#include <string>

namespace gamestructure {
	namespace composite {
		class CLetter :
			public Draw
		{
		public:
			CLetter();
			~CLetter();

			virtual int GetWidth();
			virtual int GetHeight();
			virtual std::wstring GetRow(int num);
		};
	}
}