#include <iostream>
#include <time.h>
#include <tuple>
#include <array>
#include <vector>
#include <random>

using namespace std;

const char PLAYER_TOKEN = 'x';
const char ENEMY_TOKEN = 'o';

class TicTacToe
{
public:
	array<array<char, 3>, 3> gameBoard = {{
		{'.', '.', '.'},
		{'.', '.', '.'},
		{'.', '.', '.'},
	}};

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

tuple<int, int> playerInput()
{
	int x, y;
	cout << "x Please play your turn as a grid of X-axis index: ";
	cin >> x;
	cout << "x Please play your turn as a grid of Y-axis index: ";
	cin >> y;

	return {x, y};
}

vector<int> randomPosition()
{
	vector<int> randomPosition;

	random_device rd;
	mt19937 gen(rd());
	uniform_int_distribution<> distrib(0, 2);

	for (int i = 0; i < 2; i++)
	{
		randomPosition.push_back(distrib(gen));
	}

	return randomPosition;
}

int main()
{
	cout << PLAYER_TOKEN << " plays first" << endl;
	char currentPlayer = PLAYER_TOKEN;

	TicTacToe game;

	while (!game.isWinner(currentPlayer))
	{
		game.printBoard();

		if (currentPlayer == ENEMY_TOKEN)
		{

			vector<tuple<int, int>> validTurns;

			// TOP MIDDLE
			if (game.gameBoard[0][1] == PLAYER_TOKEN)
			{
				if (game.gameBoard[0][0] == PLAYER_TOKEN)
				{
					validTurns.push_back({0, 2});
				}
				if (game.gameBoard[0][2] == PLAYER_TOKEN)
				{
					validTurns.push_back({0, 0});
				}
				if (game.gameBoard[1][1] == PLAYER_TOKEN)
				{
					validTurns.push_back({2, 1});
				}
			}
			// LEFT MIDDLE
			if (game.gameBoard[1][0] == PLAYER_TOKEN)
			{
				if (game.gameBoard[0][0] == PLAYER_TOKEN)
				{
					validTurns.push_back({2, 0});
				}
				if (game.gameBoard[2][0] == PLAYER_TOKEN)
				{
					validTurns.push_back({0, 0});
				}
				if (game.gameBoard[1][1] == PLAYER_TOKEN)
				{
					validTurns.push_back({1, 2});
				}
			}
			// RIGHT MIDDLE
			if (game.gameBoard[1][2] == PLAYER_TOKEN)
			{
				if (game.gameBoard[0][2] == PLAYER_TOKEN)
				{
					validTurns.push_back({2, 2});
				}
				if (game.gameBoard[2][2] == PLAYER_TOKEN)
				{
					validTurns.push_back({0, 2});
				}
				if (game.gameBoard[1][1] == PLAYER_TOKEN)
				{
					validTurns.push_back({0, 1});
				}
			}
			// BOTTOM MIDDLE
			if (game.gameBoard[2][1] == PLAYER_TOKEN)
			{
				if (game.gameBoard[2][0] == PLAYER_TOKEN)
				{
					validTurns.push_back({2, 2});
				}
				if (game.gameBoard[2][2] == PLAYER_TOKEN)
				{
					validTurns.push_back({2, 0});
				}
				if (game.gameBoard[1][1] == PLAYER_TOKEN)
				{
					validTurns.push_back({0, 1});
				}
			}
			// DIAGONALS
			if (game.gameBoard[1][1] == PLAYER_TOKEN)
			{
				if (game.gameBoard[0][0] == PLAYER_TOKEN)
				{
					validTurns.push_back({2, 2});
				}
				if (game.gameBoard[2][2] == PLAYER_TOKEN)
				{
					validTurns.push_back({0, 0});
				}
				if (game.gameBoard[0][2] == PLAYER_TOKEN)
				{
					validTurns.push_back({2, 0});
				}
				if (game.gameBoard[2][0] == PLAYER_TOKEN)
				{
					validTurns.push_back({0, 2});
				}
			}

			for (int i = 0; i < 9; i++)
			{
				vector<int> computerTurn = randomPosition();
				int x = computerTurn[0];
				int y = computerTurn[1];

				if (!(game.gameBoard[x][y] == PLAYER_TOKEN))
				{
					validTurns.push_back({x, y});
					break;
				}
			}

			srand(time(0));
			tuple<int, int> computerTurn = validTurns[rand() % validTurns.size()];
			int computerTurnX = get<0>(computerTurn);
			int computerTurnY = get<1>(computerTurn);

			while (!(game.isEmpty(computerTurnX, computerTurnY)))
			{
				srand(time(0));
				tuple<int, int> computerTurn = validTurns[rand() % validTurns.size()];
				computerTurnX = get<0>(computerTurn);
				computerTurnY = get<1>(computerTurn);
			}

			game.gameBoard[computerTurnX][computerTurnY] = ENEMY_TOKEN;
			cout << ENEMY_TOKEN << " played at position x: " << get<0>(computerTurn) + 1 << " y: " << get<1>(computerTurn) + 1 << endl;

			if (game.isWinner(currentPlayer))
			{
				cout << currentPlayer << " is the Winner" << endl;
				game.printBoard();
				break;
			}
			currentPlayer = PLAYER_TOKEN;
		}
		else
		{
			tuple<int, int> turn = playerInput();
			int x = get<0>(turn) - 1;
			int y = get<1>(turn) - 1;

			while (!((0 <= x) && (x <= 2) && (0 <= y) && (y <= 2)))
			{
				cout << "please input values withen bounds 1-3" << endl;
				turn = playerInput();
				x = get<0>(turn) - 1;
				y = get<1>(turn) - 1;
			}

			if (game.isEmpty(x, y))
			{
				game.gameBoard[x][y] = PLAYER_TOKEN;

				if (game.isWinner(currentPlayer))
				{
					cout << currentPlayer << " is the Winner" << endl;
					game.printBoard();
					break;
				}
			}

			currentPlayer = ENEMY_TOKEN;
		}
	}

	return 0;
}