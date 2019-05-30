#pragma once
#include "Page.h"

namespace gamestructure {
	class MainMenu :
		public composite::Page
	{
	public:
		MainMenu();
		~MainMenu();

		std::wstring GetView();
	};
}