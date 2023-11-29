#include<iostream>
#include<cstdlib>
#include <string>
#include<sstream>
using namespace std;
bool playgame();		
int getrandnum(int minnum, int maxnum);
int guessing();
int getIntegerInput(string promptMessage, string errorMessage);
int getPositiveIntegerInput(string promptMessage, string errorMessage);
int main()
{
	srand(time(0));
	cout << "welcome to the guessing game enter 'q' to quit or 'p' to play\n";
	string input;
	while (true)
	{
		if (!playgame()) {
			break;
		}
	}
	cout << "thanks for playing";
}

int getrandnum(int minnum, int maxnum)
{
	return (rand() % (maxnum - minnum + 1)) + minnum;
}

int guessing()
{
	int maxtries = getPositiveIntegerInput("Enter the amount of tries you want: ", "Invalid input. Please enter a positive integer.\n");
	int minnum = getIntegerInput("Minimum number: ", "Invalid input. Please enter an integer.\n");
	int maxnum = getIntegerInput("Maximum number: ", "Invalid input. Please enter an integer.\n");

	int tries = 0;
	int randnum = getrandnum(minnum, maxnum);
	cout << "welcome you have " << maxtries << " guesses\n";
	while (tries < maxtries)
	{
		while (tries < maxtries)
		{
			cout << "Enter your guess: ";
			string input;
			getline(cin, input);
			stringstream ss(input);
			int guess;
			if (ss >> guess && ss.eof())
			{  // Check if conversion succeeded and input ended
				if (tries !=maxtries&&guess < randnum && guess >= minnum)
				{
					cout << "Too low!\n";
				}
				else if (tries!=maxtries &&guess > randnum && guess <= maxnum)
				{
					cout << "Too high\n";
				}
				else if (guess < minnum || guess > maxnum)
				{
					cout << "The number you entered is not within the given range\n";
					tries--;
				}
				else if (guess == randnum)
				{
					cout << "You got it!\n";
					cout << "enter 'q' to quit or 'p' to play\n";
				
					return true;
				}
			}
			else {
				cout << "Invalid input. Please enter an integer.\n";
				tries--;
			}
			tries++;
			if (maxtries - tries > 0)
				cout << "You have " << maxtries - tries << " guesses left\n";
		}
	}
	if (tries == maxtries)
	{
		cout << "you ran out of guesses\n";
		cout << "The number was: " << randnum << endl;
		cout << "enter 'q' to quit or 'p' to play\n";
	}

	return true;
}


bool playgame()
{
	string input;
	getline(cin, input);
	if (input == "q")
	{
		return false;
	}
	if (input == "p")
	{
		guessing();
		if (cin.peek() == '\n')  // Check if there's a newline character left in the input stream
		{
			cin.ignore();
		}

		return true;
	}
	else
	{
		cout << "that was not a valid input\n";
		cout << "enter 'q' to quit or 'p' to play\n";
		return true;
	}
}

int getIntegerInput(string promptMessage, string errorMessage) {
	int num;
	string input;
	while (true) {
		cout << promptMessage;
		getline(cin, input);
		stringstream ss(input);
		if (ss >> num && ss.eof())
		{  // Check if conversion succeeded and input ended
				break;
		}
		else {
			cout << errorMessage;
		}
	}
	return num;
}
int getPositiveIntegerInput(string promptMessage, string errorMessage)
{
	int num;
	string input;
	while (true) {
		cout << promptMessage;
		getline(cin, input);
		stringstream ss(input);
		if (ss >> num && ss.eof())
		{  
			if(num>0)
				break;
			else
				cout << errorMessage;

		}
		else {
			cout << errorMessage;
		}
	}
	return num;
}