int main()
{
	set_up();
	draw();
	hide_cursor();
	while (!game_over)
	{
		// draw();
		input();
		logic();
		Sleep(1);
	}
	return 0;
}
