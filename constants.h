#pragma once
#define DISPLAY_WIDTH 80
#define DISPLAY_HEIGHT 25
#define COLOR_HEADER 9
#define TICKS_PER_FRAME 0.16f


#define KEY_UP 72
#define KEY_DOWN 80
#define KEY_LEFT 75
#define KEY_RIGHT 77
#define ENTER 13

namespace SnakeRevival 
{
	enum class Color { None, Red, Green, Blue, Yellow, Purple, White };
	enum class Alignment { Left, Right, Center, Top, Bottom };
	enum class Key { Up, Down, Left, Right, Enter, Any, Error};
	enum class Direction { Up, Down, Left, Right };

}