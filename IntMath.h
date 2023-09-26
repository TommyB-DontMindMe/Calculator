#pragma once
#include <string>
#include <algorithm>
#include "myUtils.h"
using namespace std;

int Addition(int a, int b)
{
	return a + b;
}

int Subtraction(int a, int b)
{
	return a - b;
}

int Multiplication(int a, int b)
{
	return a * b;
}

int Division(int a, int b)
{
	return a / b;
}
int Division(int a, int b, int& remainder)
{
	remainder = a % b;
	return a / b;
}

int ParseSimple(string input)
{
	int termA = 0;
	int termB = 0;
	char mOperator;
	int operatorPosition = -1;
	string termProcess = "";
	for (size_t i = 0; i < input.size(); i++)
	{
		if (input[i] == '+' || input[i] == '-' || input[i] == '*' || input[i] == '/')
		{
			if (input[i]=='-'&& (i == 0 || operatorPosition == i-1))
			{
				termProcess += '-';
			}
			else
			{
				operatorPosition = i;
				mOperator = input[i];
				try
				{
					termA = stoi(termProcess);
				}
				catch (const std::exception&)
				{

				}
				termProcess = "";

			}
		}
		else
		{
			termProcess += input[i];
		}
	}
	try
	{
		termB = stoi(termProcess);
	}
	catch (const std::exception&)
	{

	}

	int result;
	if (mOperator == '+')
	{
		result = Addition(termA, termB);
	}
	else if (mOperator == '-')
	{
		result = Subtraction(termA, termB);
	}
	else if (mOperator == '*')
	{
		result = Multiplication(termA, termB);
	}
	else if (mOperator == '/')
	{
		result = Division(termA, termB);
	}
	return result;
}

unsigned long long int Factorial(unsigned long long int n)
{
	if (n == 1 || n==0)
	{
		return 1;
	}
	else
	{
		return n * Factorial(n - 1);
	}
}

bool VerifyFactorial(string input, unsigned long long int &n)
{
	try
	{
		n = stoi(input);
	}
	catch (const std::exception&)
	{
		n = -2;
		return false;
	}
	if (n > 20 || n < 0)
	{
		n = -1;
		return false;
	}
	else
	{
		return true;
	}
}




const int polyTermMax = 15;
struct Polynom
{
	int coefficient[polyTermMax];
};

string WritePolynom(Polynom input)
{
	string output = "";
	for (size_t i = polyTermMax; i > 0; i--)
	{
		if (input.coefficient[i-1] != 0)
		{
			if (output != "" && input.coefficient[i-1] > 0)
			{
				output += '+';
			}

			if (input.coefficient[i-1] != 1)
			{
				output += to_string(input.coefficient[i-1]);
			}
			if (i-1 != 0)
			{
				output += 'X';
				if (i-1 != 1)
				{
					output += '^';
					output += to_string(i-1);
				}
			}
			// cof 0, move on to next cof
			// cof 1, skip n
			// fct 0, skip "X^"
		}
	}
	return output;
}


/// <summary>
/// takes a string with the format "(int)x^(int)+-(int)x^(int)..."
/// </summary>
/// <param name="input"> The string to be parsed </param>
/// <returns> Returns a Polynom struct </returns>
Polynom ParsePolynom(string input)
{
	string currentProcess = "";
	int uCof;
	int currentTerm = 0;
	bool cofOrFct = true;
	Polynom output = {};


	for (size_t i = 0; i < input.size(); i++)
	{
		if (cofOrFct)
		{
			if (isInt(input[i]) || i == 0 && input[i] == '-')
			{
				currentProcess += input[i];
			}
			else if (input[i] == 'X' || input[i] == 'x')
			{
				cofOrFct = false;
				if (currentProcess == "")
				{
					uCof = 1;
				}
				else if (currentProcess == "-")
				{
					uCof = -1;
				}
				else
				{
					uCof = stoi(currentProcess);
					currentProcess = "";
				}
			}
			// if n1+n2 then n1 && n2 >> fct = 0
		}
		else
		{
			if (isInt(input[i]))
			{
				currentProcess += input[i];
			}
			else if (input[i] == '+' || input[i] == '-')
			{
				cofOrFct = true;
				if (currentProcess == "")
				{
					output.coefficient[1] = uCof;
				}
				else
				{
					output.coefficient[stoi(currentProcess)] = uCof;
					currentProcess = "";
				}
				if (input[i] == '-')
					currentProcess += '-';
			}

				// Potential issue: enter multiple terms with the same factor only saves the last one.
			
		}
	}
	if (currentProcess != "")
	{
		if (cofOrFct)
		{
			output.coefficient[0] = stoi(currentProcess);
		}
		else
		{
			output.coefficient[stoi(currentProcess)] = uCof;
		}
	}

	return output;
}


Polynom Addition(Polynom a, Polynom b)
{
	Polynom output;
	for (size_t i = 0; i < polyTermMax; i++)
	{
		output.coefficient[i] = a.coefficient[i] + b.coefficient[i];
	}
	return output;
}

Polynom Multiplication(Polynom a, Polynom b)
{
	Polynom output{};
	for (size_t i = 0; i < polyTermMax; i++)
	{
		if (a.coefficient[i] == 0)
		{
			continue;
		}
		for (size_t n = 0; n < polyTermMax; n++)
		{
			if (b.coefficient[n] != 0)
			{
				Polynom temp{};
				temp.coefficient[i + n] = a.coefficient[i] * b.coefficient[n];
				output = Addition(output, temp);
			}
		}
	}
	return output;
}

Polynom Derivation(Polynom input)
{
	Polynom output{};
	for (size_t i = 0; i < polyTermMax; i++)
	{
		if (i == 0)
			continue;
		output.coefficient[i - 1] = input.coefficient[i] * i;
	}
	return output;
}
