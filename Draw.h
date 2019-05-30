#pragma once
#include <string>

namespace gamestructure {
	namespace composite {
		class Draw
		{
		public:
			virtual int GetWidth() = 0;
			virtual int GetHeight() = 0;
			virtual std::wstring GetRow(int num) = 0;
		};
	}
}