#pragma once
#include "Draw.h"
#include <string>

namespace SnakeRevival {
	namespace composite {
		class Fruit :
			public Draw
		{
		public:
			Fruit();
			~Fruit();

			virtual int GetWidth();
			virtual int GetHeight();
			virtual std::wstring GetRow(int num);
			int GetValue();
		private:
			int m_Value;
		};
	}
}