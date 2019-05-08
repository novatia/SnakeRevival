#pragma once
#include "gameproj.h";

namespace gameproj {
	namespace commands
	{


		class ICommand
		{
		public:
			ICommand();
			virtual ~ICommand();

			virtual void execute(Player snakePl) = 0;
		};

	}
}

