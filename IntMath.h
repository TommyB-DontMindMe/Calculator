#pragma once
#include <string>
#include <algorithm>
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

long int Factorial(long int n)
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

bool VerifyFactorial(string input, long int &n)
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
	if (n > 12 || n < 0)
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
/*
string Polynomial_toString(Polynomial input)
{
	string output = "";

}
*/
string WritePolynom(Polynom input)
{
	string output = "";
	for (size_t i = 0; i < polyTermMax; i++)
	{
		int cachedI = polyTermMax - 1 - i;
		if (input.coefficient[cachedI] != 0)
		{
			if (input.coefficient[cachedI] != 1)
				output += input.coefficient[cachedI];
			if (cachedI != 0)
			{
				output += "X";
				if (cachedI != 1)
					output += "^" + to_string(cachedI);
			}
		}
		output += to_string(input.coefficient[polyTermMax - i]);
	}
	return output;
}


/// <summary>
/// takes a string with the format "(int)x^(int)+/-(int)x^(int)..."
/// </summary>
/// <param name="input"> The string to be parsed </param>
/// <returns> Returns a Polynom struct </returns>
Polynom ParsePolynom(string input)
{
	string currentProcess = "";
	int unplacedCof;
	int currentTerm = 0;
	bool cofOrFct = true;
	Polynom output = {};


	for (size_t i = 0; i < input.size(); i++)
	{
		if (cofOrFct)
		{
			if (input[i] == 'x')
			{
				if (currentProcess == "")
				{
					unplacedCof = 1;
				}
				else
				{
					try
					{
						unplacedCof = stoi(currentProcess);
					}
					catch (const std::exception&)
					{

					}
				}
				currentProcess = "";
				cofOrFct = false;
			}
			else
			{
				currentProcess += input[i];
			}
		}
		else
		{
			if (input[i] == '+' || input[i] == '-')
			{
				try
				{
					currentTerm = stoi(currentProcess);
				}
				catch (const std::exception&)
				{

				}
				output.coefficient[currentTerm] = unplacedCof;
				currentProcess = "";
				if (input[i] == '-')
					currentProcess += '-';
				cofOrFct = true;
			}
			else if (input[i] == '^')
			{

			}
			else
			{
				currentProcess += input[i];
			}
		}
	}

	return output;
}

/*
	Polynom addition (Polynom A + Polynom B)
	Polynom output
	for (Max(A.order, B.order))
		output.coefficient[i] = A.coefficient[i] + B.coefficient[i]
	return output;

	Polynom Multiplication (Polynom A + Polynom B)
	Polynom output
	for (Max(A.order, B.order)
		output.coefficient[i] = A.coefficient[i] * B.coefficient[i]
		output.factor[i] = A.factor[i] + B.factor[i]


*/