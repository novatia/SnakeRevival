#pragma once
#define DISPLAY_WIDTH 80
#define DISPLAY_HEIGHT 25
#define COLOR_HEADER 9
#define TICKS_PER_FRAME 65
#define GAMESPEED 0.25f

#define KEY_UP 72
#define KEY_DOWN 80
#define KEY_LEFT 75
#define KEY_RIGHT 77
#define ENTER 13

namespace SnakeRevival 
{
	enum class Color { Red, Green, Blue, Yellow, Purple, White };
	enum class Alignment { Left, Right, Center, Top, Bottom, None, Ignore};
	enum class Key { Up, Down, Left, Right, Enter, Any, Error};
	enum class Direction { Up, Down, Left, Right };

	template <typename Diff>
	std::wstring log_progress(Diff duration, std::chrono::milliseconds elapsed_ticks, std::chrono::milliseconds time_interval)
	{
		long time_interval_duration = std::chrono::duration_cast<std::chrono::milliseconds>(duration).count();
		
		float fps = 1000.0f / time_interval_duration;
		std::wstring str = L"" + std::to_wstring(fps)+ L"   " + std::to_wstring(elapsed_ticks.count()) + L" ms   " + std::to_wstring(time_interval.count()) + L" ms";
		return str;
	}


	static std::wstring EmptyColorifiedString(int size, std::wstring color) 
	{
		std::wstring res_string = L"";
		for (int i = 0; i < size - 1; i++)
		{
			res_string += color + L" " + L"\033[0m";
		}

		return res_string;
	}
}