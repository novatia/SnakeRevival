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

using namespace SnakeRevival;
using namespace composite;

GameOver::GameOver()
{
	m_RootObject = std::make_unique<LayerLayout>();

	Frame *f = new Frame();

	VerticalLayout* vl = new VerticalLayout();
	vl->SetPosition(0, 1);
	vl->SetAlignment(Alignment::Center, Alignment::Center);
	HorizontalLayout* game = new HorizontalLayout();
	game->SetColor(Color::Blue);
	game->SetAlignment(Alignment::Center, Alignment::Center);
	game->Add(new GLetter());
	game->Add(new ALetter());
	game->Add(new MLetter());
	game->Add(new ELetter());

	HorizontalLayout* over = new HorizontalLayout();
	over->SetColor(Color::Blue);
	over->SetAlignment(Alignment::Center, Alignment::Center);

	over->Add(new OLetter());
	over->Add(new VLetter());
	over->Add(new ELetter());
	over->Add(new RLetter());

	vl->Add(game);
	vl->Add(over);

	m_RootObject->Add(*f, 0);
	m_RootObject->Add(*vl, 1);

	Text *gotomenu = new Text(L"PRESS ANY BUTTON");
	gotomenu->SetAlignment(Alignment::Center, Alignment::Center);
	gotomenu->SetPosition(0, 15);
	gotomenu->m_Selected = true;

	m_RootObject->Add(*gotomenu, 1);
}

GameOver::~GameOver()
{
}

void GameOver::execute()
{
}
