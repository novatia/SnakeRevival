#pragma once
#include <list>
#include <thread>
#include <conio.h>

#include "Display.h"
#include "Commands.h";

using namespace std; ////NON SI FA!!! NAME SPACE POLLUTION!!!
using namespace SnakeRevival::commands;////NON SI FA!!! NAME SPACE POLLUTION!!!

namespace SnakeRevival 
{
	namespace gameloop
	{
		std::list<IEntity> gameEntities;

		Display*  gameView;
		std::wstring* updatedDisplay;
		Player* snake;
		ScoreSystem* scoreSystem;
		FruitSpawnerSystem* fruitSpawnerSystem;

		MoveRightCommand* rightCommand;
		MoveLeftCommand* leftCommand;
		MoveUpCommand* upCommand;
		MoveDownCommand* downCommand;


		void SetGameElements() {
			gameView = new Display();
			updatedDisplay = new std::wstring();

			snake = new Player();
			scoreSystem = new ScoreSystem();
			fruitSpawnerSystem = new FruitSpawnerSystem();
			snake->RegisterObserver(scoreSystem);
			snake->RegisterObserver(fruitSpawnerSystem);

			gameEntities.emplace_back(static_cast<IEntity*>(snake));
			gameEntities.emplace_back(static_cast<IEntity*>(scoreSystem));
			gameEntities.emplace_back(static_cast<IEntity*>(fruitSpawnerSystem));

			rightCommand = new MoveRightCommand(snake);
			leftCommand = new MoveLeftCommand(snake);
			upCommand = new MoveUpCommand(snake);
			downCommand = new MoveDownCommand(snake);


		}
		//ticks_per_frame deve essere corrispondente a un tempo sempre 
		//maggiore di quello necessario a un ciclo di update e minore di quello necessario a renderizzare
		//lag_ticks aumenta a ogni ciclo di un tempo uguale a quello necessario a tutto il ciclo
		//questo schema di game loop, per quanto complesso, va abbandonato, perchè il giocatore
		//deve avere la possibilità di controllare il serpente a ogni ciclo di update
		//inoltre non è necessario passare il float lag_ticks/ ticks_per_frame al ciclo di Render()
		/*
		void GameLoop(clock_t ticks_per_frame)
		{
			bool gameOver = false;
			bool pause = false;
			

			clock_t elapsed_ticks;
			clock_t lag_ticks;
			while (!gameOver && !pause)
			{
				clock_t start_tick = clock();

				Input();
				for (lag_ticks += elapsed_ticks; lag_ticks >= ticks_per_frame; lag_ticks -= ticks_per_frame) {

					//Update() sarà eseguito sempre a intervalli regolari: posso usare ticks_per_frame per stabilire la velocità
					//del gioco
					Update();
					//poichè il gioco è semplice e non contiene grafica molto avanzata, si può inserire il metodo render
					//all'interno del ciclo for, in modo da renderizzare a intervalli regolari
					//se inserisco Render() nel ciclo for allora non ha senso usare il double buffer
					//infatti a ogni ciclo di Update farò il Render()
					

				}
				//il metodo Render() deve gestire in maniera opportuna questo float
				Render(lag_ticks/ ticks_per_frame);
				
				elapsed_ticks = clock() - start_tick;
			}
		}
		*/

		void GameLoop(clock_t ticks_per_frame)
		{
			bool gameOver = false;
			bool pause = false;


			clock_t elapsed_ticks;
			while (!gameOver && !pause)
			{
				clock_t start_tick = clock();

				Input();
				Update();
				Render();

				elapsed_ticks = clock() - start_tick;
				
				std::this_thread::sleep_for(std::chrono::milliseconds(ticks_per_frame - elapsed_ticks));
			}
		}

		//il game loop deve essere molto semplice perché sarebbe fuori luogo dover gestire il lag nel render
		//si assume che il nostro update sia abbastanza veloce

		void Input() {
			if (_kbhit()) {
				unsigned char inputKey = _getch();
				if (inputKey == 'K') {
					leftCommand->execute();
				}
				if (inputKey == 'M') {
					rightCommand->execute();
				}
				if (inputKey == 'H') {
					upCommand->execute();
				}
				if (inputKey == 'P') {
					downCommand->execute();
				}
			}
		}

		void Update() {
			std::list<IEntity>::iterator it;
			for (it = gameEntities.begin(); it != gameEntities.end(); it++) {
				it->Update();
			}
		}

		void Render()
		{
			//posso aggiustare il nextDisplay passando anche il valore "ratio_mismatch_ticks" e rendendo più fluido il 
			//gioco

			gameView->WriteNextDisplay(*updatedDisplay);
			gameView->PresentDisplay();
		}
	}


}