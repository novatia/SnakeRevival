#pragma once
#include <memory>
#include "MainMenu.h"

class GameMode
{
private :
	GameMode();
	static GameMode* instance;
	
	//Current scores
	//current lenght
	//speed
	//time elapsed
	
public:
	MainMenu menu;
	static GameMode* GetInstance();
	~GameMode();
	//update methods if needed
	
};

