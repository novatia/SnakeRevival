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
	class Player : public IEntity, public IObservable
	{
	public:
		Player();
		virtual ~Player();
		void SetCurrentDirection(Direction newDirection);
		void Update();
	private:
		Direction currentDirection;
		std::vector<position>* snake= new std::vector<position>();
		void MoveSnake();

		//questo metodo dovrebbe essere chiamato in risposta alla cattura di un oggetto
		void ExtendSnake();

	};

	class ScoreSystem : public IEntity, public IObserver
	{




	};
	
	class FruitSpawnerSystemObserver : public IEntity, public IObserver
	{




	};
}

