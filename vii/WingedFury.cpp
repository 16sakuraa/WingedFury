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

	/*p[0].score = pscore;
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
	p[4].score = 2000;*/
	
	int i = 0;
	fptr = fopen("PlayerStatsnew.txt", "w");

	//for (i = 0; i <= 4; i++)
	//{
		printf("\nEnter Player Name : ", i + 1); scanf("%s", p[i].name);
		p[0].score = pscore;
		p[0].lv = lv;
		//printf("Level : "); scanf("%d", &p[i].lv);
		//printf("Score : "); scanf("%d", &p[i].score);
		strcpy(p[1].name, "Nom Carver");
		p[1].lv = 2;
		p[1].score = 3200;

		strcpy(p[2].name, "CT-7567");
		p[2].lv = 69;
		p[2].score = 69420;

		strcpy(p[3].name, "James Bond");
		p[3].lv = 700;
		p[3].score = 77777;

		strcpy(p[4].name, "Snoopy");
		p[4].lv = 5;
		p[4].score = 5300;
		fwrite(&p, sizeof(struct player), 5, fptr);
	//}
	fclose(fptr);

	i = 0;
	setcolor(14, 0);
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
	setcolor(11, 0);
	printf(" Thank you for playing my game!\n");
	setcolor(7, 0);
	return 0;
}

void plane(int x,int y)
{
	setcolor(3, 0);
	gotoxy(x, y);
	printf(" \\  ^ ");
	gotoxy(x, y+=1);
	printf(" =>=O=D ");
	gotoxy(x, y+=1);
	printf(" /  v ");
	setcolor(7, 0);
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
	setcolor(14, 0);
	gotoxy(bx[bulletStatus], by[bulletStatus]);
	printf(" >>");
	setcolor(7, 0);
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
	setcolor(12, 0);
	gotoxy(x, y);
	printf("M");
	setcolor(7, 0);
}

void draw_w(int x, int y)
{
	setcolor(4, 0);
	gotoxy(x, y);
	printf("W");
	setcolor(7, 0);
}

void wbullet(int x, int y)
{
	gotoxy(x, y);
	printf("-");
}



void clear_enemy(int x, int y)
{
	gotoxy(x, y);
	printf(" ");
}

void map_generate()
{
	int i,j;
	setcolor(9,0);
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

	setcolor(7, 0);


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
	setcolor(10, 0);
	gotoxy(23, 23);
	printf("Score : %d", score);
	setcolor(7, 0);
}

void levelupdate(int lv)
{
	setcolor(13, 0);
	gotoxy(10, 23);
	printf("Level : %d", lv);
	setcolor(7, 0);
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
	if (x > 32)
	{
		return x;
	}
	else
	{
		x += 25;
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
		y += 2;
		return y;
	}
	
	

}

void healthpack()
{
	int x, y, drop;
	drop = rand() % 100;
	if (drop >= 90)
	{
		x = RandomX();
		y = RandomY();
		setcolor(10, 0);
		gotoxy(x, y);
		printf("+");
		setcolor(7, 0);
	}


}
void clearpack(int x ,int y)
{
	gotoxy(x, y);
	printf(" ");
}

void seescore()
{
	struct player
	{
		char name[20];
		int lv;
		int score;
	}; player p[5];

	char ch = ' ';
	FILE* fptr;

	int i = 0;
	printf("\n-------Score Summary-------\n");


	fptr = fopen("PlayerStatsnew.txt", "r");
	if (fptr == (FILE*)NULL)
		printf("Cannot open file\n");
	else
	
		while (fread(&p,sizeof(struct player),5,fptr)!=0)
		{

			printf("Player %d Name : %s\n", i + 1, p[i].name);
			printf("Level : %d\n", p[i].lv);
			printf("Score : %d\n", p[i].score);
			printf("---------------------------\n");
			
				i++;
		}
	fclose(fptr);

	while (1)
	{
		gotoxy(40, 10);
		printf("> Back");
		if (_kbhit())
		{
			ch = _getch();
			if (ch == ' ')
			{
				system("cls");
				break;
			}

		}
	}
}

