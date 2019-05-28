#pragma once
#include "IEntity.h"
#include "IObservable.h"
#include "IObserver.h"

namespace gamestructure {
	enum class Direction 
	{
		
		Right=0,
		Left = 1,
		Down=2,
		Up =3,

	};

	
	struct position 
	{
		int x;  //column index : positivo andando verso destra
		int y;  // row index : positivo andando verso il basso
	};

	struct item
	{
		position itemPosition;
		bool isSuperFruit;
		bool isFruit;
		bool isPoison;

	};
	class Player : public IEntity, public IObservable
	{
	public:
		Player();
		virtual ~Player();
		void SetCurrentDirection(Direction newDirection);
		void Update();
		position* GetHeadPosition();
	private:
		Direction currentDirection;
		std::vector<position>* snake= new std::vector<position>();
		void MoveSnake();

		//questo metodo dovrebbe essere chiamato in risposta alla cattura di un oggetto
		void ExtendSnake();

	};

	class ScoreSystem : public IEntity, public IObserver
	{
	public:
		ScoreSystem();
		virtual ~ScoreSystem();

		void Update();
		void SetScoreIsChangedTrue();
		void AnswerToObservable(IObservable* observable, Event occurredEvent);
		void SetScoreIncrement(int scoreIncrementValue);
	private:
		bool scoreIsChanged;
		int scoreIncrement;
		int score;


	};
	
	class FruitSpawnerSystem : public IEntity, public IObserver
	{
	public:
		FruitSpawnerSystem();
		virtual ~FruitSpawnerSystem();
		void Update();
		void AnswerToObservable(IObservable* observable, Event occurredEvent);
		void SetGenerateItemBoolValuesToTrue(IObservable* observable);
	private:
		item firstItem;
		item secondItem;
		item thirdItem;
		bool generateFirstItem;
		bool generateSecondItem;
		bool generateThirdItem;

	};
}

