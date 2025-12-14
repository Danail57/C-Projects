#include <iostream>
#include <cstdlib>
#include <ctime>
using namespace std;

int scoreX = 0;
int scoreO = 0;
char board[3][3];
char current_player;

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
