#include <iostream>
#include <conio.h>
#include <cstdlib>
#include <ctime>
#include <sstream>
#include <windows.h>
using namespace std;

bool game_over;
const int width = 20;
const int height = 20;
int x, y, fruit_X, fruit_Y, score;
int tail_X[100], tail_Y[100];
int n_tail;

enum e_direction{STOP = 0, LEFT, RIGHT, UP, DOWN};
e_direction dir;

void hide_cursor()
{
	HANDLE consoleHANDLE = GetStdHandle(STD_OUTPUT_HANDLE);
	CONSOLE_CURSOR_INFO info;
	info.dwSize = 100;
	info.bVisible = FALSE;
	SetConsoleCursorInfo(consoleHANDLE, &info);
}

void gotoxy(int x, int y)
{
	COORD coord;
	coord.X = x;
	coord.Y = y;
	SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), coord);
}


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

void input()
{
	if (_kbhit())
	{
		switch (_getch())
		{
		case 'a':
			if (dir != RIGHT) dir = LEFT;
			break;
		case 'd':
			if (dir != LEFT) dir = RIGHT;
			break;
		case 'w':
			if (dir != DOWN) dir = UP;
			break;
		case 's':
			if (dir != UP) dir = DOWN;
			break;
		}
	}
}

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

int main()
{
	set_up();
	draw();
	hide_cursor();
	while (!game_over)
	{
		draw();
		input();
		logic();
		Sleep(1);
	}
	return 0;
}



