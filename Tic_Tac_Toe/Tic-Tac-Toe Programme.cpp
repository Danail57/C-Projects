// Tic-Tac-Toe Programme

#include <iostream>
#include <cstdlib>
#include <ctime>
using namespace std;

int scoreX = 0;
int scoreO = 0;
char board[3][3];
char current_player;

void in_it_board()
{
	char cell = '1';
	for (int i = 0; i < 3; i++)
	{
		for (int j = 0; j < 3; j++)
		{
			board[i][j] = cell++;
		}
	}
}

void print_board()
{
	cout << "\n";
	for (int i = 0; i < 3; i++)
	{
		cout << " ";
		for (int j = 0; j < 3; j++)
		{
			cout << board[i][j];
			if (j < 2)
				cout << " | ";
		}
		cout << endl;
		if (i < 2)
			cout << "---+---+---\n";
	}
	cout << "\n";
}

bool make_move(int choice)
{
	for (int i = 0; i < 3; i++)
	{
		for (int j = 0; j < 3; j++)
		{
			if (board[i][j] == choice + '0')
			{
				board[i][j] = current_player;
				return true;
			}
		}
	}
	return false;
}

void computer_move()
{
	int choice;
	while (true)
	{
		choice = rand() % 9 + 1;
		if (make_move(choice))
			break;
	}
}


bool check_win()
{
	for (int i = 0; i < 3; i++)
	{
		if (board[i][0] == current_player &&
			board[i][1] == current_player &&
			board[i][2] == current_player)
			return true;

		if (board[0][i] == current_player &&
			board[1][i] == current_player &&
			board[2][i] == current_player)
			return true;
	}
	if (board[0][0] == current_player &&
		board[1][1] == current_player &&
		board[2][2] == current_player)
		return true;

	if (board[0][2] == current_player &&
		board[1][1] == current_player &&
		board[2][0] == current_player)
		return true;
	return false;
}

bool check_draw()
{
	for (int i = 0; i < 3; i++)
		for (int j = 0; j < 3;j++)
			if (board[i][j] != 'X' && board[i][j] != 'O')
				return false;
	return true;
}

void switch_player()
{
	current_player = (current_player == 'X') ? 'O' : 'X';
}

void play_game()
{
	in_it_board();
	current_player = 'X';
	while (true)
	{
		print_board();
		cout << "Score -> X: " << scoreX << " | O: " << scoreO << "\n";
		int choice;

		cout << "Player " << current_player << ", choose a position (1 - 9): ";
		cin >> choice;

		if (!make_move(choice))
		{
			cout << "Invalid move! Try again.\n";
			continue;
		}
		
		if (check_win())
		{
			print_board();
			cout << "Player " << current_player << " wins!\n";
		

			if (current_player == 'X')
				scoreX++;
			else
				scoreO++;
			
			break;
		}
		
		if (check_draw())
		{
			print_board();
			cout << "It is a draw!\n";
			break;
		}
		switch_player();
	}
}

void play_pvc()
{
	in_it_board();
	current_player = 'X';
	while (true)
	{
		print_board();

		if (current_player == 'X')
		{
			cout << "Player X, choose position (1-9): ";
			int choice;
			cin >> choice;

			if (!make_move(choice))
			{
				cout << "Invalid move! Try again!\n";
				continue;
			}
		}
		else
		{
			cout << "Computer is making a move...\n";
			computer_move();
		}

		if (check_win())
		{
			print_board();
			if (current_player == 'X')
				cout << "You win!\n";
			else
				cout << "Computer wins!\n";
			break;
		}
		if (check_draw())
		{
			print_board();
			cout << "Draw!\n";
			break;
		}
		switch_player();
	}
}

int menu()
{
	int choice;
	cout << "==== TIC TAC TOE ====\n";
	cout << "1. Player vs Player\n";
	cout << "2. Player vs Computer\n";
	cout << "0. Exit\n";
	cout << "Choose option: ";
	cin >> choice;
	return choice;
}



int main()
{
	srand(time(0));

	while (true)
	{
		int choice = menu();

		if (choice == 1)
			play_game();
		else if (choice == 2)
			play_pvc();
		else if (choice == 0)
			break;
		else
			cout << "Invalid option!\n";

		cout << "\nPress Enter to continue...";
		cin.ignore();
		cin.get();
	}

	return 0;
}
