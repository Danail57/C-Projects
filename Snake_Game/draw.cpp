void draw()
{
	gotoxy(0, 0);

	ostringstream buffer;

	for (int i = 0; i < width + 2; i++)
		buffer << "#";
	buffer << "\n";

	for (int i = 0; i < height; i++)
	{
		for (int j = 0; j < width; j++)
		{
			if (j == 0)
				buffer << "#";

			if (i == y && j == x)
				buffer << "O";
			else if (i == fruit_Y && j == fruit_X)
				buffer << "F";
			else
			{
				bool print = false;
				for (int k = 0; k < n_tail; k++)
				{
					if (tail_X[k] == j && tail_Y[k] == i)
					{
						buffer << "o";
						print = true;
						break;
					}
				}
				if (!print)
					buffer << " ";
			}

			if (j == width - 1)
				buffer << "#";
		}
		buffer << "\n";
	}

	for (int i = 0; i < width + 2; i++)
		buffer << "#";
	buffer << "\n";

	buffer << "Score: " << score << "\n";

	cout << buffer.str();
}
