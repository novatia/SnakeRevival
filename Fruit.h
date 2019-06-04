#pragma once
#include "Draw.h"

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
			void RandomValue();
		private:
			int m_Value;
		};
	}
}