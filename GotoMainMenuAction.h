#pragma once
#include "IActionListener.h"

namespace SnakeRevival
{
	namespace strategy
	{
		class GotoMainMenuAction : public IActionListener
		{
		public:
			virtual void ActionPerformed() override;
		};
	}
}