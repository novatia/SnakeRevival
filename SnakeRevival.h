#pragma once
#include "GameMode.h"
#include "MainMenu.h"

using namespace gamestructure;

class SnakeRevival
{

private:
	GameMode* gm;
	
public:
	SnakeRevival();
	~SnakeRevival();
	void Start();
};
