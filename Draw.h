#pragma once
#include <string>



namespace gamestructure {
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
			Colors color = None;
			Alignments horizontal_alignment = Left;
			Alignments vertical_alignment = Top;

			int top  = 0;
			int left = 0;
		};
	}
}