#include "pch.h"
#include "MainMenu.h"
#include "VerticalLayout.h"
#include "HorizontalLayout.h"
#include "LayerLayout.h"
#include "SLetter.h"
#include "NLetter.h"
#include "ALetter.h"
#include "KLetter.h"
#include "ELetter.h"
#include "DLetter.h"
#include "OLetter.h"
#include "SLetter.h"
#include "Text.h"

#include "Frame.h"

using namespace gamestructure;
using namespace composite;

MainMenu::MainMenu()
{
	root_object = std::make_unique<LayerLayout>();

	VerticalLayout* vl = new VerticalLayout();
	vl->SetPosition(0,1);

	HorizontalLayout* dos = new HorizontalLayout();
	dos->Add(new DLetter());
	dos->Add(new OLetter());
	dos->Add(new SLetter());

	HorizontalLayout* snake = new HorizontalLayout();
	Frame *f = new Frame();

	SLetter *s = new SLetter();
	s->SetColor(Blue);

	NLetter *n = new NLetter();
	n->SetColor(Red);

	ALetter *a = new ALetter();
	a->SetColor(Yellow);
	
	KLetter *k = new KLetter();
	k->SetColor(Blue);
	
	ELetter *e = new ELetter();
	e->SetColor(Green);

	snake->Add(s);
	snake->Add(n);
	snake->Add(a);
	snake->Add(k);
	snake->Add(e);

	vl->Add(dos);
	vl->Add(snake);

	root_object->Add(*f, 0);
	root_object->Add(*vl,1);

	Text *play = new Text(L"PLAY");
	play->top = 15;
	play->selected = true;

	Text *quit = new Text(L"QUIT");
	quit->top = 17;

	root_object->Add(*play, 1);
	root_object->Add(*quit, 1);

}

std::wstring  MainMenu::GetView() {
	std::wstring draw;

	int height = root_object->GetHeight();

	for (int row = 0; row < height; row++) {
		draw += root_object->GetRow(row);
		draw += L"\n";
	}

	return draw;
}

MainMenu::~MainMenu()
{
}
