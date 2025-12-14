
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
