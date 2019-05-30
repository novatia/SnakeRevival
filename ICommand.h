#pragma once

namespace SnakeRevival {
	namespace commands
	{
		class ICommand
		{
		public:
			ICommand();
			virtual ~ICommand();

			virtual void execute() = 0;
		};

	}
}

