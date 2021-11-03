#include <iostream>

using namespace std;

const char PLAYER_TOKEN = 'x';
const char  ENEMY_TOKEN = 'o';

class Game
{
public:
	char gameBoard[3][3] = {
		{'.', '.', '.'},
		{'.', '.', '.'},
		{'.', '.', '.'},
	};

	int isEmpty(int x, int y)
	{
		if (gameBoard[x][y] == '.')
		{
			return 1;
		}
		else
		{
			return 0;
		}
	}

	int isWinner(char player)
	{
		// checks all rows
		if ((gameBoard[0][0] == player && gameBoard[0][1] == player && gameBoard[0][2] == player) ||
			(gameBoard[1][0] == player && gameBoard[1][1] == player && gameBoard[1][2] == player) ||
			(gameBoard[2][0] == player && gameBoard[2][1] == player && gameBoard[2][2] == player))
		{
			return 1;
		}

		// checks all columns
		if ((gameBoard[0][0] == player && gameBoard[1][0] == player && gameBoard[2][0] == player) ||
			(gameBoard[0][1] == player && gameBoard[1][1] == player && gameBoard[2][1] == player) ||
			(gameBoard[0][2] == player && gameBoard[1][2] == player && gameBoard[2][2] == player))
		{
			return 1;
		}
		
		// checks all diagonals
		if ((gameBoard[0][0] == player && gameBoard[1][1] == player && gameBoard[2][2] == player) ||
			(gameBoard[0][2] == player && gameBoard[1][1] == player && gameBoard[2][0] == player))
		{
			return 1;
		}
		return 0;
	}

	void printBoard()
	{	
		// cout << "0 |" << " 1 |" << " 2 |" << " 3 |" << endl;
		cout << "0 |" << " 1 |" << " 2 |" << " 3 |" << endl;
		cout << "1 | " << gameBoard[0][0] << " | " << gameBoard[0][1] << " | " << gameBoard[0][2] << " |" << endl;
		cout << "2 | " << gameBoard[1][0] << " | " << gameBoard[1][1] << " | " << gameBoard[1][2] << " |" << endl;
		cout << "3 | " << gameBoard[2][0] << " | " << gameBoard[2][1] << " | " << gameBoard[2][2] << " |" << endl;
	}
};

int main()
{
	Game game;
	game.printBoard();
	
	return 0;
}