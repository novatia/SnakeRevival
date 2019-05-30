#pragma once
#include "Draw.h"

namespace SnakeRevival {
	namespace composite {
		class Text :
			public Draw
		{
		public:
			bool m_Selected = false;
			Text(std::wstring text);
			~Text();

			virtual int GetWidth();
			virtual int GetHeight();
			virtual std::wstring GetRow(int num);
		private:
			std::wstring m_Text;
		};
	}
}