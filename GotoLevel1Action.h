#pragma once
#include "IActionListener.h"

namespace SnakeRevival
{
	namespace strategy
	{
		class GotoLevel1Action : public IActionListener
		{
		public:
			virtual void ActionPerformed() override;
		};
	}
}