#include<stdio.h>
#include<windows.h>
#include<conio.h>
#include<time.h>

void setcolor(int fg, int bg)
{
	HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
	SetConsoleTextAttribute(hConsole, bg * 16 + fg);
}

char cursor(int x, int y) {
	HANDLE hStd = GetStdHandle(STD_OUTPUT_HANDLE);
	char buf[2]; COORD c = { x,y }; DWORD num_read;
	if (
		!ReadConsoleOutputCharacter(hStd, (LPTSTR)buf, 1, c, (LPDWORD)&num_read))

		return '\0';
	else
		return buf[0];

}

void setcursor(bool visible)
{
	HANDLE console = GetStdHandle(STD_OUTPUT_HANDLE);
	CONSOLE_CURSOR_INFO lpCursor;
	lpCursor.bVisible = visible;
	lpCursor.dwSize = 20;
	SetConsoleCursorInfo(console, &lpCursor);
}

void gotoxy(int x, int y)
{
	COORD c = { x, y };
	SetConsoleCursorPosition(
		GetStdHandle(STD_OUTPUT_HANDLE), c);
}

void plane(int x,int y)
{
	gotoxy(x, y);
	printf(" \\  ^ ");
	gotoxy(x, y+=1);
	printf(" ---O=> ");
	gotoxy(x, y+=1);
	printf(" /  v ");
}

void clearplane(int x, int y)
{
	gotoxy(x, y -=1);
	printf("        ");
	gotoxy(x, y);
	printf("        ");
	gotoxy(x, y += 1);
	printf("        ");
	gotoxy(x, y += 1);
	printf("       ");
	gotoxy(x, y += 1);
	printf("       ");
}

void draw_bullet(int x, int y, int bulletStatus)
{
	int bx[6], by[6];
	bx[bulletStatus] = x;
	by[bulletStatus] = y;
	gotoxy(bx[bulletStatus], by[bulletStatus]);
	printf(" ->");
}

void clear_bullet(int x, int y, int bulletStatus)
{
	int bx[6], by[6];
	bx[bulletStatus] = x;
	by[bulletStatus] = y;
	gotoxy(bx[bulletStatus], by[bulletStatus]);
	setcolor(7, 0);
	printf("   ");
}


int main()
{
	setcursor(0);
/*	struct bullet
	{
		int x;
		int y;
	}bullet; b[10];*/
	char ch = ' ';
	int x = 12, y = 10;
	int bulletx[5], bullety[5];
	int bulletStatus[5];
	for (int i = 0; i <= 5; i++)
	{
		bulletStatus[i] = 0;
	}

	plane(x, y);
	do {
		if (_kbhit()) 
		{
			ch = _getch();
			if (ch == 'a') { plane(--x, y); }
			if (ch == 'd') { plane(++x, y); }
			if (ch == 'w') { clearplane(x, y);  plane(x, --y); }
			if (ch == 's') { clearplane(x, y);  plane(x, ++y); }
			if (bulletStatus[0] == 0 && ch == ' ')
			{
				Beep(700, 50);
				bulletStatus[0] = 1;
				bulletx[0] = x + 8;
				bullety[0] = y + 1;
			}
			else if (bulletStatus[1] == 0 && ch == ' ')
			{
				Beep(700, 50);
				bulletStatus[1] = 1;
				bulletx[1] = x + 8;
				bullety[1] = y + 1;
			}
			else if (bulletStatus[2] == 0 && ch == ' ')
			{
				Beep(700, 50);
				bulletStatus[2] = 1;
				bulletx[2] = x + 8;
				bullety[2] = y + 1;
			}
			else if (bulletStatus[3] == 0 && ch == ' ')
			{
				Beep(700, 50);
				bulletStatus[3] = 1;
				bulletx[3] = x + 8;
				bullety[3] = y + 1;
			}
			else if (bulletStatus[4] == 0 && ch == ' ')
			{
				Beep(700, 50);
				bulletStatus[4] = 1;
				bulletx[4] = x + 8;
				bullety[4] = y + 1;
			}


			fflush(stdin);
		}

		if (bulletStatus[0] == 1)
		{

			clear_bullet(bulletx[0], bullety[0], 0);
			if (bulletx[0] == 50)
			{
				bulletStatus[0] = 0;
			}
			else if (cursor(bulletx[0], bullety[0] - 1) == '*')
			{
				bulletStatus[0] = 0;
			}
			else
			{
				draw_bullet(++bulletx[0], bullety[0], 0);
			}
		}




		if (bulletStatus[1] == 1)
		{
			clear_bullet(bulletx[1], bullety[1], 1);
			if (bulletx[1] == 50)
			{
				bulletStatus[1] = 0;
			}
			else if (cursor(bulletx[1], bullety[1] - 1) == '*')
			{

				bulletStatus[1] = 0;
			}
			else
			{
				draw_bullet(++bulletx[1], bullety[1], 1);
			}
		}
		if (bulletStatus[2] == 1)
		{
			clear_bullet(bulletx[2], bullety[2], 2);
			if (bulletx[2] == 50)
			{
				bulletStatus[2] = 0;
			}
			else if (cursor(bulletx[2], bullety[2] - 1) == '*')
			{

				bulletStatus[2] = 0;
			}
			else
			{
				draw_bullet(++bulletx[2], bullety[2], 2);
			}
		}

		if (bulletStatus[3] == 1)
		{
			clear_bullet(bulletx[3], bullety[3], 3);
			if (bulletx[3] == 50)
			{
				bulletStatus[3] = 0;
			}
			else if (cursor(bulletx[3], bullety[3] - 1) == '*')
			{
				bulletStatus[3] = 0;
			}
			else
			{
				draw_bullet(++bulletx[3], bullety[3], 3);
			}
		}
		if (bulletStatus[4] == 1)
		{
			clear_bullet(bulletx[4], bullety[4], 4);
			if (bulletx[4] == 50)
			{
				bulletStatus[4] = 0;
			}
			else if (cursor(bulletx[4], bullety[4] - 1) == '*')
			{

				bulletStatus[4] = 0;
			}
			else
			{
				draw_bullet(++bulletx[4], bullety[4], 4);
			}
		}
		Sleep(100);
	} while (ch != 'x');
	return 0;


}