void title()
{
	int a = 200;
	setcolor(3, 0);
	printf("         .----.                                                  .\'.\n");
	Sleep(a);
	printf("        |  /   \'                                                 |  \'\n");
	Sleep(a);
	printf("        |  |    \'                                                \'  :\n");
	Sleep(a);
	printf("        |010860  \'             .-~~~-.               .-~-.        \\ |\n");
	Sleep(a);
	printf("        |  |      \'          .\\\\   .//\'._+_________.\'.\'  /_________\\|\n");
	Sleep(a);
	printf("        |  |___ ...\'.__..--~~ .\\\\__//_.-     . . .\' .\'  /      :  |  `.\n");
	Sleep(a);
	printf("        |.-\"  .\'  /                          . .\' .\'   /.      :_.|__.\'\n");
	Sleep(a);
	printf("       <    .\'___/                           .\' .\'    /|.      : .\'|\\\n");
	Sleep(a);
	printf("        ~~--..                             .\' .\'     /_|.      : | | \\\n");
	Sleep(a);
	printf("          /_.\' ~~--..__             .----.\'_.\'      /. . . . . . | |  |\n");
	Sleep(a);
	printf("                      ~~--.._______\'.__.\'  .\'      /____________.\' :  /\n");
	Sleep(a);
	printf("                               .\'   .\'\'.._\'______.\'                \'-\'\n");
	Sleep(a);
	printf("                               \'---\'\n");
	Sleep(600);
	setcolor(6, 0);
	printf("   __      __.__                          .___ ___________                   \n");
	printf("  /  \\    /  \\__| ____    ____   ____   __| _/ \\_   _____/_ _________ ___.__.\n");
	printf("  \\   \\/\\/   /  |/    \\  / ___\\_/ __ \\ / __ |   |    __)|  |  \\_  __ <   |  |\n");
	printf("   \\        /|  |   |  \\/ /_/  >  ___// /_/ |   |     \\ |  |  /|  | \\/\\___  |\n");
	printf("    \\__/\\  / |__|___|  /\\___  / \\___  >____ |   \\___  / |____/ |__|   / ____|\n");
	printf("         \\/          \\//_____/      \\/     \\/       \\/                \\/     ");
	setcolor(7, 0);
}

void menu()
{
	char ch = ' ';
	int play = 1;
	title();
	Sleep(500);
	gotoxy(15,20);
	printf("> ");

	while (1)
	{
		gotoxy(17, 20);
		printf("Play");
		gotoxy(17, 21);
		printf("Score");
		//gotoxy(10, 12);
		if (_kbhit())
		{
			ch = _getch();
			if (ch == 'w' && play != 1)
			{
				Beep(900, 50);
				Beep(700, 50);
				gotoxy(15, 21);
				printf("  ");
				gotoxy(15, 20);
				printf(">");
				play = 1;
			}
			else if (ch == 's' && play == 1)
			{
				Beep(900, 50);
				Beep(700, 50);
				gotoxy(15, 20);
				printf("  ");
				gotoxy(15, 21);
				printf(">");
				play = 0;
			}
			else if (ch == ' ' && play == 1)
			{
				system("cls");
				break;

			}
			else if (ch == ' ' && play == 0)
			{
				system("cls");
				seescore();
				title();


			}

		}
	}
}

void gameover()
{
	int a = 200;
	setcolor(3, 0);
	printf("  _______      ___      .___  ___.  _______      ______   ____    ____  _______ .______      \n");
	Sleep(a);
	printf(" /  _____|    /   \\     |   \\/   | |   ____|    /  __  \\  \\   \\  /   / |   ____||   _  \\     \n");
	Sleep(a);
	printf("|  |  __     /  ^  \\    |  \\  /  | |  |__      |  |  |  |  \\   \\/   /  |  |__   |  |_)  |    \n");
	Sleep(a);
	printf("|  | |_ |   /  /_\\  \\   |  |\\/|  | |   __|     |  |  |  |   \\      /   |   __|  |      /     \n");
	Sleep(a);
	printf("|  |__| |  /  _____  \\  |  |  |  | |  |____    |  `--\'  |    \\    /    |  |____ |  |\\  \\----.\n");
	Sleep(a);
	printf(" \\______| /__/     \\__\\ |__|  |__| |_______|    \\______/      \\__/     |_______|| _| `._____|\n     ");
	Sleep(500);
	setcolor(7, 0);
}

