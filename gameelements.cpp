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
	std::vector<position>::iterator it;
	for (it = snake->begin(); it!= snake->end(); it++) {
		tempPosition.x = it->x;
		tempPosition.y = it->y;
		snake->emplace(it,nextPosition);
		nextPosition.x = tempPosition.x;
		nextPosition.y = tempPosition.y;

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