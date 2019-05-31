#pragma once

namespace SnakeRevival
{
	namespace strategy
	{
		class IActionListener {
			public:
				IActionListener();
				~IActionListener();

				virtual void ActionPerformed();
				
		};
	}
}
