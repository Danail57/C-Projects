void logic()
{
	if (n_tail > 0)
	{
		int previous_X = tail_X[0];
		int previous_Y = tail_Y[0];
		int prev_2X, prev_2Y;
		tail_X[0] = x;
		tail_Y[0] = y;

		for (int i = 1; i < n_tail; i++)
		{
			prev_2X = tail_X[i];
			prev_2Y = tail_Y[i];
			tail_X[i] = previous_X;
			tail_Y[i] = previous_Y;
			previous_X = prev_2X;
			previous_Y = prev_2Y;
		}
	}
	switch (dir)
	{
	case LEFT:
		x--;
		break;
	case RIGHT:
		x++;
		break;
	case UP:
		y--;
		break;
	case DOWN:
		y++;
		break;
	default:
		break; 
	}
	if (x >= width || x < 0 || y >= height || y < 0)
		game_over = true;
	
	for (int i = 0; i < n_tail; i++)
		if (tail_X[i] == x && tail_Y[i] == y)
			game_over = true;

	if (x == fruit_X && y == fruit_Y)
	{
		score += 10;
		fruit_X = rand() % width;
		fruit_Y = rand() % height;
		n_tail++;
	}
}
