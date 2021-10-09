#define _CRT_SECURE_NO_WARNINGS 1
#include<stdio.h>
#include<windows.h>
#include<conio.h>
#include<time.h>
#include<string.h>

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

int PlayerStats(int pscore, int lv)
{
	FILE* fptr;
	struct player
	{
		char name[20];
		int lv;
		int score;
	}; player p[5];

	p[0].score = pscore;
	p[0].lv = lv;

	strcpy(p[1].name, "Nom Carver");
	p[1].lv = 2;
	p[1].score = 3200;

	strcpy(p[2].name, "CT-7567");
	p[2].lv = 99;
	p[2].score = 42069;

	strcpy(p[3].name, "James Bond");
	p[3].lv = 700;
	p[3].score = 777;

	strcpy(p[4].name, "Snoopy");
	p[4].lv = 5;
	p[4].score = 2000;

	int i = 0;
	setcolor(7, 0);
	fptr = fopen("PlayerStatsnew.txt", "w");

	//for (i = 0; i <= 4; i++)
	//{
		printf("Enter Player Name : ", i + 1); scanf("%s", p[i].name);
		//printf("Level : "); scanf("%d", &p[i].lv);
		//printf("Score : "); scanf("%d", &p[i].score);
		fwrite(&p, sizeof(struct player), 1, fptr);
	//}
	fclose(fptr);

	i = 0;
	printf("\n-------Score Summary-------\n");


	fptr = fopen("PlayerStatsnew.txt", "r");
	if (fptr == (FILE*)NULL)
		printf("Cannot open file\n");
	else
		for (i = 0; i <= 4; i++)
			//while (fread(&p,sizeof(struct player),5,fptr)!=0)
		{
			/*   for(i=0;i<=2;i++)
			   {*/
			printf("Player %d Name : %s\n", i + 1, p[i].name);
			printf("Level : %d\n", p[i].lv);
			printf("Score : %d\n", p[i].score);
			printf("---------------------------\n");
			// }
				//i++;
		}
	fclose(fptr);

	printf(" Thank you for playing !\n");
	return 0;
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
	printf("    ");
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
	gotoxy(23, 23);
	printf("Score : %d", score);
}

void levelupdate(int lv)
{
	gotoxy(10, 23);
	printf("Level : %d", lv);
}


int RandomX()
{
	long int x;
	x = rand();
	/*if (x > 20 && x < 57)
	{
		return x;
	}
	else
	{
		RandomX();
	}*/

	x = x % 58;
	if (x > 37)
	{
		return x;
	}
	else
	{
		x += 21;
		return x;
	}

	
	
}

int RandomY()
{
	long int y;
	y = rand();
	/*if (y > 1 && y < 19)
	{
		return y;
	}
	else
	{
		
	}*/
	y = y % 20;
	if (y == 19)
	{
		return y;
	}
	else
	{
		y += 1;
		return y;
	}
	
	

}

void healthpack()
{
	int x, y, drop;
	drop = rand() % 100;
	if (drop >= 80)
	{
		x = RandomX();
		y = RandomY();
		gotoxy(x, y);
		printf("+");
	}


}
void clearpack(int x ,int y)
{
	gotoxy(x, y);
	printf(" ");
}



