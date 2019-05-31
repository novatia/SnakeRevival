#pragma once
#include "IEntity.h"
#include <string>

namespace SnakeRevival {
	namespace composite {
		class Draw: public IEntity
		{
		public:
			virtual int GetWidth() = 0;
			virtual int GetHeight() = 0;
			virtual std::wstring GetRow(int num) = 0;

			void SetColor(Color new_color);
			std::wstring GetColor();
			std::wstring GetEndColor();

			void SetPosition(int left,int top);
			std::pair<int, int> GetPosition();

			void SetAlignment(Alignment horizontal, Alignment vertical);
			std::pair<Alignment, Alignment> GetAlignment();
		protected:
			Color m_Color = Color::None;
			Alignment m_HorizontalAlignment = Alignment::Left;
			Alignment m_VerticalAlignment = Alignment::Top;

			int m_Top  = 0;
			int m_Left = 0;

			std::string m_Name;
		};
	}
}