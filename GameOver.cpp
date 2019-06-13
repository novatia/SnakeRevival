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
#include "Frame.h"
#include "SnakeRevivalGameLoop.h"
#include "InputManager.h"

using namespace SnakeRevival;
using namespace composite;
using namespace singleton;

GameOver::GameOver()
{
	m_RootObject = std::make_unique<LayerLayout>();

	Frame *f = new Frame();

	VerticalLayout* vl = new VerticalLayout();
	vl->SetPosition(0, 1);
	vl->SetAlignment(Alignment::Center, Alignment::Center);
	HorizontalLayout* game = new HorizontalLayout();
	game->SetAlignment(Alignment::Center, Alignment::Center);

	m_G = new GLetter();
	m_G->SetColor(Color::Blue);

	m_A = new ALetter();
	m_A->SetColor(Color::White);

	m_M = new MLetter();
	m_M->SetColor(Color::Blue);

	m_E = new ELetter();
	m_E->SetColor(Color::White);

	game->Add(m_G);
	game->Add(m_A);
	game->Add(m_M);
	game->Add(m_E);

	HorizontalLayout* over = new HorizontalLayout();
	over->SetAlignment(Alignment::Center, Alignment::Center);

	m_O = new OLetter();
	m_O->SetColor(Color::Blue);

	m_V = new VLetter();
	m_V->SetColor(Color::White);

	m_E1 = new ELetter();
	m_E1->SetColor(Color::Blue);

	m_R = new RLetter();
	m_R->SetColor(Color::White);

	over->Add(m_O);
	over->Add(m_V);
	over->Add(m_E1);
	over->Add(m_R);

	vl->Add(game);
	vl->Add(over);

	m_RootObject->Add(*f, 0);
	m_RootObject->Add(*vl, 1);

	Text *gotomenu = new Text(L"PRESS ANY BUTTON");
	gotomenu->SetAlignment(Alignment::Center, Alignment::Center);
	gotomenu->SetPosition(0, 15);
	gotomenu->m_Selected = true;

	m_RootObject->Add(*gotomenu, 1);
	
	m_Done = false;
}

GameOver::~GameOver()
{
}


Color Increase(Color color) {
	switch (color) {
	case Color::Blue: return Color::White;
	case Color::White: return Color::Blue;
	}

	return Color::White;
}

void GameOver::RotateColours()
{
	//SnakeRevivalGameLoop *SL = SnakeRevivalGameLoop::GetInstance();
	int time = round(SnakeRevivalGameLoop::GetInstance()->m_TimeElapsed*1000);
	if (time % 100 == 0) 
	{
		m_ColorCounter = Increase(m_ColorCounter);
		m_G->SetColor(m_ColorCounter);
		
		m_ColorCounter = Increase(m_ColorCounter);
		m_A->SetColor(m_ColorCounter);
		
		m_ColorCounter = Increase(m_ColorCounter);
		m_M->SetColor(m_ColorCounter);
	
		m_ColorCounter = Increase(m_ColorCounter);
		m_E->SetColor(m_ColorCounter);

		m_ColorCounter = Increase(m_ColorCounter);
		m_ColorCounter = Increase(m_ColorCounter);
		m_O->SetColor(m_ColorCounter);
		
		m_ColorCounter = Increase(m_ColorCounter);
		m_V->SetColor(m_ColorCounter);

		m_ColorCounter = Increase(m_ColorCounter);
		m_E1->SetColor(m_ColorCounter);
	
		m_ColorCounter = Increase(m_ColorCounter);
		m_R->SetColor(m_ColorCounter);
	}
}

bool GameOver::IsDone()
{
	return m_Done;
}

void GameOver::UnsetDone()
{
	m_Done = false;
}

void GameOver::Update() {
	//InputManager *IM = InputManager::GetInstance();

	if (InputManager::GetInstance()->ButtonPressed())
	{
		m_Done = true;
	}

	RotateColours();
}