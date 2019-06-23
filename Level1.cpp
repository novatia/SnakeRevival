#include "pch.h"
#include "Level1.h"
#include "GameOver.h"
#include "MainMenu.h"
#include "VerticalLayout.h"
#include "HorizontalLayout.h"
#include "LayerLayout.h"
#include "GLetter.h"
#include "ALetter.h"
#include "MLetter.h"
#include "ELetter.h"
#include "SPACELetter.h"
#include "OLetter.h"
#include "VLetter.h"
#include "RLetter.h"
#include "Text.h"
#include "Fruit.h"
#include "WormBody.h"
#include "LevelFrame.h"
#include "InputManager.h"
#include "SnakeRevivalGameLoop.h"

using namespace SnakeRevival;
using namespace composite;
using namespace singleton;
using namespace strategy;

Level1::Level1()
{
	m_RootObject = std::make_unique<LayerLayout>();

	LevelFrame *f = new LevelFrame();
	f->SetColor(Color::Green);
	m_RootObject->Add(*f, 0);
	
	m_Score = new Text(L"SCORE: 0");
	m_Score->SetColor(Color::Yellow);
	m_Score->SetAlignment(Alignment::Right, Alignment::None);
	m_RootObject->Add(*m_Score, 1);

	m_Performance = new Text(L"fps");
	m_Performance->SetAlignment(Alignment::Left, Alignment::None);
	m_Performance->SetPosition(0, 0);
	m_RootObject->Add(*m_Performance, 1);

	m_Fruit = new Fruit();
	m_Fruit->SetAlignment(Alignment::Left, Alignment::None);
	m_RootObject->Add(*m_Fruit, 1);

	m_Snake = new WormBody();
	m_Snake->SetColor(Color::Purple);
	m_Snake->SetPosition(1, 2);
	m_Snake->SetAlignment(Alignment::Left, Alignment::None);

	m_RootObject->Add(*m_Snake, 2);

	m_Spider = new Spider();
	m_Spider->SetColor(Color::Blue);
	m_SpiderPosition_X = 60;
	m_SpiderPosition_Y = 12;

	m_Spider->SetPosition(m_SpiderPosition_X, m_SpiderPosition_Y);

	m_RootObject->Add(*m_Spider, 3);

	m_GameOverListener = new GotoGameOverAction();

	ResetLevel();
}

Level1::~Level1()
{
}

void Level1::ResetLevel()
{
	int position_x = rand() % (75 - 1 + 1) + 1;
	int position_y = rand() % (21 - 2 + 1) + 2;
	m_Fruit->SetPosition(position_x, position_y);

	m_ScoreValue = 0;
	m_Score->SetText(L"SCORE: 0");

	m_SnakePosition_X = 40;
	m_SnakePosition_Y = 12;

	m_Snake->Clear();
	m_Snake->SetSnakePosition(m_SnakePosition_X, m_SnakePosition_Y);
	m_Snake->SetSnakeDirection(Direction::Left);

	m_GameOver = false;

	//spider POSITION
	m_SpiderPosition_X = 60;
	m_SpiderPosition_Y = 12;
	m_Spider->SetPosition(m_SpiderPosition_X, m_SpiderPosition_Y);
	m_SpiderCollideSnake = false;
}

