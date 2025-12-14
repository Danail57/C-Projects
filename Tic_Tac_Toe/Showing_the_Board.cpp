
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
