#include<iostream>
#include<cstdlib>
#include<cctype>
#include <string>
using namespace std;
bool playgame ();
int getrandnum(int minnum, int maxnum);
int guessing();
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
	int maxtries, minnum, maxnum;
	cout << "enter the amount of tries you want: ";
	cin >> maxtries;
	if (cin.fail())
	{
		cin.clear();
		cin.ignore();
		cout << "invalid input\nenter the amount of tries you want: ";
		cin >> maxtries;
	}
	cout << "enter the range of numbers you want\n";
	cout << "minimum number: ";
	cin >> minnum;
	if (cin.fail())
	{
		cin.clear();
		cin.ignore();
		cout << "invalid input\nminimum number: ";
		cin >> minnum;
	}
	cout << "maximum number: ";
	cin >> maxnum;
	if (cin.fail())
	{
		cin.clear();
		cin.ignore();
		cout << "invalid input\nmaximum number: ";
		cin >> maxnum;
	}
	int tries = 0;
	int randnum = getrandnum(minnum, maxnum);
	cout << randnum << endl;
	cout << "welcome you have " << maxtries << " guesses\n";
	while (tries < maxtries)
	{
		int guess;
		cin >> guess;
		if (cin.fail())
		{
				cin.clear();
				cin.ignore();
		}
	    if (guess < randnum && guess >= minnum )
	    {
		    cout << "too low!\n";
	    }
	    else if (guess > randnum && guess <= maxnum)
	    {
	    	cout << "too high\n";
	    }
		else if (guess < minnum || guess > maxnum)
		{
			cout << "the number you entered is not within the given range or the input was invalid\n";
			tries--;
		}	
		else if (guess == randnum)
		{
			cout << "you got it!\n";
			break;
		}
		tries++;
	}
	if (tries == maxtries)
	{
		cout << "you ran out of guesses\n";
		cout << "The number was: " << randnum << endl;
	}
	cout << "enter 'q' to quit or 'p' to play\n";
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
		cin.ignore();
		return true;
	}
	else
	{
		cout << "that was not a valid input\n";
		cout << "enter 'q' to quit or 'p' to play\n";
		return true;
	}

}