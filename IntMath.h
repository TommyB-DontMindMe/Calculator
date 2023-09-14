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


const int polyTermMax = 15;
struct Polynom
{
	int coefficient[polyTermMax];
	int factor[polyTermMax];
	int order;
};
/*
string Polynomial_toString(Polynomial input)
{
	string output = "";

}
*/

Polynom ParsePolynom(string input)
{
	string currentProcess = "";
	int currentTerm = 0;


	Polynom output;
	output.coefficient[0] = 1;
	output.factor[0] = 2;
	// as I iterate through factors, compare with output.order and store the larger value
	// That is: output.factor[currentTerm] = stoi(currentProcess); output.order = Max(output.order, output.factor[currentTerm]);
	output.order ;
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