#pragma once
#include "Page.h"

namespace SnakeRevival {
	namespace composite {
		class Level1 :
			public Page
		{
		public:
			Level1();
			~Level1();
			virtual void execute();
		};
	}
}