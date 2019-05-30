#include "pch.h"
#include "gameelements.h"
//#include "IObservable.h"
using namespace std;
//using namespace gamestructure;

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
gamestructure::position& gamestructure::Player::GetHeadPosition() {
	return snake->at(0);
}

gamestructure::Player::Player() : currentDirection(Direction::Right), snake() {

}
gamestructure::Player::~Player(){
}

gamestructure::ScoreSystem::ScoreSystem() : score(0), scoreIsChanged(false), scoreIncrement(0)
{
}
gamestructure::ScoreSystem::~ScoreSystem() {
}
void gamestructure::ScoreSystem::Update() {
	if (scoreIsChanged) {
		score += scoreIncrement;
		scoreIsChanged = false;
	}
}
void gamestructure::ScoreSystem::SetScoreIncrement(int scoreIncrementValue) {
	scoreIncrement = scoreIncrementValue;
}
void gamestructure::ScoreSystem::SetScoreIsChangedTrue() {
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
gamestructure::FruitSpawnerSystem::FruitSpawnerSystem() {}
gamestructure::FruitSpawnerSystem::~FruitSpawnerSystem(){}
void gamestructure::FruitSpawnerSystem::Update() {

}

/*
void gamestructure::FruitSpawnerSystem::AnswerToObservable( Event occurredEvent) {
	if (occurredEvent == Event::EatenFruitItem || occurredEvent == Event::EatenSuperFruitItem || occurredEvent == Event::EatenPoisonItem) {
		SetGenerateItemBoolValuesToTrue(observable);
	}
}*/


void gamestructure::FruitSpawnerSystem::SetGenerateItemBoolValuesToTrue(IObservable* observable) {
	Player* observableAsPlayer= static_cast<Player*>(observable);

	//adjust these rows..... oh yeah!!
	int headPos_x = observableAsPlayer->GetHeadPosition().x;
	int headPos_y = observableAsPlayer->GetHeadPosition().y;

	if (headPos_x == firstItem.itemPosition.x && headPos_x == firstItem.itemPosition.y)
	{

	}

}

