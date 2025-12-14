
void computer_move()
{
	int choice;
	while (true)
	{
		choice = rand() % 9 + 1;
		if (make_move(choice))
			break;
	}
}
