#pragma once
#include "IEntity.h"

namespace SnakeRevival {
	namespace composite {
		class Draw: public IEntity
		{
		public:
			Draw();
			virtual int GetWidth() = 0;
			virtual int GetHeight() = 0;
			virtual std::wstring GetRow(int num) = 0;

			void SetColor(Color new_color);
			std::wstring GetColor();
			static std::wstring GetColor(Color);
			std::wstring GetEndColor();
			static std::wstring Colorify(std::wstring, std::wstring);

			virtual void SetPosition(int left,int top);
			std::pair<int, int> GetPosition();

			void SetAlignment(Alignment horizontal, Alignment vertical);
			std::pair<Alignment, Alignment> GetAlignment();
		protected:
			Color m_Color = Color::White;
			Alignment m_HorizontalAlignment = Alignment::Left;
			Alignment m_VerticalAlignment = Alignment::Top;

			int m_Top  = 0;
			int m_Left = 0;

			std::string m_Name;
		};
	}
}