void Level1::Update()
{
	InputManager *IM = InputManager::GetInstance();
	
	//obtain the old snake head position
	m_SnakePositionPreviousUpdate = m_Snake->GetSnakeHeadPosition();
	//ask for input if it is possible
	if (m_enableInput) {

		if (IM->ButtonPressed())
		{
			m_CurrentSnakeDirection = m_Snake->GetSnakeDirection();
			switch (IM->GetButtonPressed())
			{
			case Key::Up:
			{
				if (m_CurrentSnakeDirection == Direction::Down)
					break;

				m_Snake->SetSnakeDirection(Direction::Up);
				m_enableInput = false;
				break;
			}
			case Key::Down:
			{
				if (m_CurrentSnakeDirection == Direction::Up)
					break;

				m_Snake->SetSnakeDirection(Direction::Down);
				m_enableInput = false;


				break;
			}

			case Key::Left:
			{
				if (m_CurrentSnakeDirection == Direction::Right)
					break;

				m_Snake->SetSnakeDirection(Direction::Left);
				m_enableInput = false;

				break;
			}

			case Key::Right:
			{
				if (m_CurrentSnakeDirection == Direction::Left)
					break;

				m_Snake->SetSnakeDirection(Direction::Right);
				m_enableInput = false;

				break;
			}

			};
		}
		
	}

	switch (m_Snake->GetSnakeDirection()) {
	case Direction::Down:
	{
		m_SnakePosition_Y += GAMESPEED *m_SnakeSpeed/2;
		break;
	}
	case Direction::Up:
	{
		m_SnakePosition_Y-= GAMESPEED * m_SnakeSpeed/2;
		break;
	}
	case Direction::Left :
	{
		m_SnakePosition_X-= GAMESPEED * m_SnakeSpeed;
		break;
	}
	case Direction::Right:
	{
		m_SnakePosition_X+= GAMESPEED * m_SnakeSpeed;
		break;
	}
	};

	//set snake position

	if (m_SnakePosition_X <= 1 || m_SnakePosition_X >= (DISPLAY_WIDTH  - 1) ||
		m_SnakePosition_Y <= 2 || m_SnakePosition_Y >= (DISPLAY_HEIGHT - 1) || 
		m_Snake->CollisionCheck(m_SnakePosition_X, m_SnakePosition_Y)) {

		//GAME OVER
		m_GameOver = true;
	}
	if (IsGameOver()) {
		ResetLevel();
		UnsetGameOver();
		m_GameOverListener->ActionPerformed();
		return;
	}

	m_Snake->SetSnakePosition(m_SnakePosition_X, m_SnakePosition_Y); //i float vengono troncati
	//compare the updated position and the old one to decide if the input must be enabled again
	if (m_SnakePositionPreviousUpdate != m_Snake->GetSnakeHeadPosition())
	{
		m_enableInput = true;
	}

	//SET SPIDER POSITION
	if (m_PatrollingLeft) {
		m_SpiderPosition_X -= GAMESPEED * m_SpiderSpeed;
		if (m_SpiderPosition_X <= 1) m_PatrollingLeft = false;
	}
	else {
		m_SpiderPosition_X += GAMESPEED * m_SpiderSpeed;
		if (m_SpiderPosition_X >= 70) m_PatrollingLeft = true;
	}
		
	m_Spider->SetPosition(m_SpiderPosition_X,m_SpiderPosition_Y);

	//check fruit collision
	std::pair<int, int> s_position = m_Snake->GetSnakeHeadPosition();
	std::pair<int, int> f_position = m_Fruit->GetPosition();
	
	if (s_position.first+1 >= f_position.first &&
		s_position.first+1 <= f_position.first + m_Fruit->GetWidth()-1 &&
		s_position.second >= f_position.second &&
		s_position.second <= f_position.second + m_Fruit->GetHeight()-1
		) 
	{
		// collided
		//upgrade score value and increase the snake length
		m_ScoreValue += m_Fruit->GetValue();
		std::wstring scores = L"SCORE: " + std::to_wstring(m_ScoreValue);
		m_Score->SetText(scores);
		m_Snake->Grow(m_Fruit->GetValue());

		//generate new fruit position and value
		int position_x = rand() % (75 - 1 + 1) + 1;
		int position_y = rand() % (21 - 2 + 1) + 2;
		m_Fruit->SetPosition(position_x, position_y);
		m_Fruit->RandomValue();
	}

	//CHECK SPIDER COLLISION
	for (int y = 0; y < 25; y++) {
		std::wstring row = m_Spider->GetRow(y);

		for (int x = 5; x < row.size(); x+=10) {
			if (row[x] != L' ') 
			{
				int spider_x = m_Spider->GetPosition().first;
				int spider_x_position = spider_x + ( (x - 5) / 10) ;
				bool check  = m_Snake->CollisionCheck(spider_x_position, y);
				m_SpiderCollideSnake = m_SpiderCollideSnake | check;
			}
		}
	}

	if (m_SpiderCollideSnake) 
	{
		m_GameOver = true;
	}
	if (IsGameOver()) {
		ResetLevel();
		UnsetGameOver();
		m_GameOverListener->ActionPerformed();
		return;
	}
	std::wstring perf = SnakeRevivalGameLoop::GetElapsedTicksPerformance();
	m_Performance->SetText(perf);
}

bool SnakeRevival::composite::Level1::IsGameOver()
{
	return m_GameOver;
}

void SnakeRevival::composite::Level1::UnsetGameOver()
{
	m_GameOver = false;
}
