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

#include "LevelFrame.h"

using namespace gamestructure;
using namespace composite;

Level1::Level1()
{
	root_object = std::make_unique<LayerLayout>();

	LevelFrame *f = new LevelFrame();
	f->SetColor(Green);

	Fruit *f1 = new Fruit();
	f1->SetPosition(10, 10);

	root_object->Add(*f, 0);
	root_object->Add(*f1, 0);

	Text *score = new Text(L"SCORE: ");
	score->SetColor(Yellow);

	root_object->Add(*score, 1);
}

std::wstring  Level1::GetView()
{
	std::wstring draw;

	int height = root_object->GetHeight();

	for (int row = 0; row < height; row++) {
		draw += root_object->GetRow(row);
		draw += L"\n";
	}

	return draw;
}

Level1::~Level1()
{
}
