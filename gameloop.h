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


		//ticks_per_frame deve essere corrispondente a un tempo sempre minore di quello necessario a renderizzare
		//lag_ticks aumenta a ogni ciclo di un tempo uguale a quello necessario a renderizzare
		void Loop(clock_t ticks_per_frame)
		{
			clock_t elapsed_ticks;
			clock_t lag_ticks;
			while (true)
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

		void Input() {

		}

		void Update() {
			gameView->WriteNextDisplay(updatedDisplay);
		}

		void Render(float ratio_mismatch_ticks)
		{
			//posso aggiustare il nextDisplay passando anche il valore "ratio_mismatch_ticks" e rendendo più fluido il 
			//gioco

			gameView->PresentDisplay();
		}
	}


}