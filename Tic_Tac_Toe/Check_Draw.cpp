bool check_draw()
{
	for (int i = 0; i < 3; i++)
		for (int j = 0; j < 3;j++)
			if (board[i][j] != 'X' && board[i][j] != 'O')
				return false;
	return true;
}
