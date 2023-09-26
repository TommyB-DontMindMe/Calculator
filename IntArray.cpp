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

int PolynomialMenu()
{
	FancyWords("Please select an operation\n");
	string polynomString;
	string polyOptions[] = {"Addition", "Multiplication", "Derivation"};
	Polynom a, b, output;
	switch (menuUtil(polyOptions, 3))
	{
	case 1:
		FancyWords("Please input the first polynom, (for example 2x^3+3x^2)\n> ");
		cin >> polynomString;
		a = ParsePolynom(polynomString);
		FancyWords("\nAnd now input the second polynom\n> ");
		cin >> polynomString;
		b = ParsePolynom(polynomString);
		output = Addition(a, b);
		FancyWords("\nThe sum of your two polynoms is " + WritePolynom(output) + "\n");
		break;
	case 2:
		FancyWords("Please input the first polynom, (for example 2x^3+3x^2)\n> ");
		cin >> polynomString;
		a = ParsePolynom(polynomString);
		FancyWords("\nAnd now input the second polynom\n> ");
		cin >> polynomString;
		b = ParsePolynom(polynomString);
		output = Multiplication(a, b);
		FancyWords("\nThe product of your two polynoms are " + WritePolynom(output) + "\n");
		break;
	case 3:
		FancyWords("Please input a polynom to derivate, (for example 2x^3+3x^2)\n> ");
		cin >> polynomString;
		a = ParsePolynom(polynomString);
		output = Derivation(a);
		FancyWords("Deriving your polynom gives " + WritePolynom(output) + "\n");
		break;
	default:
		break;
	}
	FancyWords("Would you like to handle other polynomials, return to the main menu or exit the program\n");
	string myArray[] = {"Polynomials", "Main menu", "Exit"};
	switch (menuUtil(myArray, 3))
	{
	case 1:
		return 2;
	case 2:
		return 0;
	case 3:
		return 4;
	default:
		break;
	}
}

int FactorialMenu()
{
	string number;
	FancyWords("Please enter the number you would like the factorial of\n> ");
	cin >> number;
	unsigned long long int result;
	if (!VerifyFactorial(number, result))
	{
		if (result == -1)
		{
			FancyWords("\nI'm sorry that number is out of bounds.\nWould you like to try again?\n");
		}
		else if (result == -2)
		{
			FancyWords("\nI'm sorry I couldn't recognize that number.\nWould you like to try again?\n");
		}
	}
	else
	{
		FancyWords("\n" + number + "! = " + to_string(Factorial(result)));
		FancyWords("\nWould you like to do another factorial, return to the main menu or exit the program\n");
	}
	string myArray[] = { "Factorial", "Main menu", "Exit" };
	switch (menuUtil(myArray, 3))
	{
	case 1:
		return 3;
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
			currentMenu = PolynomialMenu();
			break;
		case 3:
			currentMenu = FactorialMenu();
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