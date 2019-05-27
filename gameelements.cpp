#include "pch.h"
#include "gameelements.h"
using namespace std;

void gamestructure::Player::MoveSnake() {
	position nextPosition= snake->front();
	switch (currentDirection) {
	case Direction::Right:
		nextPosition.x++;
		break;
	case Direction::Left:
		nextPosition.x--;
		break;
	case Direction::Up:
		nextPosition.y--;
		break;
	case Direction::Down:
		nextPosition.y++;
		break;
	}
	position tempPosition;
	for (unsigned index = 0; index < snake->size(); index++) {
		tempPosition = snake->at(index);
		snake->emplace(index,nextPosition);
		nextPosition = tempPosition;

	}
}

void  gamestructure::Player::SetCurrentDirection(Direction newDirection) {
	if (currentDirection == Direction::Right || currentDirection == Direction::Left) {
		if (newDirection == Direction::Down || newDirection == Direction::Up) {
			currentDirection = newDirection;
		}
	}
	else {
		if (newDirection == Direction::Right || newDirection == Direction::Left) {
			currentDirection = newDirection;
		}
	}
}

void gamestructure::Player::Update(){
	MoveSnake();
}
void gamestructure::Player::ExtendSnake() {

}

gamestructure::Player::Player() : currentDirection(Direction::Right), snake() {

}
gamestructure::Player::~Player(){
}