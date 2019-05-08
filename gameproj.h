#pragma once
#include <list>
using namespace std;

namespace gameproj {
	enum class Direction 
	{
		
		Right=0,
		Left = 1,
		Down=2,
		Up =3,

	};
	struct position 
	{
		int x;
		int y;
	};
	struct Player 
	{
		list<position> snake;
		Direction movementDirection;
	};
	class Game
	{
	public:
		Game();
		~Game();
	};
}

