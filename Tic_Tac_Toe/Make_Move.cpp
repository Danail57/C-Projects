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
