#include "pch.h"
#include "gameelements.h"
//#include "IObservable.h"
using namespace std;
using namespace SnakeRevival;

void Player::MoveSnake() {
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

void  Player::SetCurrentDirection(Direction newDirection) {
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

void Player::Update(){
	MoveSnake();
}
void Player::ExtendSnake() {

}
position& Player::GetHeadPosition() {
	return snake->at(0);
}

Player::Player() : currentDirection(Direction::Right), snake() {

}
Player::~Player(){
}

ScoreSystem::ScoreSystem() : score(0), scoreIsChanged(false), scoreIncrement(0)
{
}
ScoreSystem::~ScoreSystem() {
}
void ScoreSystem::Update() {
	if (scoreIsChanged) {
		score += scoreIncrement;
		scoreIsChanged = false;
	}
}
void ScoreSystem::SetScoreIncrement(int scoreIncrementValue) {
	scoreIncrement = scoreIncrementValue;
}
void ScoreSystem::SetScoreIsChangedTrue() {
	if (!scoreIsChanged) {
		scoreIsChanged = true;
	}
}
/*
void gamestructure::ScoreSystem::AnswerToObservable( Event occurredEvent) {
	if (occurredEvent ==Event::EatenFruitItem) {
		SetScoreIsChangedTrue();
		SetScoreIncrement(10);
	}
	if (occurredEvent == Event::EatenSuperFruitItem) {
		SetScoreIsChangedTrue();
		SetScoreIncrement(30);

	}
	if (occurredEvent == Event::EatenPoisonItem) {
		if (score >= 20) {
			SetScoreIsChangedTrue();
			SetScoreIncrement(-20);
		}
		else if (score >= 10) {
			SetScoreIsChangedTrue();
			SetScoreIncrement(-10);
		}
	}
}
*/
FruitSpawnerSystem::FruitSpawnerSystem() {}
FruitSpawnerSystem::~FruitSpawnerSystem(){}
void FruitSpawnerSystem::Update() {

}

/*
void gamestructure::FruitSpawnerSystem::AnswerToObservable( Event occurredEvent) {
	if (occurredEvent == Event::EatenFruitItem || occurredEvent == Event::EatenSuperFruitItem || occurredEvent == Event::EatenPoisonItem) {
		SetGenerateItemBoolValuesToTrue(observable);
	}
}*/


void FruitSpawnerSystem::SetGenerateItemBoolValuesToTrue(IObservable* observable) {
	Player* observableAsPlayer= static_cast<Player*>(observable);

	//adjust these rows..... oh yeah!!
	int headPos_x = observableAsPlayer->GetHeadPosition().x;
	int headPos_y = observableAsPlayer->GetHeadPosition().y;

	if (headPos_x == firstItem.itemPosition.x && headPos_x == firstItem.itemPosition.y)
	{

	}

}

