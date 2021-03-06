#pragma once
#include "Page.h"

namespace SnakeRevival {
	namespace composite {
		class LevelFrame :
			public Draw
		{
		public:
			LevelFrame();
			virtual ~LevelFrame();

			virtual int GetWidth();
			virtual int GetHeight();
			virtual std::wstring GetRow(int num);
		};
	}
}

