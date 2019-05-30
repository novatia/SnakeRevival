#pragma once
#include "IObservable.h"
#include "gameelements.h"
namespace SnakeRevival {
	class IObserver
	{
	public:
		IObserver() {
		};
		~IObserver() {
		};
		//virtual void AnswerToObservable(Event occurredEvent) {};
			//qui si inserisce la logica del gioco: è necessario fare un override per ogni osservatore
			// l'evento va generato dentro il metodo update del player
			// è necessario decidere se ScoreSystem e FruitSpawnerSystemObserver devono ereditare da
			// IEntity oppure no
			// Se derivano da IEntity bisogna implementare un metodo Update anche per loro
			// quindi è necessario regolare la tempistica del loro aggiornamento con un flag booleano
			// passo e chiudo
	};


	/*
	IObserver::IObserver()
	{
	}


	IObserver::~IObserver()
	{
	}

	void IObserver::AnswerToObservable() 
	{
	}
	*/
}