#pragma once
#include "Draw.h"
#include <vector>

namespace gamestructure {
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

			operator std::wstring() {
				std::wstring draw;

				int height = GetHeight();

				for (int row = 0; row < height; row++) {
					draw += GetRow(row);
					draw += L"\n";
				}

				return draw;
			}

		private:
			std::vector<Draw*> elements;
		};
	}
}