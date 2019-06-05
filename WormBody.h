#pragma once
#include "Draw.h"

namespace SnakeRevival {
	namespace composite {
		class WormBody :
			public Draw
		{
		public:
			int top = 0;
			bool selected = false;
			WormBody();
			~WormBody();

			virtual int GetWidth();
			virtual int GetHeight();
			virtual std::wstring GetRow(int num);
			void SetSnakePosition(int left, int top);
			bool CollisionCheck(int left, int top);
			std::pair<int, int> GetSnakeHeadPosition();
			void Grow(int);
			void Clear();

		private:
			int m_MaxLenght;
			std::vector<std::pair<int, int>> m_WormElements;
		};
	}
}