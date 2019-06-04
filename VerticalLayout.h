#pragma once
#include "Draw.h"
#include <vector>

namespace SnakeRevival {
	namespace composite {
		class VerticalLayout :
			public Draw
		{
		public:
			VerticalLayout();
			virtual ~VerticalLayout();
			void Add(Draw* element);

			virtual int GetWidth();
			virtual int GetHeight();
			virtual std::wstring GetRow(int num);

		private:
			std::vector<Draw*> m_Elements;
		};
	}
}