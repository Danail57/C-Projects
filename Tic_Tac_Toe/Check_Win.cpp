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