void squid()
{
	setcolor(4, 0);
	gotoxy(35, 5);
	printf("                        _,--._\n");
	gotoxy(35, 6);
	printf("                      ,\'      `.\n");
	gotoxy(35, 7);
	printf("              |\\     / ,-.  ,-. \\     /|\n");
	gotoxy(35, 8);
	printf("              )o),/ ( ( o )( o ) ) \\.(o(\n");
	gotoxy(35, 9);
	printf("             /o/// /|  `-\'  `-\'  |\\ \\\\\\o\\\n");
	gotoxy(35, 10);
	printf("            / / |\\ \\(   .    ,   )/ /| \\ \\\n");
	gotoxy(35, 11);
	printf("            | | \\o`-/    `\\/\'    \\-\'o/ | |\n");
	gotoxy(35, 12);
	printf("            \\ \\  `,\'              `.\'  / /\n");
	gotoxy(35, 13);
	printf("         \\.  \\ `-\'  ,\'|   /\\   |`.  `-\' /  ,/\n");
	gotoxy(35, 14);
	printf("          \\`. `.__,\' /   /  \\   \\ `.__,\' ,\'/\n");
	gotoxy(35, 15);
	printf("           \\o\\     ,\'  ,\'    `.  `.     /o/\n");
	gotoxy(35, 16);
	printf("            \\o`---\'  ,\'        `.  `---\'o/\n");
	gotoxy(35, 17);
	printf("             `.____,\'            `.____,\'\n");
	setcolor(7, 0);
}

void delsquid()
{
	gotoxy(35, 5);
	printf("                                  ");
	gotoxy(35, 6);
	printf("                                   ");
	gotoxy(35, 7);
	printf("                                            ");
	gotoxy(35, 8);
	printf("                                           ");
	gotoxy(35, 9);
	printf("													");
	gotoxy(35, 10);
	printf("												");
	gotoxy(35, 11);
	printf("													");
	gotoxy(35, 12);
	printf("												");
	gotoxy(35, 13);
	printf("														");
	gotoxy(35, 14);
	printf("													");
	gotoxy(35, 15);
	printf("												");
	gotoxy(35, 16);
	printf("													");
	gotoxy(35, 17);
	printf("												");
}

void bosshpupdate(int hp)
{
	gotoxy(38, 23);
	printf("Boss HP : %d", hp);
}

