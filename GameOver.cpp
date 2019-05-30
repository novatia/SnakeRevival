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

using namespace gamestructure;
using namespace composite;

GameOver::GameOver()
{
	root_object = std::make_unique<LayerLayout>();

	Frame *f = new Frame();

	VerticalLayout* vl = new VerticalLayout();
	vl->SetPosition(0, 1);

	HorizontalLayout* game = new HorizontalLayout();
	game->Add(new GLetter());
	game->Add(new ALetter());
	game->Add(new MLetter());
	game->Add(new ELetter());

	HorizontalLayout* over = new HorizontalLayout();
	over->Add(new OLetter());
	over->Add(new VLetter());
	over->Add(new ELetter());
	over->Add(new RLetter());

	vl->Add(game);
	vl->Add(over);

	root_object->Add(*f, 0);
	root_object->Add(*vl, 1);

	Text *gotomenu = new Text(L"PRESS ANY BUTTON");
	gotomenu->top = 15;
	gotomenu->selected = true;

	root_object->Add(*gotomenu, 1);
}

std::wstring  GameOver::GetView()
{
	std::wstring draw;

	int height = root_object->GetHeight();

	for (int row = 0; row < height; row++) {
		draw += root_object->GetRow(row);
		draw += L"\n";
	}

	return draw;
}

GameOver::~GameOver()
{
}