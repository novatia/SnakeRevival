#include "pch.h"
#include "SnakePlayer.h"


SnakePlayer::SnakePlayer()
{
}


SnakePlayer::~SnakePlayer()
{
}

using namespace std;
using namespace SnakeRevival;

void SnakePlayer::MoveSnake() {
	position nextPosition = snake->front();
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
	for (it = snake->begin(); it != snake->end(); it++) {
		tempPosition.x = it->x;
		tempPosition.y = it->y;
		snake->emplace(it, nextPosition);
		nextPosition.x = tempPosition.x;
		nextPosition.y = tempPosition.y;

	}
}

void  SnakePlayer::SetCurrentDirection(Direction newDirection) {
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

void SnakePlayer::Update() {
	MoveSnake();
}
void SnakePlayer::ExtendSnake() {

}
position& SnakePlayer::GetHeadPosition() {
	return snake->at(0);
}

SnakePlayer::SnakePlayer() : currentDirection(Direction::Right), snake() {

}
SnakePlayer::~SnakePlayer() {
}

