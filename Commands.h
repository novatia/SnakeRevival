#pragma once
#include "gameelements.h"
#include "ICommand.h"

namespace SnakeRevival {
	namespace commands
	{

		class MoveRightCommand : ICommand {
		public:
			MoveRightCommand(Player* initSnake);
			virtual ~MoveRightCommand();
			virtual void execute();
		private:
			Player* snake;
		};

		class MoveLeftCommand : ICommand {
		public:
			MoveLeftCommand(Player* initSnake);
			virtual ~MoveLeftCommand();
			virtual void execute();
		private:
			Player* snake;
		};

		class MoveUpCommand : ICommand {
		public:
			MoveUpCommand(Player* initSnake);
			virtual ~MoveUpCommand();
			virtual void execute();
		private:
			Player* snake;
		};

		class MoveDownCommand : ICommand {
		public:
			MoveDownCommand(Player* initSnake);
			virtual ~MoveDownCommand();
			virtual void execute();
		private:
			Player* snake;
		};
	}
}


