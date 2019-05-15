#pragma once
#include <memory>

class GameMode
{
private :
	GameMode();
	static std::unique_ptr<GameMode>* instance;

	//Current scores
	//current lenght
	//speed
	//time elapsed
	


public:
	static GameMode* GetInstance();
	~GameMode();
	//update methods if needed
	
};

