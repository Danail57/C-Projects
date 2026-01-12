void set_up()
{
	game_over = false;
	dir = STOP;
	x = width / 2;
	y = height / 2;
	srand(time(0));
	fruit_X = rand() % width;
	fruit_Y = rand() % height;
	score = 0;
	n_tail = 0;
}
