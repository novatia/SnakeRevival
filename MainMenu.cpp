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

using namespace SnakeRevival;
using namespace composite;

MainMenu::MainMenu()
{
	m_RootObject = std::make_unique<LayerLayout>();

	VerticalLayout* vl = new VerticalLayout();
	vl->SetPosition(0,1);
	vl->SetAlignment(Center, Center);

	HorizontalLayout* dos  = new HorizontalLayout();
	dos->SetAlignment(Center, Center);

	dos->Add(new DLetter());
	dos->Add(new OLetter());
	dos->Add(new SLetter());

	HorizontalLayout* snake = new HorizontalLayout();
	snake->SetAlignment(Center, Center);

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

	m_RootObject->Add(*f, 0);
	m_RootObject->Add(*vl,1);

	Text *play = new Text(L"PLAY");
	play->SetAlignment(Center, Center);
	play->SetPosition(0,15);
	play->m_Selected = true;

	Text *quit = new Text(L"QUIT");
	quit->SetAlignment(Center, Center);
	quit->SetPosition(0, 17);

	m_RootObject->Add(*play, 1);
	m_RootObject->Add(*quit, 1);

}

MainMenu::~MainMenu()
{
}