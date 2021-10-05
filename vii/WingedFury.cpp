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
	printf(" ---O=D ");
	gotoxy(x, y+=1);
	printf(" /  v ");
}

void clearplane(int x, int y)
{
	/*gotoxy(x, y -= 1);
	printf("        ");*/
	gotoxy(x, y);
	printf("        ");
	gotoxy(x, y += 1);
	printf("        ");
	gotoxy(x, y += 1);
	printf("       ");
/*	gotoxy(x, y += 1);
	printf("       ");*/
}

void draw_bullet(int x, int y, int bulletStatus)
{
	int bx[6], by[6];
	bx[bulletStatus] = x;
	by[bulletStatus] = y;
	gotoxy(bx[bulletStatus], by[bulletStatus]);
	printf(" ->>");
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

void draw_enemy(int x, int y)
{
	gotoxy(x, y);
	printf("M");
}

void clear_enemy(int x, int y)
{
	gotoxy(x, y);
	printf(" ");
}

void map_generate()
{
	int i,j;
	for (i = 0; i <= 60; i++)
	{
		printf("*");
	}
	printf("\n");
	for (j = 0; j <= 20; j++)
	{
		for (i = 0; i <= 60; i++)
		{
			if (i == 0)
			{
				printf("*");
			}

			else if (i == 60)
			{
				printf("*\n");
			}
			else
			{
				printf(" ");
			}
		}
	}
	for (i = 0; i <= 60; i++)
	{
		printf("*");
	}


}

void playerhealth(int php)
{
	gotoxy(0, 23);
	setcolor(2, 0);
	printf("HP : %d", php);

	/*gotoxy(25, 10);
	printf("<");
	gotoxy(25, 15);
	printf("<");
	gotoxy(25, 18);
	printf("<");*/

}

void scoreupdate(int score)
{
	gotoxy(10, 23);
	printf("Score : %d", score);
}

int RandomX()
{
	int x;
	x = rand();
	if (x > 20 && x < 57)
	{
		return x;
	}
	else
	{
		RandomX();
	}
}

int RandomY()
{
	int y;
	y = rand();
	if (y > 1 && y < 19)
	{
		return y;
	}
	else
	{
		RandomY();
	}
}



int main()
{
	setcursor(0);
	srand(time(NULL));
	struct enemy
	{
		int status=0;
		int x=0;
		int y=0;
		int hp = 2;
	};enemy enemy[3];
	char ch = ' ';
	int x = 12, y = 10;
	int bulletx[5], bullety[5];
	int bulletStatus[5];
	int PlayerHP = 3, OldPlayerHP = 3 , score=0 , oldscore=0;
	for (int i = 0; i <= 4; i++)
	{
		bulletStatus[i] = 0;
	}
	map_generate();
	playerhealth(PlayerHP);
	scoreupdate(score);
	setcolor(7, 0);
	plane(x, y);
	do {
		setcolor(7, 0);
		if (_kbhit()) 
		{
			ch = _getch();
			if (ch == 'a' && cursor(x - 1, y) != '*') { plane(--x, y); }
			if (ch == 'd' && cursor(x + 8, y) != '*') { plane(++x, y); }
			if (ch == 'w' && cursor(x, y - 1) != '*') { clearplane(x, y);  plane(x, --y); }
			if (ch == 's' && cursor(x, y+3) != '*') { clearplane(x, y);  plane(x, ++y); }
			if (bulletStatus[0] == 0 && ch == ' ')
			{
				Beep(700, 50);
				bulletStatus[0] = 1;
				bulletx[0] = x + 7;
				bullety[0] = y + 1;
			}
			else if (bulletStatus[1] == 0 && ch == ' ')
			{
				Beep(700, 50);
				bulletStatus[1] = 1;
				bulletx[1] = x + 7;
				bullety[1] = y + 1;
			}
			else if (bulletStatus[2] == 0 && ch == ' ')
			{
				Beep(700, 50);
				bulletStatus[2] = 1;
				bulletx[2] = x + 7;
				bullety[2] = y + 1;
			}
			else if (bulletStatus[3] == 0 && ch == ' ')
			{
				Beep(700, 50);
				bulletStatus[3] = 1;
				bulletx[3] = x + 7;
				bullety[3] = y + 1;
			}
			else if (bulletStatus[4] == 0 && ch == ' ')
			{
				Beep(700, 50);
				bulletStatus[4] = 1;
				bulletx[4] = x + 7;
				bullety[4] = y + 1;
			}
			fflush(stdin);
		}

		if (enemy[0].status == 0)
		{
			enemy[0].x = RandomX();
			enemy[0].y = RandomY();
			draw_enemy(enemy[0].x, enemy[0].y);
			enemy[0].status = 1;
		}
		if (enemy[1].status == 0)
		{
			enemy[1].x = RandomX();
			enemy[1].y = RandomY();
			draw_enemy(enemy[1].x, enemy[1].y);
			enemy[1].status = 1;
		}


		if (enemy[0].status == 1)
		{
			clear_enemy(enemy[0].x, enemy[0].y);
			if (cursor(enemy[0].x - 2, enemy[0].y) == '>')
			{
				Beep(400, 50);
				clear_enemy(enemy[0].x, enemy[0].y);
				enemy[0].status = 0;
				//clear_bullet(enemy[0].x - 1, enemy[0].y);
			}
			else if (cursor(enemy[0].x - 2, enemy[0].y) == '*')
			{
				clear_enemy(enemy[0].x, enemy[0].y);
				enemy[0].status = 0;
			}
			else if (cursor(enemy[0].x - 2, enemy[0].y) == 'D')
			{
				clear_enemy(enemy[0].x, enemy[0].y);
				enemy[0].status = 0;
				PlayerHP -= 1;
			}
			else if (cursor(enemy[0].x - 2, enemy[0].y) == '^')
			{
				clear_enemy(enemy[0].x, enemy[0].y);
				enemy[0].status = 0;
				PlayerHP -= 1;
			}
			else if (cursor(enemy[0].x - 2, enemy[0].y) == 'v')
			{
				clear_enemy(enemy[0].x, enemy[0].y);
				enemy[0].status = 0;
				PlayerHP -= 1;
			}
			else 
			{
				draw_enemy(--enemy[0].x, enemy[0].y);
			}
			
		}

		if (enemy[1].status == 1)
		{
			clear_enemy(enemy[1].x, enemy[1].y);
			if (cursor(enemy[1].x - 2, enemy[1].y) == '>')
			{
				Beep(400, 50);
				clear_enemy(enemy[1].x, enemy[1].y);
				enemy[1].status = 0;
				//clear_bullet(enemy[0].x - 1, enemy[0].y);
			}
			else if (cursor(enemy[1].x - 2, enemy[1].y) == '*')
			{
				clear_enemy(enemy[1].x, enemy[1].y);
				enemy[1].status = 0;
			}
			else if (cursor(enemy[1].x - 2, enemy[1].y) == 'D')
			{
				clear_enemy(enemy[1].x, enemy[1].y);
				enemy[1].status = 0;
				PlayerHP -= 1;
			}
			else if (cursor(enemy[1].x - 2, enemy[1].y) == '^')
			{
				clear_enemy(enemy[1].x, enemy[1].y);
				enemy[1].status = 0;
				PlayerHP -= 1;
			}
			else if (cursor(enemy[1].x - 2, enemy[1].y) == 'v')
			{
				clear_enemy(enemy[1].x, enemy[1].y);
				enemy[1].status = 0;
				PlayerHP -= 1;
			}
			else
			{
				draw_enemy(--enemy[1].x, enemy[1].y);
			}

		}


		if (bulletStatus[0] == 1)
		{

			clear_bullet(bulletx[0], bullety[0], 0);
			if (bulletx[0] == 57)
			{
				bulletStatus[0] = 0;
			}
			else if (cursor(bulletx[0]+3, bullety[0]) == '*')
			{
				clear_bullet(bulletx[0], bullety[0], 0);
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
			if (bulletx[1] == 57)
			{
				bulletStatus[1] = 0;
			}
			else if (cursor(bulletx[1]+3, bullety[1] - 1) == '*')
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
			if (bulletx[2] == 57)
			{
				bulletStatus[2] = 0;
			}
			else if (cursor(bulletx[2]+3, bullety[2] - 1) == '*')
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
			if (bulletx[3] == 57)
			{
				bulletStatus[3] = 0;
			}
			else if (cursor(bulletx[3]+3, bullety[3] - 1) == '*')
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
			if (bulletx[4] == 57)
			{
				bulletStatus[4] = 0;
			}
			else if (cursor(bulletx[4]+3, bullety[4] - 1) == '*')
			{

				bulletStatus[4] = 0;
			}
			else
			{
				draw_bullet(++bulletx[4], bullety[4], 4);
			}
		}

		if (PlayerHP < OldPlayerHP)
		{
			playerhealth(PlayerHP);
			OldPlayerHP = PlayerHP;

		}

		if (score != oldscore)
		{
			scoreupdate(score);
			oldscore = score;
		}

		if (PlayerHP == 0)
		{
			bulletStatus[0] = 0;
			bulletStatus[1] = 0;
			bulletStatus[2] = 0;
			bulletStatus[3] = 0;
			bulletStatus[4] = 0;
			system("cls");
			//printf("You noob");
				
		}
		Sleep(100);
	} while (ch != 'x');
	printf("You noob");
	
	return 0;


}

