#pragma once
#pragma once
#include "IActionListener.h"

namespace SnakeRevival
{
	namespace strategy
	{
		class GotoGameOverAction : public IActionListener
		{
		public:
			virtual void ActionPerformed() override;
		};
	}
}