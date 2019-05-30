#pragma once
#include "Page.h"

namespace gamestructure {
	namespace composite {
		class Frame :
			public Draw
		{
		public:
			Frame();
			virtual ~Frame();

			virtual int GetWidth();
			virtual int GetHeight();
			virtual std::wstring GetRow(int num);
		};
	}
}

