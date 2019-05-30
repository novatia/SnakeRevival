#pragma once
#include "VerticalLayout.h"
#include "HorizontalLayout.h"
#include "LayerLayout.h"
#include <memory.h>

namespace gamestructure {
	namespace composite {
		class Page

		{
		public:
			Page();
			virtual ~Page();

		protected:
			std::unique_ptr<LayerLayout> root_object;
		};
	}
}
