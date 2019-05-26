#pragma once
#include <list>

namespace gamestructure {
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
	public:
		void SetCurrentDirection(Direction newDirection) {
			if (currentDirection == Direction::Right || currentDirection == Direction::Left) {
				if (newDirection == Direction::Down || newDirection == Direction::Up) {
					currentDirection = newDirection;
				}
			}
			else {
				if (newDirection == Direction::Right || newDirection == Direction::Left) {
					currentDirection = newDirection;
				}
			}
		}
	private:
		Direction currentDirection;
	};
	class Game
	{
	public:
		Game();
		~Game();
	};
}

