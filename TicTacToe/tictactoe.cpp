#include<iostream>
#include<cstdlib>
using namespace std;
void drawBoard(char *board);
void playerTurn(char* board, char player);
void computerTurn(char* board, char copmuter);
bool checkTie(char* board);
bool checkWin(char* board, char player, char computer);
int main()
{

	char board[] = {' ', ' ', ' ',' ',' ',' ',' ',' ',' '};
	char player = 'X';
	char computer = 'O';
	bool running = true;
	drawBoard(board);
	while (running)
	{
		playerTurn(board, player);
		 if(checkTie(board))
		 {
			 running = false;
			 break;
		 }
		 else if (checkWin(board, player, computer))
		 {
			 running = false; 
			 break;
		 }
		computerTurn(board, computer);
		if (checkTie(board))
		{
			running = false;
			break;
		}
		else if (checkWin(board, player, computer))
		{
			running = false;
			break;
		}
	}
	cout << "thanks for playing";
	return 0;
		
}
void drawBoard(char* board)
{
	cout << "     |     |     \n";
	cout << "  " << board[0] << "  |  " << board[1] << "  |  " << board[2] << "  \n";
	cout << "_____|_____|_____\n";
	cout << "     |     |     \n";
	cout << "  " << board[3] << "  |  " << board[4] << "  |  " << board[5] << "  \n";
	cout << "_____|_____|_____\n";
	cout << "     |     |     \n";
	cout << "  " << board[6] << "  |  " << board[7] << "  |  " << board[8] << "  \n";
	cout << "     |     |     \n\n";
}
void playerTurn(char* board, char player)
{
	cout << "enter which space you want to fill(1-9): ";
	int number = 0;
	while (true)
	{
		cin >> number;
		number--;
		if ( number < 9 && board[number] == ' ')
			break;
		else {
			cout << "please enter a valid number\n";
		}
	}
	board[number] = player;
	drawBoard(board);

}
void computerTurn(char *board, char computer)
{
	srand(time(0));
	int number;
	while (true)
	{
	 number = rand() % 9;
	 if (board[number] == ' ')
		 break;
	}
	board[number] = computer;
	drawBoard(board);
}
bool checkTie(char *board)
{
	for (int i = 0; i < 9;i++)
	{
		if (board[i] == ' ')
			return false;

	}
	cout << "Its a tie!!!\n";
	return true;
}
bool checkWin(char* board, char player, char computer)
{
	if (board[0] != ' ' && board[0] == board[1] && board[1] == board[2]) {
		board[0] == player ? cout << "You win!!!\n" : cout << "you lose\n";
		return true;
	}


	if (board[3] != ' ' && board[3] == board[4] && board[4] == board[5]){
		board[3] == player ? cout << "You win!!!\n" : cout << "you lose\n";
		return true;
}

		if (board[6] != ' ' && board[6] == board[7] && board[7] == board[8]){
			board[6] == player ? cout << "You win!!!\n" : cout << "you lose\n";
			return true;
}

		if (board[0] != ' ' && board[0] == board[3] && board[3] == board[6]){
			board[0] == player ? cout << "You win!!!\n" : cout << "you lose\n";
			return true;
}

		if (board[1] != ' ' && board[1] == board[4] && board[4] == board[7]){
			board[1] == player ? cout << "You win!!!\n" : cout << "you lose\n";
			return true;
}
		if (board[2] != ' ' && board[2] == board[5] && board[5] == board[8]) {
			board[2] == player ? cout << "You win!!!\n" : cout << "you lose\n";
			return true;
		}
	if (board[0] != ' ' && board[0] == board[4] && board[4] == board[8]) {
		board[0] == player ? cout << "You win!!!\n" : cout << "you lose\n";
		return true;
	}
		if (board[2] != ' ' && board[2] == board[4] && board[4] == board[6]) 
		{
			board[2] == player ? cout << "You win!!!\n" : cout << "you lose\n";
			return true;
		}
	else {
		return false;
	}

	return true;
}