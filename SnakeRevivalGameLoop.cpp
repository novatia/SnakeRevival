#pragma once
#include "pch.h"

#include "SnakeRevivalGameLoop.h"
#include "InputManager.h"
#include "SoundManager.h"

using namespace std;
using namespace SnakeRevival;
using namespace singleton;

std::wstring SnakeRevivalGameLoop::m_ElapsedTicksPerformance;

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

	//Run main menu music
	SoundManager *SM = SoundManager::GetInstance();
	SM->PlayIntro();
}

void SnakeRevivalGameLoop::Update()
{
	//il ciclo di Update del game loop non ha bisogno di ricevere ticks_per_frame come argomento
	//se si prova a sostituire con TICKS_PER_FRAME con ticks_per_frame si ha
	//l'effetto delle lettere che lampeggiano più velocemente
	//ciò è dovuto al fatto che l'argomento del metodo GameLoop effettua una conversione implicita da float a clock_t
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
	/* inutile.... la lista m_GameEntities è vuota
	std::list<IEntity>::iterator it;
	for (it = m_GameEntities.begin(); it != m_GameEntities.end(); it++) {
		it->Update();
	}*/
}

void SnakeRevivalGameLoop::Input() {
	
		InputManager *IM = InputManager::GetInstance();

		IM->Input();
	
}

void SnakeRevivalGameLoop::GameLoop(clock_t ticks_per_frame)
{

	while (!f_Pause)
	{
		m_start_tick = clock();
		std::chrono::time_point < std::chrono::steady_clock> t1 = std::chrono::high_resolution_clock::now();
		Input();
		Update();
		Render();
		m_end_tick = clock();
		std::chrono::time_point < std::chrono::steady_clock> t2 = std::chrono::high_resolution_clock::now();
		
		m_elapsed_ticks = m_end_tick - m_start_tick;
		m_elapsed_ms = std::chrono::milliseconds(m_elapsed_ticks);
		
		m_sleep_time_interval_ms = std::chrono::milliseconds(ticks_per_frame - m_elapsed_ticks);
		std::this_thread::sleep_for(m_sleep_time_interval_ms);
		//m_cycle_duration_test_ms= std::chrono::duration_cast<std::chrono::milliseconds>(t2 - t1).count();
		
		m_ElapsedTicksPerformance = log_progress(t2 - t1, m_elapsed_ms, m_sleep_time_interval_ms);
	}
}

std::wstring SnakeRevival::SnakeRevivalGameLoop::GetElapsedTicksPerformance()
{
	return m_ElapsedTicksPerformance;
}

int main()
{
	SnakeRevivalGameLoop *snake = SnakeRevivalGameLoop::GetInstance();
	snake->Start();

	return 0;
}
