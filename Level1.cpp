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
	m_RootObject->Add(*f, 0);
	
	m_Score = new Text(L"SCORE: 0000");
	m_Score->SetColor(Color::Yellow);
	m_Score->SetAlignment(Alignment::Center, Alignment::Center);
	m_RootObject->Add(*m_Score, 1);

	m_Fruit = new Fruit();
	m_Fruit->SetPosition(18, 2);
	m_Fruit->SetAlignment(Alignment::Left, Alignment::Left);
	m_RootObject->Add(*m_Fruit, 1);

	m_Snake = new WormBody();
	m_Snake->SetPosition( m_SnakePosition_X, m_SnakePosition_Y );
	
	m_RootObject->Add(*m_Snake, 2);
}

Level1::~Level1()
{
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
		m_SnakePosition_Y += TICKS_PER_FRAME*m_SnakeSpeed;
		break;
	}
	case Direction::Up:
	{
		m_SnakePosition_Y-= TICKS_PER_FRAME * m_SnakeSpeed;
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

	m_Snake->SetPosition(m_SnakePosition_X, m_SnakePosition_Y);
}