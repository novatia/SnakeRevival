#include "pch.h"
#include "MainMenu.h"
#include "VerticalLayout.h"
#include "SLetter.h"
#include "NLetter.h"
#include "ALetter.h"
#include "KLetter.h"
#include "ELetter.h"


MainMenu::MainMenu()
{
	root_object = std::make_unique<VerticalLayout>();

	root_object->Add(new SLetter());
	root_object->Add(new NLetter());
	root_object->Add(new ALetter());
	root_object->Add(new KLetter());
	root_object->Add(new ELetter());
}

std::string MainMenu::GetView() {
	std::string draw;

	int height = root_object->GetHeight();

	for (int row = 0; row < height; row++) {
		draw += root_object->GetRow(row);
		draw += "\n";
	}

	return draw;
}

MainMenu::~MainMenu()
{
}
