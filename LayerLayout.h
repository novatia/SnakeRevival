#pragma once
#include "Draw.h"

namespace SnakeRevival {
	namespace composite {
		class LayerLayout :
			public Draw
		{
		public:
			LayerLayout();
			~LayerLayout();
			void Add(Draw &element, int layer);

			virtual int GetWidth();
			virtual int GetHeight();
			virtual std::wstring GetRow(int num);

		private:
			std::map<int, std::vector< Draw* >> m_Elements;
		};
	}
}