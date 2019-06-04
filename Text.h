#pragma once
#include "Draw.h"
#include "IActionListener.h"

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
			virtual void SetText(std::wstring text);
			virtual std::wstring GetRow(int num);
			virtual void AddActionListener(strategy::IActionListener *ActionListener);
			strategy::IActionListener *m_ActionListener;
		private:
			std::wstring m_Text;
			
		};
	}
}