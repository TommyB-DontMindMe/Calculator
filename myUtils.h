#pragma once
#include <iostream>
using namespace std;

/// <summary>
/// A function to type out a string one symbol at a time
/// </summary>
/// <param name="words">The string to output</param>
/// <param name="delay">How long to wait between each symbol</param>
/// <param name="variance">How much the wait can deviate from the stated delay</param>
void FancyWords(string words, int delay = 80, int variance = 40)
{
	for (size_t i = 0; i < words.length(); i++)
	{
		cout << words[i];
		this_thread::sleep_for(chrono::milliseconds(delay - variance + rand() % 2 * variance));
	}
	return;
}




int menuUtil(string options[], int optionCount)
{
	for (size_t i = 0; i < optionCount; i++)
	{
		FancyWords(to_string(i+1) + ". " + options[i] + "\n", 60, 30);
	}
	FancyWords("> ");
	bool invalidInput = true;
	do
	{
		string input;
		cin >> input;
		for (size_t i = 0; i < optionCount; i++)
		{
			if (input == to_string(i + 1) || input == options[i])
				return i+1;
		}
		FancyWords("\nI couldn't understand that\nPlease try again\n> ");
	} while (invalidInput);
	return 0;
}