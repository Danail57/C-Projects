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
