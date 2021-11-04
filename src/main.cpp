#include <iostream>
#include <tuple>	

using namespace std;

const char PLAYER_TOKEN = 'x';
const char ENEMY_TOKEN = 'o';

class TicTacToe
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
		cout << "0 |"
			 << " 1 |"
			 << " 2 |"
			 << " 3 |" << endl; // this gets formatted like this for some reason on saving
		cout << "1 | " << gameBoard[0][0] << " | " << gameBoard[0][1] << " | " << gameBoard[0][2] << " |" << endl;
		cout << "2 | " << gameBoard[1][0] << " | " << gameBoard[1][1] << " | " << gameBoard[1][2] << " |" << endl;
		cout << "3 | " << gameBoard[2][0] << " | " << gameBoard[2][1] << " | " << gameBoard[2][2] << " |" << endl;
	}
};

tuple<int, int> playerInput(char currentPlayer){
	int x, y;
	cout << currentPlayer << " Please play your turn as a grid of X-axis index: ";
	cin >> x;
	cout << currentPlayer << " Please play your turn as a grid of Y-axis index: ";
	cin >> y;

	return {x, y};
}

int main()
{
	cout << PLAYER_TOKEN << " plays first" << endl;
	char currentPlayer = PLAYER_TOKEN;

	TicTacToe game;

	while (!game.isWinner(currentPlayer))
	{
		game.printBoard();

		tuple<int, int> turn = playerInput(currentPlayer);
		int x = get<0>(turn) - 1;
		int y = get<1>(turn) - 1;

		while (!((0 <= x) && (x <= 2) && (0 <= y) && (y <= 2))) {
			cout << "please input values withen bounds 1-3" << endl;
			turn = playerInput(currentPlayer);
			x = get<0>(turn) - 1;
			y = get<1>(turn) - 1;
		}
		

		if (game.isEmpty(x, y))
		{
			game.gameBoard[x][y] = currentPlayer;
			if (game.isWinner(currentPlayer))
			{
				cout << currentPlayer << " is the Winner" << endl;
				game.printBoard();
				break;
			}
		}

		if (currentPlayer == PLAYER_TOKEN)
		{
			currentPlayer = ENEMY_TOKEN;
		}
		else
		{
			currentPlayer = PLAYER_TOKEN;
		}
	}

	return 0;
}