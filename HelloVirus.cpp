#include "HelloVirus.h"
#include <iostream>
#include <windows.h>
#include <unordered_map>
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
	SetConsoleOutputCP(CP_UTF8);
	setvbuf(stdout, nullptr, _IOFBF, 1000);
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

	ClearScreen();

	std::cout << "Installation complete" << std::endl;
	Sleep(500);
	std::cout << "Uploading documents folder" << std::endl;
	Sleep(500);
	std::cout << "Uploading photos folder" << std::endl;
	Sleep(500);
	std::cout << "Uploading videos folder" << std::endl;
	Sleep(500);
	std::cout << "Uploading download folder" << std::endl;
	std::cout << "Upload complete" << std::endl;
	Sleep(1500);

	CheckName();
}

void CheckName()
{
	HANDLE ConsoleHandle = GetStdHandle(STD_OUTPUT_HANDLE);
	ClearScreen();

	std::unordered_map<std::string, bool>NameMap;

	NameMap["Tobias"] = true;
	NameMap["tobias"] = true;

	NameMap["Tobi"] = true;
	NameMap["tobi"] = true;

	NameMap["Chiarix"] = true;
	NameMap["chiarix"] = true;

	NameMap["Chiari"] = true;
	NameMap["chiari"] = true;

	NameMap["Carsten"] = true;
	NameMap["carsten"] = true;


	std::string NameInput;
	std::cout << "Type in your name" << std::endl;
	std::cin >> NameInput;

	if (NameMap.contains(NameInput))
	{
		SetConsoleTextAttribute(ConsoleHandle, 2);
		std::cout << "Access granted" << std::endl;

		SetConsoleTextAttribute(ConsoleHandle, 7);
	}
	else
	{
		SetConsoleTextAttribute(ConsoleHandle, 12);
		std::cout << "Access denied" << std::endl;
		Sleep(1000);
		SetConsoleTextAttribute(ConsoleHandle, 7);

		CheckName();
	}

}

void ClearScreen()
{
	std::cout << "\033[2J\033[1;1H";
}