void delay(int ms)
{
	clock_t timeDelay = ms + clock();
	while (timeDelay > clock());
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
	};enemy enemy[10];

	struct wmy
	{
		int status = 0;
		int x = 0;
		int y = 0;
		int hp = 2;
		int walk = 0;
	}; wmy wmy[5];

	struct wb
	{
		int status = 0;
		int x = 0;
		int y = 0;
		//int hp = 2;
	}; wb wb[5];

	char ch = ' ';
	int x = 12, y = 10 , level = 1 , oldlevel = 1 , pack = 0;
	int bosshp = 30, oldbosshp = 30 , bossstate = 1;
	int bulletx[5] = { 0,0,0,0,0 }, bullety[5] = {0,0,0,0,0};
	int bulletStatus[5];
	int PlayerHP = 3, OldPlayerHP = 3 , score=0 , oldscore=0;
	//int walk = 0;
	for (int i = 0; i <= 4; i++)
	{
		bulletStatus[i] = 0;
	}
	menu();
	map_generate();
	playerhealth(PlayerHP);
	setcolor(7, 0);
	scoreupdate(score);
	levelupdate(level);
	//squid();
	//bosshpupdate(bosshp);
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
			if (PlayerHP < 5)
			{
				Beep(800, 25);
				Beep(650, 25);
				clearpack(x + 8, y + 1);
				PlayerHP += 1;
			}
			else
			{
				clearpack(x + 8, y + 1);
			}
			
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

		if (enemy[3].status == 0 && level >= 2)
		{
			enemy[3].x = RandomX();
			enemy[3].y = RandomY();
			draw_enemy(enemy[3].x, enemy[3].y);
			enemy[3].status = 1;
		}

		if (enemy[4].status == 0 && level >= 3)
		{
			enemy[4].x = RandomX();
			enemy[4].y = RandomY();
			draw_enemy(enemy[4].x, enemy[4].y);
			enemy[4].status = 1;
		}

		if (enemy[5].status == 0 && level >= 4)
		{
			enemy[5].x = RandomX();
			enemy[5].y = RandomY();
			draw_enemy(enemy[5].x, enemy[5].y);
			enemy[5].status = 1;
		}

		if (enemy[6].status == 0 && level >= 5)
		{
			enemy[6].x = RandomX();
			enemy[6].y = RandomY();
			draw_enemy(enemy[6].x, enemy[6].y);
			enemy[6].status = 1;
		}

		if (wmy[0].status == 0 && level >= 3)
		{
			wmy[0].x = RandomX();
			wmy[0].y = 19;
			draw_w(wmy[0].x, wmy[0].y);
			wmy[0].status = 1;

		}

		if (wmy[0].status == 1)
		{
			wmy[0].walk += 1;
			if (wmy[0].walk % 4 == 0)
			{
				clear_enemy(wmy[0].x, wmy[0].y);
				if (cursor(wmy[0].x, wmy[0].y - 2) == '*')
				{
					clear_enemy(wmy[0].x, wmy[0].y);
					wmy[0].status = 0;
				}
				else if (cursor(wmy[0].x, wmy[0].y - 1) == '>' || cursor(wmy[0].x, wmy[0].y - 1) == '-' || cursor(wmy[0].x+1, wmy[0].y) == '>' )
				{
					Beep(480, 50);
					clear_enemy(wmy[0].x, wmy[0].y);
					wmy[0].status = 0;
					score += 200;
				}
				else if (wmy[0].y == y + 1 && wb[0].status == 0)
				{
					wb[0].x = wmy[0].x - 1;
					wb[0].y = wmy[0].y;
					wb[0].status = 1;
					draw_w(wmy[0].x, --wmy[0].y);
				}
				else
				{
					draw_w(wmy[0].x, --wmy[0].y);
				}


			}
			
			
		}

		if (wb[0].status == 1)
		{
			clear_enemy(wb[0].x, wb[0].y);
			if (wb[0].x == 2)
			{
				clear_enemy(wb[0].x, wb[0].y);
				wb[0].status = 0;
			}
			else if (cursor(wb[0].x - 1, wb[0].y) == 'D' || cursor(wb[0].x - 1, wb[0].y) == '^' || cursor(wb[0].x - 1, wb[0].y) == 'v')
			{
				clear_enemy(wb[0].x, wb[0].y);
				PlayerHP -= 1;
				wb[0].status = 0;
			}
			else
			{
				wbullet(--wb[0].x, wb[0].y);
			}

		}

		if (wmy[1].status == 0 && level >= 4)
		{
			wmy[1].x = RandomX();
			wmy[1].y = 1;
			draw_w(wmy[1].x, wmy[1].y);
			wmy[1].status = 1;

		}

		if (wmy[1].status == 1)
		{
			wmy[1].walk += 1;
			if (wmy[1].walk % 4 == 0)
			{
				clear_enemy(wmy[1].x, wmy[1].y);
				if (cursor(wmy[1].x, wmy[1].y + 1) == '*')
				{
					clear_enemy(wmy[1].x, wmy[1].y);
					wmy[1].status = 0;
				}
				else if (cursor(wmy[1].x, wmy[1].y - 1) == '>' || cursor(wmy[1].x, wmy[1].y - 1) == '-' || cursor(wmy[1].x + 1, wmy[1].y) == '>')
				{
					Beep(480, 50);
					clear_enemy(wmy[1].x, wmy[1].y);
					wmy[1].status = 0;
					score += 200;
				}
				else if (wmy[1].y == y + 1 && wb[1].status == 0)
				{

					wb[1].x = wmy[1].x - 1;
					wb[1].y = wmy[1].y;
					wb[1].status = 1;
					draw_w(wmy[1].x, ++wmy[1].y);
				}
				else
				{
					draw_w(wmy[1].x, ++wmy[1].y);
				}


			}


		}

		if (wb[1].status == 1)
		{
			clear_enemy(wb[1].x, wb[1].y);
			if (wb[1].x == 2)
			{
				clear_enemy(wb[1].x, wb[1].y);
				wb[1].status = 0;
			}
			else if (cursor(wb[1].x - 1, wb[1].y) == 'D' || cursor(wb[1].x - 1, wb[1].y) == '^' || cursor(wb[1].x - 1, wb[1].y) == 'v')
			{
				clear_enemy(wb[1].x, wb[1].y);
				PlayerHP -= 1;
				wb[1].status = 0;
			}
			else
			{
				wbullet(--wb[1].x, wb[1].y);
			}

		}

		if (wmy[2].status == 0 && level >= 5)
		{
			wmy[2].x = RandomX();
			wmy[2].y = 19;
			draw_w(wmy[2].x, wmy[2].y);
			wmy[2].status = 1;

		}

		if (wmy[2].status == 1)
		{
			wmy[2].walk += 1;
			if (wmy[2].walk % 4 == 0)
			{
				clear_enemy(wmy[2].x, wmy[2].y);
				if (cursor(wmy[2].x, wmy[2].y - 2) == '*')
				{
					clear_enemy(wmy[2].x, wmy[2].y);
					wmy[2].status = 0;
				}
				else if (cursor(wmy[2].x, wmy[2].y - 1) == '>' || cursor(wmy[2].x, wmy[2].y - 1) == '-' || cursor(wmy[2].x + 1, wmy[2].y) == '>')
				{
					Beep(480, 50);
					clear_enemy(wmy[2].x, wmy[2].y);
					wmy[2].status = 0;
					score += 200;
				}
				else if (wmy[2].y == y + 1 && wb[2].status == 0)
				{
					wb[2].x = wmy[2].x - 1;
					wb[2].y = wmy[2].y;
					wb[2].status = 1;
					draw_w(wmy[2].x, --wmy[2].y);
				}
				else
				{
					draw_w(wmy[2].x, --wmy[2].y);
				}


			}


		}

		if (wb[2].status == 1)
		{
			clear_enemy(wb[2].x, wb[2].y);
			if (wb[2].x == 2)
			{
				clear_enemy(wb[2].x, wb[2].y);
				wb[2].status = 0;
			}
			else if (cursor(wb[2].x - 1, wb[2].y) == 'D' || cursor(wb[2].x - 1, wb[2].y) == '^' || cursor(wb[2].x - 1, wb[2].y) == 'v')
			{
				clear_enemy(wb[2].x, wb[2].y);
				PlayerHP -= 1;
				wb[2].status = 0;
			}
			else
			{
				wbullet(--wb[2].x, wb[2].y);
			}

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
			else if (cursor(enemy[0].x - 2, enemy[0].y) == '^' || cursor(enemy[0].x - 2, enemy[0].y) == '\\' || cursor(enemy[0].x - 2, enemy[0].y) == '/')
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
			else if (cursor(enemy[1].x - 2, enemy[1].y) == 'D' || cursor(enemy[1].x - 2, enemy[1].y) == '=')
			{
				clear_enemy(enemy[1].x, enemy[1].y);
				enemy[1].status = 0;
				PlayerHP -= 1;
			}
			else if (cursor(enemy[1].x - 2, enemy[1].y) == '^' || cursor(enemy[1].x - 2, enemy[1].y) == '\\' || cursor(enemy[1].x - 2, enemy[1].y) == '/')
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
			else if (cursor(enemy[2].x - 2, enemy[2].y) == '^' || cursor(enemy[2].x - 2, enemy[2].y) == '\\' || cursor(enemy[2].x - 2, enemy[2].y) == '/')
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

		if (enemy[3].status == 1)
		{
			clear_enemy(enemy[3].x, enemy[3].y);
			if (cursor(enemy[3].x - 2, enemy[3].y) == '>')
			{
				Beep(400, 50);
				healthpack();
				clear_enemy(enemy[3].x, enemy[3].y);
				enemy[3].status = 0;
				score += 100;
			}
			else if (cursor(enemy[3].x - 2, enemy[3].y) == '*')
			{
				clear_enemy(enemy[3].x, enemy[3].y);
				enemy[3].status = 0;
			}
			else if (cursor(enemy[3].x - 2, enemy[3].y) == 'D' || cursor(enemy[3].x - 2, enemy[3].y) == '=')
			{
				clear_enemy(enemy[3].x, enemy[3].y);
				enemy[3].status = 0;
				PlayerHP -= 1;
			}
			else if (cursor(enemy[3].x - 2, enemy[3].y) == '^' || cursor(enemy[3].x - 2, enemy[3].y) == '\\' || cursor(enemy[3].x - 2, enemy[3].y) == '/')
			{
				clear_enemy(enemy[3].x, enemy[3].y);
				enemy[3].status = 0;
				PlayerHP -= 1;
			}
			else if (cursor(enemy[3].x - 2, enemy[3].y) == 'v')
			{
				clear_enemy(enemy[3].x, enemy[3].y);
				enemy[3].status = 0;
				PlayerHP -= 1;
			}
			else
			{
				draw_enemy(--enemy[3].x, enemy[3].y);
			}

		}

		if (enemy[4].status == 1)
		{
			clear_enemy(enemy[4].x, enemy[4].y);
			if (cursor(enemy[4].x - 2, enemy[4].y) == '>')
			{
				Beep(400, 50);
				healthpack();
				clear_enemy(enemy[4].x, enemy[4].y);
				enemy[4].status = 0;
				score += 100;
			}
			else if (cursor(enemy[4].x - 2, enemy[4].y) == '*')
			{
				clear_enemy(enemy[4].x, enemy[4].y);
				enemy[4].status = 0;
			}
			else if (cursor(enemy[4].x - 2, enemy[4].y) == 'D' || cursor(enemy[4].x - 2, enemy[4].y) == '=')
			{
				clear_enemy(enemy[4].x, enemy[4].y);
				enemy[4].status = 0;
				PlayerHP -= 1;
			}
			else if (cursor(enemy[4].x - 2, enemy[4].y) == '^' || cursor(enemy[4].x - 2, enemy[4].y) == '\\' || cursor(enemy[4].x - 2, enemy[4].y) == '/')
			{
				clear_enemy(enemy[4].x, enemy[4].y);
				enemy[4].status = 0;
				PlayerHP -= 1;
			}
			else if (cursor(enemy[4].x - 2, enemy[4].y) == 'v')
			{
				clear_enemy(enemy[4].x, enemy[4].y);
				enemy[4].status = 0;
				PlayerHP -= 1;
			}
			else
			{
				draw_enemy(--enemy[4].x, enemy[4].y);
			}

		}

		if (enemy[5].status == 1)
		{
			clear_enemy(enemy[5].x, enemy[5].y);
			if (cursor(enemy[5].x - 2, enemy[5].y) == '>')
			{
				Beep(400, 50);
				healthpack();
				clear_enemy(enemy[5].x, enemy[5].y);
				enemy[5].status = 0;
				score += 100;
			}
			else if (cursor(enemy[5].x - 2, enemy[5].y) == '*')
			{
				clear_enemy(enemy[5].x, enemy[5].y);
				enemy[5].status = 0;
			}
			else if (cursor(enemy[5].x - 2, enemy[5].y) == 'D' || cursor(enemy[5].x - 2, enemy[5].y) == '=')
			{
				clear_enemy(enemy[5].x, enemy[5].y);
				enemy[5].status = 0;
				PlayerHP -= 1;
			}
			else if (cursor(enemy[5].x - 2, enemy[5].y) == '^' || cursor(enemy[5].x - 2, enemy[5].y) == '\\' || cursor(enemy[5].x - 2, enemy[5].y) == '/')
			{
				clear_enemy(enemy[5].x, enemy[5].y);
				enemy[5].status = 0;
				PlayerHP -= 1;
			}
			else if (cursor(enemy[5].x - 2, enemy[5].y) == 'v')
			{
				clear_enemy(enemy[5].x, enemy[5].y);
				enemy[5].status = 0;
				PlayerHP -= 1;
			}
			else
			{
				draw_enemy(--enemy[5].x, enemy[5].y);
			}

		}

		if (enemy[6].status == 1)
		{
			clear_enemy(enemy[6].x, enemy[6].y);
			if (cursor(enemy[6].x - 2, enemy[6].y) == '>')
			{
				Beep(400, 50);
				healthpack();
				clear_enemy(enemy[6].x, enemy[6].y);
				enemy[6].status = 0;
				score += 100;
			}
			else if (cursor(enemy[6].x - 2, enemy[6].y) == '*')
			{
				clear_enemy(enemy[6].x, enemy[6].y);
				enemy[6].status = 0;
			}
			else if (cursor(enemy[6].x - 2, enemy[6].y) == 'D' || cursor(enemy[6].x - 2, enemy[6].y) == '=')
			{
				clear_enemy(enemy[6].x, enemy[6].y);
				enemy[6].status = 0;
				PlayerHP -= 1;
			}
			else if (cursor(enemy[6].x - 2, enemy[6].y) == '^' || cursor(enemy[6].x - 2, enemy[6].y) == '\\' || cursor(enemy[6].x - 2, enemy[6].y) == '/')
			{
				clear_enemy(enemy[6].x, enemy[6].y);
				enemy[6].status = 0;
				PlayerHP -= 1;
			}
			else if (cursor(enemy[6].x - 2, enemy[6].y) == 'v')
			{
				clear_enemy(enemy[6].x, enemy[6].y);
				enemy[6].status = 0;
				PlayerHP -= 1;
			}
			else
			{
				draw_enemy(--enemy[6].x, enemy[6].y);
			}

		}


		if (bulletStatus[0] == 1)
		{

			clear_bullet(bulletx[0], bullety[0], 0);
			if (bulletx[0] == 56)
			{
				bulletStatus[0] = 0;
			}
			else if (cursor(bulletx[0] + 4, bullety[0]) == '\\' || cursor(bulletx[0] + 4, bullety[0]) == '|' || cursor(bulletx[0] + 4, bullety[0]) == '/' || cursor(bulletx[0] + 4, bullety[0]) == ')' || cursor(bulletx[0] + 4, bullety[0]) == ',' || cursor(bulletx[0] + 4, bullety[0]) == '_')
			{
				clear_bullet(bulletx[0], bullety[0], 0);
				bulletStatus[0] = 0;
				bosshp -= 1;

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
			if (bulletx[1] == 56)
			{
				bulletStatus[1] = 0;
			}
			else if (cursor(bulletx[1] + 4, bullety[1]) == '\\' || cursor(bulletx[1] + 4, bullety[1]) == '|' || cursor(bulletx[1] + 4, bullety[1]) == '/' || cursor(bulletx[1] + 4, bullety[1]) == ')' || cursor(bulletx[1] + 4, bullety[1]) == ',' || cursor(bulletx[1] + 4, bullety[1]) == '_')
			{
				clear_bullet(bulletx[1], bullety[1], 1);
				bulletStatus[1] = 0;
				bosshp -= 1;

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
			else if (cursor(bulletx[2] + 4, bullety[2]) == '\\' || cursor(bulletx[2] + 4, bullety[2]) == '|' || cursor(bulletx[2] + 4, bullety[2]) == '/' || cursor(bulletx[2] + 4, bullety[2]) == ')' || cursor(bulletx[2] + 4, bullety[2]) == ',' || cursor(bulletx[2] + 4, bullety[2]) == '_')
			{
				clear_bullet(bulletx[2], bullety[2], 1);
				bulletStatus[2] = 0;
				bosshp -= 1;

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
			else if (cursor(bulletx[3] + 4, bullety[3]) == '\\' || cursor(bulletx[3] + 4, bullety[3]) == '|' || cursor(bulletx[3] + 4, bullety[3]) == '/' || cursor(bulletx[3] + 4, bullety[3]) == ')' || cursor(bulletx[3] + 4, bullety[3]) == ',' || cursor(bulletx[3] + 4, bullety[3]) == '_')
			{
				clear_bullet(bulletx[3], bullety[3], 1);
				bulletStatus[3] = 0;
				bosshp -= 1;

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
			else if (cursor(bulletx[4] + 4, bullety[4]) == '\\' || cursor(bulletx[4] + 4, bullety[4]) == '|' || cursor(bulletx[4] + 4, bullety[4]) == '/' || cursor(bulletx[4] + 4, bullety[4]) == ')' || cursor(bulletx[4] + 4, bullety[4]) == ',' || cursor(bulletx[4] + 4, bullety[4]) == '_')
			{
				clear_bullet(bulletx[4], bullety[4], 1);
				bulletStatus[4] = 0;
				bosshp -= 1;

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
				bossstate = 1;
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

		/*if (level == 2 && bossstate == 1)
		{
			squid();
			bossstate = 0;
		}

		if (bosshp != oldbosshp)
		{
			bosshpupdate(bosshp);
			oldbosshp = bosshp;
		}

		if (bosshp <= 0)
		{
			delsquid();
			//score += 500;
			bosshp = 50;
		
		}*/

		Sleep(100);
	} while (ch != 'x');
	system("cls");
	gameover();
	PlayerStats(score , level);
	
	return 0;


}

