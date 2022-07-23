#include "HelloVirus.h"
#include <iostream>
#include <windows.h>
#include "progressbar.hpp"


const int Blue = 1;
const int Green = 2;
const int Red = 4;
const int Purple = 5;
const int Yellow = 6;
const int White = 7;
const int Gray = 8;

void main()
{
	StartUp();
}

void StartUp()
{
	progressbar bar(100);
	bar.set_done_char("█");

	std::cout << "Preparing for installation" << std::endl;
	Sleep(1500);
	std::cout << "Configuring storage" << std::endl;
	Sleep(500);
	std::cout << "Configuring network" << std::endl;
	std::cout << "Downloading additional data" << std::flush;
	for (int i = 0; i < 8; i++)
	{
		std::cout << "." << std::flush;
		Sleep(500 * i);
	}
	std::cout << std::endl;

	std::cout << "Installing data" << std::endl;
	for (int i = 0; i < 100; i++)
	{
		bar.update();
		Sleep(100);
	}

}

void ColorChangeOutput(std::string output, int color)
{
	HANDLE ConsoleHandle = GetStdHandle(STD_OUTPUT_HANDLE);

	SetConsoleTextAttribute(ConsoleHandle, color);

	std::cout << "Penis" << std::endl;
}

void Clearscreen()
{
	std::cout << "\033[2J\033[1;1H";
}
