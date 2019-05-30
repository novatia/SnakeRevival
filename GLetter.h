#pragma once
#include "Draw.h"
#include <string>

namespace gamestructure {
	namespace composite {
		class GLetter :
			public Draw
		{
		public:
			GLetter();
			~GLetter();

			virtual int GetWidth();
			virtual int GetHeight();
			virtual std::wstring GetRow(int num);
		};
	}
}