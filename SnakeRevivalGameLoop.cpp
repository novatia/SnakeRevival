#pragma once
#include "pch.h"

#include "SnakeRevivalGameLoop.h"
#include "InputManager.h"

using namespace std;
using namespace SnakeRevival;
using namespace singleton;

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

SnakeRevivalGameLoop* SnakeRevivalGameLoop::m_Instance;
SnakeRevivalGameLoop * SnakeRevival::SnakeRevivalGameLoop::GetInstance()
{
	if (m_Instance == nullptr)
		m_Instance = new SnakeRevivalGameLoop();

	return m_Instance;
}

SnakeRevivalGameLoop::~SnakeRevivalGameLoop()
{

}

void SnakeRevivalGameLoop::Render()
{
	//posso aggiustare il nextDisplay passando anche il valore "ratio_mismatch_ticks" e rendendo più fluido il 
	//gioco
	m_UpdatedDisplay = m_CurrentView->GetView();
	m_GameView->WriteNextDisplay(m_UpdatedDisplay);
	m_GameView->PresentDisplay();
}

void SnakeRevivalGameLoop::Start()
{
	m_GameView = new Display();
	m_CurrentView = &m_Menu;

	GameLoop(TICKS_PER_FRAME);
}

void SnakeRevivalGameLoop::Update(clock_t ticks_per_frame)
{
	m_TimeElapsed += TICKS_PER_FRAME;

	m_CurrentView->Update();

	composite::Level1 *level1 = dynamic_cast<composite::Level1*>(m_CurrentView);

	if (level1 != nullptr) {
		if (level1->IsGameOver()) {
			m_CurrentView = &m_GameOver;
			level1->ResetLevel();
			level1->UnsetGameOver();
			return;
		}
	}

	composite::GameOver *gameover = dynamic_cast<composite::GameOver*>(m_CurrentView);
	if (gameover != nullptr) {
		if (gameover->IsDone()) {
			m_CurrentView = &m_Menu;
			gameover->UnsetDone();
			return;
		}
	}

	std::list<IEntity>::iterator it;
	for (it = m_GameEntities.begin(); it != m_GameEntities.end(); it++) {
		it->Update();
	}
}

void SnakeRevivalGameLoop::Input() {
	
		InputManager *IM = InputManager::GetInstance();

		IM->Input();
	
}

void SnakeRevivalGameLoop::GameLoop(clock_t ticks_per_frame)
{
	clock_t elapsed_ticks;

	while (!f_Pause)
	{
		clock_t start_tick = clock();

		Input();
		Update(ticks_per_frame);
		Render();

		elapsed_ticks = clock() - start_tick;

		std::this_thread::sleep_for(std::chrono::milliseconds(ticks_per_frame - elapsed_ticks));
	}
}

int main()
{
	SnakeRevivalGameLoop *snake = SnakeRevivalGameLoop::GetInstance();
	snake->Start();

	return 0;
}
