#include "pch.h"
#include "Level1.h"
#include "pch.h"
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

using namespace SnakeRevival;
using namespace composite;
using namespace singleton;

Level1::Level1()
{
	m_RootObject = std::make_unique<LayerLayout>();

	LevelFrame *f = new LevelFrame();
	f->SetColor(Color::Green);
	m_RootObject->Add(*f, 0);
	
	m_Score = new Text(L"SCORE: 0");
	m_Score->SetColor(Color::Yellow);
	m_Score->SetAlignment(Alignment::Center, Alignment::None);
	m_RootObject->Add(*m_Score, 1);

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
	m_Spider->SetPosition(60, 12);

	m_RootObject->Add(*m_Spider, 3);

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

	m_Score->SetText(L"SCORE: 0");

	m_SnakePosition_X = 40;
	m_SnakePosition_Y = 12;

	m_Snake->Clear();
	m_Snake->SetSnakePosition(m_SnakePosition_X, m_SnakePosition_Y);

	m_GameOver = false;
}

void Level1::Update()
{
	InputManager *IM = InputManager::GetInstance();

	if (IM->ButtonPressed())
	{
		switch (IM->GetButtonPressed())
		{
		case Key::Up:
		{
			if (m_SnakeDirection == Direction::Down)
				break;

			m_SnakeDirection = Direction::Up;

			break;
		}
		case Key::Down:
		{
			if (m_SnakeDirection == Direction::Up)
				break;

			m_SnakeDirection = Direction::Down;

			break;
		}

		case Key::Left:
		{
			if (m_SnakeDirection == Direction::Right)
				break;

			m_SnakeDirection = Direction::Left;

			break;
		}

		case Key::Right:
		{
			if (m_SnakeDirection == Direction::Left)
				break;

			m_SnakeDirection = Direction::Right;
			break;
		}

		};
	}


	switch (m_SnakeDirection) {
	case Direction::Down:
	{
		m_SnakePosition_Y += TICKS_PER_FRAME*m_SnakeSpeed / 2;
		break;
	}
	case Direction::Up:
	{
		m_SnakePosition_Y-= TICKS_PER_FRAME * m_SnakeSpeed / 2;
		break;
	}
	case Direction::Left :
	{
		m_SnakePosition_X-= TICKS_PER_FRAME * m_SnakeSpeed;
		break;
	}
	case Direction::Right:
	{
		m_SnakePosition_X+= TICKS_PER_FRAME * m_SnakeSpeed;
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

	m_Snake->SetSnakePosition(m_SnakePosition_X, m_SnakePosition_Y);

	//check fruit collision
	std::pair<int, int> s_position = m_Snake->GetSnakeHeadPosition();
	std::pair<int, int> f_position = m_Fruit->GetPosition();

	
	if (s_position.first >= f_position.first &&
		s_position.first <= f_position.first + m_Fruit->GetWidth() &&
		s_position.second >= f_position.second &&
		s_position.second <= f_position.second + m_Fruit->GetHeight() 
		) {
		// collided
		int position_x = rand() % (75 - 1 + 1) + 1;
		int position_y = rand() % (21 - 2 + 1) + 2;
		m_Fruit->SetPosition(position_x, position_y);
		m_ScoreValue += m_Fruit->GetValue();
		std::wstring scores = L"SCORE: " + std::to_wstring(m_ScoreValue);
		m_Score->SetText(scores);

		m_Fruit->RandomValue();
		m_Snake->Grow(m_Fruit->GetValue());
	}
	
	

}

bool SnakeRevival::composite::Level1::IsGameOver()
{
	return m_GameOver;
}

void SnakeRevival::composite::Level1::UnsetGameOver()
{
	m_GameOver = false;
}
