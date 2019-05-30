#pragma once
#include <string>

namespace SnakeRevival {
	namespace composite {
		class Draw
		{
		public:
			virtual int GetWidth() = 0;
			virtual int GetHeight() = 0;
			virtual std::wstring GetRow(int num) = 0;

			void SetColor(Colors new_color);
			std::wstring GetColor();
			std::wstring GetEndColor();

			void SetPosition(int left,int top);
			std::pair<int, int> GetPosition();

			void SetAlignment(Alignments horizontal, Alignments vertical);
			std::pair<Alignments, Alignments> GetAlignment();
		protected:
			Colors m_Color = None;
			Alignments m_HorizontalAlignment = Left;
			Alignments m_VerticalAlignment = Top;

			int m_Top  = 0;
			int m_Left = 0;

			std::string m_Name;
		};
	}
}