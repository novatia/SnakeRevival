#pragma once
#include "VerticalLayout.h"
#include "HorizontalLayout.h"
#include "LayerLayout.h"
#include <memory.h>

namespace SnakeRevival {
	namespace composite {
		class Page

		{
		public:
			Page();
			virtual ~Page();
			virtual std::wstring GetView();
		protected:
			std::unique_ptr<LayerLayout> m_RootObject;
		};
	}
}