int main()
{
	setcursor(0);
	srand(time(NULL));


	struct enemy
	{
		int status=0;
		long int x=0;
		long int y=0;
		int hp = 2;
	};enemy enemy[5];

	struct repair
	{
		int x = 0;
		int y = 0;
	}; repair rep[1];

	char ch = ' ';
	int x = 12, y = 10 , level = 1 , oldlevel = 1 , pack = 0;
	//char name[100];
	int bulletx[5] = { 0,0,0,0,0 }, bullety[5] = {0,0,0,0,0};
	int bulletStatus[5];
	int PlayerHP = 3, OldPlayerHP = 3 , score=0 , oldscore=0;
	for (int i = 0; i <= 4; i++)
	{
		bulletStatus[i] = 0;
	}
	map_generate();
	playerhealth(PlayerHP);
	setcolor(7, 0);
	scoreupdate(score);
	levelupdate(level);
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
		if (cursor(x + 8, y+1) == '+')
		{
			Beep(900, 50);
			clearpack(x + 8, y + 1);
			PlayerHP += 1;
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

		if (enemy[2].status == 0)
		{
			enemy[2].x = RandomX();
			enemy[2].y = RandomY();
			draw_enemy(enemy[2].x, enemy[2].y);
			enemy[2].status = 1;
		}


		if (enemy[0].status == 1)
		{
			clear_enemy(enemy[0].x, enemy[0].y);
			if (cursor(enemy[0].x - 2, enemy[0].y) == '>')
			{
				Beep(400, 50);
				healthpack();
				clear_enemy(enemy[0].x, enemy[0].y);
				enemy[0].status = 0;
				score += 100;
			}
			else if (cursor(enemy[0].x - 2, enemy[0].y) == '*')
			{
				clear_enemy(enemy[0].x, enemy[0].y);
				enemy[0].status = 0;
			}
			else if (cursor(enemy[0].x - 2, enemy[0].y) == 'D' || cursor(enemy[0].x - 2, enemy[0].y) == '=')
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
				healthpack();
				clear_enemy(enemy[1].x, enemy[1].y);
				enemy[1].status = 0;
				score += 100;
			}
			else if (cursor(enemy[1].x - 2, enemy[1].y) == '*')
			{
				clear_enemy(enemy[1].x, enemy[1].y);
				enemy[1].status = 0;
			}
			else if (cursor(enemy[1].x - 2, enemy[1].y) == 'D' || cursor(enemy[0].x - 2, enemy[0].y) == '=')
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

		if (enemy[2].status == 1)
		{
			clear_enemy(enemy[2].x, enemy[2].y);
			if (cursor(enemy[2].x - 2, enemy[2].y) == '>')
			{
				Beep(400, 50);
				healthpack();
				clear_enemy(enemy[2].x, enemy[2].y);
				enemy[2].status = 0;
				score += 100;
			}
			else if (cursor(enemy[2].x - 2, enemy[2].y) == '*')
			{
				clear_enemy(enemy[2].x, enemy[2].y);
				enemy[2].status = 0;
			}
			else if (cursor(enemy[2].x - 2, enemy[2].y) == 'D' || cursor(enemy[2].x - 2, enemy[2].y) == '=')
			{
				clear_enemy(enemy[2].x, enemy[2].y);
				enemy[2].status = 0;
				PlayerHP -= 1;
			}
			else if (cursor(enemy[2].x - 2, enemy[2].y) == '^')
			{
				clear_enemy(enemy[2].x, enemy[2].y);
				enemy[2].status = 0;
				PlayerHP -= 1;
			}
			else if (cursor(enemy[2].x - 2, enemy[2].y) == 'v')
			{
				clear_enemy(enemy[2].x, enemy[2].y);
				enemy[2].status = 0;
				PlayerHP -= 1;
			}
			else
			{
				draw_enemy(--enemy[2].x, enemy[2].y);
			}

		}


		if (bulletStatus[0] == 1)
		{

			clear_bullet(bulletx[0], bullety[0], 0);
			if (bulletx[0] == 56)
			{
				bulletStatus[0] = 0;
			}
		/*	else if (cursor(bulletx[0] + 5, bullety[0]) == 'M')
			{
				clear_bullet(bulletx[0], bullety[0], 0);
				bulletStatus[0] = 0;

			}*/
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
			if (bulletx[1] == 56)
			{
				bulletStatus[1] = 0;
			}
			else if (cursor(bulletx[1] + 3, bullety[1] - 1) == '*')
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
			if (bulletx[2] == 56)
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
			if (bulletx[3] == 56)
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
			if (bulletx[4] == 56)
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

		if (PlayerHP != OldPlayerHP)
		{
			playerhealth(PlayerHP);
			OldPlayerHP = PlayerHP;

		}

		if (score != oldscore)
		{
			scoreupdate(score);
			oldscore = score;
			if (score % 1000 == 0)
			{
				level += 1;
			}
			
		}

		if (level != oldlevel)
		{
			levelupdate(level);
			oldlevel = level;

		}
		

		if (PlayerHP <= 0)
		{
			break;
		}
		Sleep(100);
	} while (ch != 'x');
	system("cls");
	PlayerStats(score , level);
	
	return 0;


}

