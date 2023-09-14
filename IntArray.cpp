#include <iostream>
#include <thread>
#include <chrono>
#include <string>
#include "IntMath.h"
#include "myUtils.h"
using namespace std;


int MainMenu()
{
	string myArray[] = { "Basic", "Polynomials", "Factorials", "Exit" };
	return menuUtil(myArray, 4);
}


int BasicMenu()
{
	string equation;
	FancyWords("Please enter a simple equation. Use +, -, * or / and only two terms\n> ");
	cin >> equation;
	int result = ParseSimple(equation);
	FancyWords("\n" + equation + " gives a result of " + to_string(result));
	FancyWords("\nWould you like to do another simple equation, return to the main menu or exit the program\n");
	string myArray[] = { "Basic", "Main menu", "Exit" };
	switch (menuUtil(myArray, 3))
	{
	case 1:
		return 1;
	case 2:
		return 0;
	case 3:
		return 4;
	default:
		break;
	}
}






int main()
{
	int currentMenu = 0;
	bool cont = true;
	FancyWords("Hello, please select a function\n");
	do
	{
		switch (currentMenu)
		{
		case 0:
			currentMenu = MainMenu();
			break;
		case 1:
			currentMenu = BasicMenu();
			break;
		case 2:
			break;
		case 3:
			break;
		case 4:
			cont = false;
			break;
		default:
			break;
		}
	} while (cont);

	return 0;
}