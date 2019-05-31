#pragma once
#include "IActionListener.h"

namespace SnakeRevival
{
	namespace strategy
	{
		class QuitAction : public IActionListener
		{
		public:
			virtual void ActionPerformed() override;
		};
	}
}