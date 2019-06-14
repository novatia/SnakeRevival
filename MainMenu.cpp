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
#include "Text.h"
#include "GotoLevel1Action.h"
#include "QuitAction.h"
#include "Frame.h"
#include "InputManager.h"
#include "SnakeRevivalGameLoop.h"
#include "SoundManager.h"

using namespace SnakeRevival;
using namespace composite;
using namespace strategy;
using namespace singleton;

MainMenu::MainMenu()
{
	m_RootObject = std::make_unique<LayerLayout>();

	VerticalLayout* vl = new VerticalLayout();
	vl->SetPosition(0,1);
	vl->SetAlignment(Alignment::Center, Alignment::None);

	HorizontalLayout* dos  = new HorizontalLayout();
	dos->SetAlignment(Alignment::Center, Alignment::None);

	dos->Add(new DLetter());
	dos->Add(new OLetter());
	dos->Add(new SLetter());

	HorizontalLayout* snake = new HorizontalLayout();
	snake->SetAlignment(Alignment::Center, Alignment::None);


	m_S = new SLetter();
	m_S->SetColor(Color::Blue);

	m_N = new NLetter();
	m_N->SetColor(Color::Red);

	m_A = new ALetter();
	m_A->SetColor(Color::Yellow);
	
	m_K = new KLetter();
	m_K->SetColor(Color::Blue);
	
	m_E = new ELetter();
	m_E->SetColor(Color::Green);

	snake->Add(m_S);
	snake->Add(m_N);
	snake->Add(m_A);
	snake->Add(m_K);
	snake->Add(m_E);

	m_Performance = new Text(L"fps");
	m_Performance->SetAlignment(Alignment::Left, Alignment::None);
	m_Performance->SetPosition(5, 23);

	vl->Add(dos);
	vl->Add(snake);

	Frame *f = new Frame();
	m_RootObject->Add(*f, 0); //LEVEL 0 FRAME
	m_RootObject->Add(*vl,1); //LEVEL 1  DOS,SNAKE

	m_PlayButton = new Text(L"PLAY");
	m_PlayButton->SetAlignment(Alignment::Center, Alignment::None);
	m_PlayButton->SetPosition(0,15);
	m_PlayButton->AddActionListener(new GotoLevel1Action());
	m_PlayButton->m_Selected = true;
	m_PlayButton->SetColor(Color::Yellow);

	m_QuitButton = new Text(L"QUIT");
	m_QuitButton->SetAlignment(Alignment::Center, Alignment::None);
	m_QuitButton->SetPosition(0, 17);
	m_QuitButton->AddActionListener(new QuitAction());

	m_RootObject->Add(*m_PlayButton, 1);//LEVEL 1 
	m_RootObject->Add(*m_QuitButton, 1);//LEVEL 1 
	m_RootObject->Add(*m_Performance,1);

	SoundManager *SM = SoundManager::GetInstance();
	SM->PlayIntro();
	
}

MainMenu::~MainMenu()
{

}

void MainMenu::SelectNext()
{
	if (m_PlayButton->m_Selected )
	{
		m_QuitButton->m_Selected = true;
		m_QuitButton->SetColor(Color::Yellow);

		m_PlayButton->m_Selected = false;
		m_PlayButton->SetColor(Color::White);
	}
	else 
	{
		m_QuitButton->m_Selected = false;
		m_QuitButton->SetColor(Color::White);

		m_PlayButton->m_Selected = true;
		m_PlayButton->SetColor(Color::Yellow);
	}
}

void MainMenu::Update() {
	InputManager *IM = InputManager::GetInstance();

	if (IM->ButtonPressed())
	{
		switch (IM->GetButtonPressed())
		{
		case Key::Up: case Key::Down:
		{
			SelectNext();
			break;
		}
		case Key::Enter : 
		{
			if (m_PlayButton->m_Selected)
				m_PlayButton->m_ActionListener->ActionPerformed();
			if (m_QuitButton->m_Selected)
				m_QuitButton->m_ActionListener->ActionPerformed();
		}
		};
	}
	
	std::wstring perf = SnakeRevivalGameLoop::GetElapsedTicksPerformance();
	m_Performance->SetText(perf);

	RotateColours();
}

Color IncreaseBW(Color color) {
	switch (color) {
	case Color::Red:  return Color::Green;
	case Color::Green: return Color::Blue;
	case Color::Blue: return Color::Yellow;
	case Color::Yellow: return Color::Purple;
	case Color::Purple: return Color::White;
	case Color::White: return Color::Red;
	}

	return Color::White;
}

void MainMenu::RotateColours()
{
	SnakeRevivalGameLoop *SL = SnakeRevivalGameLoop::GetInstance();
	int time = round(SL->m_TimeElapsed*4);
	if (time % 100 == 0) {
		//si blocca perchè m_TimeElapsed, e quindi anche time, diventano più grandi del range consentito per i numeri interi
		m_ColorCounter = IncreaseBW(m_ColorCounter);
		m_S->SetColor(m_ColorCounter);
		
		m_ColorCounter = IncreaseBW(m_ColorCounter);
		m_N->SetColor(m_ColorCounter);

		m_ColorCounter = IncreaseBW(m_ColorCounter);
		m_A->SetColor(m_ColorCounter);

		m_ColorCounter = IncreaseBW(m_ColorCounter);
		m_K->SetColor(m_ColorCounter);

		m_ColorCounter = IncreaseBW(m_ColorCounter);
		m_E->SetColor(m_ColorCounter);
	}
}