#pragma once
#include "gameelements.h";

namespace gamestructure {
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

