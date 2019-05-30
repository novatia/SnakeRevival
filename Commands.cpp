#include "pch.h"
#include "Commands.h"

using namespace SnakeRevival;
using namespace commands;

void MoveRightCommand::execute() 
{
	snake->SetCurrentDirection(Direction::Right);
}

void MoveLeftCommand::execute() 
{
	snake->SetCurrentDirection(Direction::Left);
}

void MoveUpCommand::execute()
{
	snake->SetCurrentDirection(Direction::Up);
}

void MoveDownCommand::execute() 
{
	snake->SetCurrentDirection(Direction::Down);
}

MoveRightCommand::MoveRightCommand(Player* initSnake): snake(initSnake) 
{
	
}

MoveRightCommand::~MoveRightCommand()
{

}

MoveLeftCommand::MoveLeftCommand(Player* initSnake) : snake(initSnake) 
{

}

MoveLeftCommand::~MoveLeftCommand() 
{

}

MoveUpCommand::MoveUpCommand(Player* initSnake) : snake(initSnake) 
{

}

MoveUpCommand::~MoveUpCommand() 
{

}

MoveDownCommand::MoveDownCommand(Player* initSnake) : snake(initSnake) 
{

}

MoveDownCommand::~MoveDownCommand() 
{

}
