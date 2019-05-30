#pragma once
#include "Page.h"

namespace gamestructure {
	class GameOver :
		public composite::Page
	{
	public:
		GameOver();
		~GameOver();

		std::wstring GetView();
	};
}