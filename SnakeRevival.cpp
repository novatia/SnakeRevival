// SnakeRevival.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include "pch.h"




int main()
{

    std::cout << "Hello World!\n"; 
	while (true) {
		if (_kbhit()) {
			unsigned char input = _getch();
			std::cout << input;
			std::cout << std::endl;

			std::cout << clock() << std::endl;
			std::cout << CLOCKS_PER_SEC << std::endl;
			//std::cout << (unsigned int)input;
			if (input == 'K')
				std::cout << "left" << std::endl;
			if (input == 'M')
				std::cout << "right" << std::endl;
			if (input == 'H')
				std::cout << "up" << std::endl;
			if (input == 'P')
				std::cout << "down" << std::endl;
			if (input == 'x') {
				std::cout << "exiting at time: " << std::endl;
				std::cout << clock() << std::endl;

				std::cout << input;
				break;
			}
		}

	}
}


// Run program: Ctrl + F5 or Debug > Start Without Debugging menu
// Debug program: F5 or Debug > Start Debugging menu

// Tips for Getting Started: 
//   1. Use the Solution Explorer window to add/manage files
//   2. Use the Team Explorer window to connect to source control
//   3. Use the Output window to see build output and other messages
//   4. Use the Error List window to view errors
//   5. Go to Project > Add New Item to create new code files, or Project > Add Existing Item to add existing code files to the project
//   6. In the future, to open this project again, go to File > Open > Project and select the .sln file
