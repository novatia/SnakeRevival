#pragma once
#pragma once
#include "Page.h"

namespace gamestructure {
	class Level1 :
		public composite::Page
	{
	public:
		Level1();
		~Level1();

		std::wstring GetView();
	};
}