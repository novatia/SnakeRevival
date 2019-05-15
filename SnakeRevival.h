#pragma once
#include "GameMode.h"
#include "MainMenu.h"

class SnakeRevival
{

private:
	GameMode* gm;
	Draw *menu;

public:
	SnakeRevival();
	~SnakeRevival();
	void Start();
};

