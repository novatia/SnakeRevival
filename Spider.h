#pragma once
#pragma once
#include "Draw.h"

namespace SnakeRevival {
	namespace composite {
		class Spider :
			public Draw
		{
		public:
			Spider();
			~Spider();

			virtual int GetWidth();
			virtual int GetHeight();
			virtual std::wstring GetRow(int num);
			int GetValue();
			void RandomValue();
		private:
			int m_Value;
		};
	}
}
