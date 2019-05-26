#include "pch.h"
#include "Commands.h"

void gamestructure::commands::MoveRightCommand::execute() {
	snake->SetCurrentDirection(Direction::Right);
}

void gamestructure::commands::MoveLeftCommand::execute() {
	snake->SetCurrentDirection(Direction::Left);

}

void gamestructure::commands::MoveUpCommand::execute() {
	snake->SetCurrentDirection(Direction::Up);
}

void gamestructure::commands::MoveDownCommand::execute() {
	snake->SetCurrentDirection(Direction::Down);

}

gamestructure::commands::MoveRightCommand::MoveRightCommand(Player* initSnake): snake(initSnake) {
	
}
gamestructure::commands::MoveRightCommand::~MoveRightCommand(){}

gamestructure::commands::MoveLeftCommand::MoveLeftCommand(Player* initSnake) : snake(initSnake) {

}
gamestructure::commands::MoveLeftCommand::~MoveLeftCommand() {}

gamestructure::commands::MoveUpCommand::MoveUpCommand(Player* initSnake) : snake(initSnake) {

}
gamestructure::commands::MoveUpCommand::~MoveUpCommand() {}

gamestructure::commands::MoveDownCommand::MoveDownCommand(Player* initSnake) : snake(initSnake) {

}
gamestructure::commands::MoveDownCommand::~MoveDownCommand() {}
