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
