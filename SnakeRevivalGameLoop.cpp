#pragma once
#include "pch.h"

#include "SnakeRevivalGameLoop.h"
#include "GameMode.h"

using namespace std;
using namespace SnakeRevival;
using namespace commands;

/** FREE FUNC*/

void PrintColorSheet() {

	printf("\n");
	printf("\x1B[31mTexting\033[0m\t\t");
	printf("\x1B[32mTexting\033[0m\t\t");
	printf("\x1B[33mTexting\033[0m\t\t");
	printf("\x1B[34mTexting\033[0m\t\t");
	printf("\x1B[35mTexting\033[0m\n");

	printf("\x1B[36mTexting\033[0m\t\t");
	printf("\x1B[36mTexting\033[0m\t\t");
	printf("\x1B[36mTexting\033[0m\t\t");
	printf("\x1B[37mTexting\033[0m\t\t");
	printf("\x1B[93mTexting\033[0m\n");

	printf("\033[3;42;30mTexting\033[0m\t\t");
	printf("\033[3;43;30mTexting\033[0m\t\t");
	printf("\033[3;44;30mTexting\033[0m\t\t");
	printf("\033[3;104;30mTexting\033[0m\t\t");
	printf("\033[3;100;30mTexting\033[0m\n");

	printf("\033[3;47;35mTexting\033[0m\t\t");
	printf("\033[2;47;35mTexting\033[0m\t\t");
	printf("\033[1;47;35mTexting\033[0m\t\t");
	printf("\t\t");
	printf("\n");
}

/*END FREE FUNC*/

SnakeRevivalGameLoop::SnakeRevivalGameLoop()
{

}

SnakeRevivalGameLoop::~SnakeRevivalGameLoop()
{

}

void SnakeRevivalGameLoop::Render()
{
	//posso aggiustare il nextDisplay passando anche il valore "ratio_mismatch_ticks" e rendendo più fluido il 
	//gioco
	m_UpdatedDisplay = m_GameMode->GetCurrentView();
	m_GameView->WriteNextDisplay(m_UpdatedDisplay);
	m_GameView->PresentDisplay();
}

void SnakeRevivalGameLoop::Start()
{
	m_GameMode = GameMode::GetInstance();
	m_GameView = new Display();
	
	//m_RightCommand = new MoveRightCommand(m_Snake);
	//m_LeftCommand = new MoveLeftCommand(m_Snake);
	//m_UpCommand = new MoveUpCommand(m_Snake);
	//m_DownCommand = new MoveDownCommand(m_Snake);
	GameLoop(TICKS_PER_FRAME);
}

void SnakeRevivalGameLoop::Update() {
	std::list<IEntity>::iterator it;
	for (it = m_GameEntities.begin(); it != m_GameEntities.end(); it++) {
		it->Update();
	}
}

void SnakeRevivalGameLoop::Input() {
	if (_kbhit()) {
		unsigned char inputKey = _getch();
		if (inputKey == 'K') {
			if (m_LeftCommand!=nullptr)
				m_LeftCommand->execute();
		}
		if (inputKey == 'M') {
			if (m_RightCommand != nullptr)
				m_RightCommand->execute();
		}
		if (inputKey == 'H') {
			if (m_UpCommand != nullptr)
				m_UpCommand->execute();
		}
		if (inputKey == 'P') {
			if (m_DownCommand != nullptr)
				m_DownCommand->execute();
		}
	}
}

void SnakeRevivalGameLoop::GameLoop(clock_t ticks_per_frame)
{
	clock_t elapsed_ticks;
	while (!f_GameOver && !f_Pause)
	{
		clock_t start_tick = clock();

		Input();
		Update();
		Render();

		elapsed_ticks = clock() - start_tick;

		std::this_thread::sleep_for(std::chrono::milliseconds(ticks_per_frame - elapsed_ticks));
	}
}

int main()
{
	SnakeRevivalGameLoop snake;
	snake.Start();

	return 0;
}
