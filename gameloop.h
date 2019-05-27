#pragma once
#include "pch.h"
#include "Display.h"
#include "Commands.h";

using namespace std;
using namespace gamestructure::commands;
namespace gamestructure 
{
	namespace gameloop


	{

		Display*  gameView = new Display();
		std::string updatedDisplay;
		Player snake;

		MoveRightCommand* rightCommand = new MoveRightCommand(&snake);
		MoveLeftCommand* leftCommand = new MoveLeftCommand(&snake);
		MoveUpCommand* upCommand = new MoveUpCommand(&snake);
		MoveDownCommand* downCommand = new MoveDownCommand(&snake);


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
			gameView->WriteNextDisplay(updatedDisplay);
		}

		void Render()
		{
			//posso aggiustare il nextDisplay passando anche il valore "ratio_mismatch_ticks" e rendendo più fluido il 
			//gioco

			gameView->PresentDisplay();
		}
	}


}