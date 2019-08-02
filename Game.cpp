#include "Game.h"
string frame_le = "  ";
string frame_hen = "                                                                    ";
string Lv[5] = {
	"★☆☆☆☆",
	"★★☆☆☆",
	"★★★☆☆",
	"★★★★☆",
	"★★★★★"
};

char choice;//记录按键
int choice_y = FRAME_Y + 3;//记录当前主选项
int choice_p = FRAME_Y + 7;//记录当前皮肤
int lv = 2;//记录当前等级
int Time;
int mark[3] = { 0, 0, 0 };//记录分数
int times[3] = { 0, 0, 0 };//记录耗时

void frame()
{
	SetColor(3, 3);
	printByxy(FRAME_X - 1, FRAME_Y, frame_hen);

	for (int i = 1; i <= FRAME_L / 2; i++)
	{
		printByxy(FRAME_X - 1, i + FRAME_Y, frame_le);
		printByxy(FRAME_X + FRAME_L, i + FRAME_Y, frame_le);
	}
	printByxy(FRAME_X - 1, FRAME_Y + FRAME_L / 2 + 1, frame_hen);
	SetColor(7, 0);
}


int getLv()
{
	return lv;
}

int getPf()
{
	return choice_p - FRAME_Y - 6;
}

void showChoice()
{
	SetColor(4, 11);
	switch (choice_y)
	{
	case FRAME_Y + 3:
		printByxy(FRAME_X + FRAME_L + 4, FRAME_Y + 3, "*新的开始*");
		break;
	case FRAME_Y + 5:
		printByxy(FRAME_X + FRAME_L + 4, FRAME_Y + 5, "*大天梯榜*");
		break;
	case FRAME_Y + 7:
		printByxy(FRAME_X + FRAME_L + 4, FRAME_Y + 7, "*游戏设置*");
		break;
	}
	SetColor(7, 0);
}

void showHellochoice()
{
	while (1)
	{
		printByxy(FRAME_X + FRAME_L + 4, FRAME_Y + 3, "*新的开始*");
		printByxy(FRAME_X + FRAME_L + 4, FRAME_Y + 5, "*大天梯榜*");
		printByxy(FRAME_X + FRAME_L + 4, FRAME_Y + 7, "*游戏设置*");
		showChoice();
		choice = _getch();
		if (choice == 13)//回车
			break;
		else if (choice == 72)//上
		{
			if (choice_y == FRAME_Y + 3)
				choice_y = FRAME_Y + 7;
			else
				choice_y -= 2;
		}
		else if (choice == 80)//下
		{
			if (choice_y == FRAME_Y + 7)
				choice_y = FRAME_Y + 3;
			else
				choice_y += 2;
		}
	}
}

void hello()
{
	Clear(FRAME_X + FRAME_L + 2, FRAME_Y, FRAME_L / 2 + 1, 20);
	int x = 16, y = 3;
	printByxy(FRAME_X + x, FRAME_Y + y + 0, "   ┌─┐       ┌─┐");
	printByxy(FRAME_X + x, FRAME_Y + y + 1, "┌──┘ ┴───────┘ ┴──┐");
	printByxy(FRAME_X + x, FRAME_Y + y + 2, "│                 │");
	printByxy(FRAME_X + x, FRAME_Y + y + 3, "│       ───       │");
	printByxy(FRAME_X + x, FRAME_Y + y + 4, "│  ─┬┘       └┬─  │");
	printByxy(FRAME_X + x, FRAME_Y + y + 5, "│                 │");
	printByxy(FRAME_X + x, FRAME_Y + y + 6, "│       ─┴─       │");
	printByxy(FRAME_X + x, FRAME_Y + y + 7, "│                 │");
	printByxy(FRAME_X + x, FRAME_Y + y + 8, "└───┐         ┌───┘");
	printByxy(FRAME_X + x, FRAME_Y + y + 9, "    │         │");
	printByxy(FRAME_X + x, FRAME_Y + y +10, "    │         │");
	printByxy(FRAME_X + x, FRAME_Y + y +11, "    │         │");
	printByxy(FRAME_X + x, FRAME_Y + y +12, "    │         └──────────────┐");
	printByxy(FRAME_X + x, FRAME_Y + y +13, "    │                        │");
	printByxy(FRAME_X + x, FRAME_Y + y +14, "    │                        ├─┐");
	printByxy(FRAME_X + x, FRAME_Y + y +15, "    │                        ┌─┘");
	printByxy(FRAME_X + x, FRAME_Y + y +16, "    │                        │");
	printByxy(FRAME_X + x, FRAME_Y + y +17, "    └─┐  ┐  ┌───────┬──┐  ┌──┘");
	printByxy(FRAME_X + x, FRAME_Y + y +18, "      │ ─┤ ─┤       │ ─┤ ─┤");
	printByxy(FRAME_X + x, FRAME_Y + y +19, "      └──┴──┘       └──┴──┘");
	printByxy(FRAME_X + FRAME_L / 2 - 6, FRAME_Y + y + 25, "直视我,崽种!");
	printByxy(FRAME_X + FRAME_L + 2, FRAME_Y + 1, "欢迎来到贪吃蛇!");
	FILE * fp1 = fopen("config.txt", "r");
	fscanf(fp1, "%d %d", &choice_p, &lv);
	fclose(fp1);
	fp1 = NULL;
	FILE * fp2 = fopen("mark.txt", "r");
	fscanf(fp2, "%d %d %d %d %d %d", &mark[0], &mark[1], &mark[2], &times[0], &times[1], &times[2]);
	fclose(fp2);
	fp2 = NULL;
	showHellochoice();
	switch (choice_y)
	{
	case FRAME_Y + 3:
		play();
		break;
	case FRAME_Y + 5:
		old();
		break;
	case FRAME_Y + 7:
		config();
		break;
	}
}

void play()
{
	PlaySound((L"sounds/play.wav"), NULL, SND_ASYNC | SND_LOOP);
	Sleep(200);
	Clear(FRAME_X + 1, FRAME_Y + 1, FRAME_L / 2, FRAME_L - 1);
	Clear(FRAME_X + FRAME_L + 2, FRAME_Y, FRAME_L / 2 + 1, 20);
	printByxy(FRAME_X + FRAME_L + 5, FRAME_Y + 1, "游戏中");
	printByxy(FRAME_X + FRAME_L + 2, FRAME_Y + 3, "难度:" + Lv[lv]);
	printByxy(FRAME_X + FRAME_L + 2, FRAME_Y + 5, "时间:0s");
	printByxy(FRAME_X + FRAME_L + 2, FRAME_Y + 7, "分数:0分");
	Snake snake; //新建一条蛇
	InitSnake(&snake);
	PrintSnake(&snake);
	Food food;
	setXY(&food, &snake);
	PrintFood(&food);
	int marks = MoveSnake(&food, &snake, &Time);
	if ( (marks > mark[2]) || (marks == mark[2] && Time < times[2]) ) {
		int tempMark, tempTime;
		mark[2] = marks;
		times[2] = Time;
		for (int i = 0; i < 2; i++) {
			for (int j = 0; j < 2 - i; j++) {
				if ((mark[j] < mark[j + 1]) || (mark[j] == mark[j + 1] && times[j] > times[j + 1])) {
					tempMark = mark[j];
					mark[j] = mark[j + 1];
					mark[j + 1] = tempMark;
					tempTime = times[j];
					times[j] = times[j + 1];
					times[j + 1] = tempTime;
				}
			}
		}
		FILE * fp = fopen("mark.txt", "w");
		fprintf(fp, "%d %d %d %d %d %d", mark[0], mark[1], mark[2], times[0], times[1], times[2]);
		fclose(fp);
		fp = NULL;
	}
	printByxy(FRAME_X + FRAME_L + 5, FRAME_Y + 1, "游戏结束");
	SetPosition(FRAME_X + FRAME_L + 2, FRAME_Y + 9);
	system("pause");
	PlaySound((L"sounds/hello.wav"), NULL, SND_ASYNC | SND_LOOP);
	Sleep(200);
	Clear(FRAME_X + 1, FRAME_Y + 1, FRAME_L / 2, FRAME_L - 1);
	frame();
	hello();
}

void old()
{
	Clear(FRAME_X + FRAME_L + 2, FRAME_Y, FRAME_L / 2 + 1, 20);
	printByxy(FRAME_X + FRAME_L + 9, FRAME_Y + 1, "天梯榜");
	SetPosition(FRAME_X + FRAME_L + 2, FRAME_Y + 3);
	cout << "NO.1:" << mark[0] << "分\t" << times[0] << "s";
	SetPosition(FRAME_X + FRAME_L + 2, FRAME_Y + 5);
	cout << "NO.2:" << mark[1] << "分\t" << times[1] << "s";
	SetPosition(FRAME_X + FRAME_L + 2, FRAME_Y + 7);
	cout << "NO.3:" << mark[2] << "分\t" << times[2] << "s";
	printByxy(FRAME_X + FRAME_L + 2, FRAME_Y + 9, "按任意键返回");
	_getch();
	Clear(FRAME_X + FRAME_L + 2, FRAME_Y, FRAME_L / 2 + 1, 20);
	hello();
}

void configChoice()
{
	SetColor(4, 11);
	switch (choice_p)
	{
	case FRAME_Y + 7:
		printByxy(FRAME_X + FRAME_L + 4, FRAME_Y + 7, "小白");
		break;
	case FRAME_Y + 8:
		printByxy(FRAME_X + FRAME_L + 4, FRAME_Y + 8, "小青");
		break;
	case FRAME_Y + 9:
		printByxy(FRAME_X + FRAME_L + 4, FRAME_Y + 9, "小花");
		break;
	}
	SetColor(7, 0);
}

void showPf()
{
	switch (choice_p)
	{
	case FRAME_Y + 7:
		printByxy(FRAME_X + FRAME_L + 2, FRAME_Y + 11, "■■■■■■＠");
		break;
	case FRAME_Y + 8:
		SetColor(11, 0);
		printByxy(FRAME_X + FRAME_L + 2, FRAME_Y + 11, "■■■■■■＠");
		SetColor(7, 0);
		break;
	case FRAME_Y + 9:
		for (int i = 0; i < 7; i++)
		{
			if (i % 3 == 0)
				SetColor(7, 0);
			else if (i % 3 == 1)
				SetColor(14, 0);
			else
				SetColor(11, 0);
			if (i == 6)
			{
				printByxy(FRAME_X + FRAME_L + 2 + 2 * i, FRAME_Y + 11, "＠");
				continue;
			}	
			printByxy(FRAME_X + FRAME_L + 2 + 2 * i, FRAME_Y + 11, "■");
		}
		break;
	}
}

void config()
{
	Clear(FRAME_X + FRAME_L + 2, FRAME_Y, FRAME_L / 2 + 1, 20);
	printByxy(FRAME_X + FRAME_L + 5, FRAME_Y + 1, "设  置");
	printByxy(FRAME_X + FRAME_L + 2, FRAME_Y + 3, "难度:");
	printByxy(FRAME_X + FRAME_L + 2, FRAME_Y + 6, "皮肤:");
	printByxy(FRAME_X + FRAME_L + 4, FRAME_Y + 13, "按回车键返回");
	while (1)
	{
		SetColor(4, 0);
		printByxy(FRAME_X + FRAME_L + 4, FRAME_Y + 4, Lv[lv]);
		SetColor(7, 0);
		printByxy(FRAME_X + FRAME_L + 4, FRAME_Y + 7, "小白");
		printByxy(FRAME_X + FRAME_L + 4, FRAME_Y + 8, "小青");
		printByxy(FRAME_X + FRAME_L + 4, FRAME_Y + 9, "小花");
		configChoice();
		showPf();
		choice = _getch();
		if (choice == 13) {
			//记录设置
			FILE * fp = fopen("config.txt", "w");
			fprintf(fp, "%d %d", choice_p, lv);
			fclose(fp);
			fp = NULL;
			break;
		}
		else if (choice == 72)
		{
			if (choice_p == FRAME_Y + 7)
				choice_p = FRAME_Y + 9;
			else
				choice_p -= 1;
		}
		else if (choice == 80)
		{
			if (choice_p == FRAME_Y + 9)
				choice_p = FRAME_Y + 7;
			else
				choice_p += 1;
		}
		else if (choice == 75)
		{
			if (lv == 0)
				lv = 4;
			else
				lv -= 1;
		}
		else if (choice == 77)
		{
			if (lv == 4)
				lv = 0;
			else
				lv += 1;
		}
		configChoice();
		showPf();
		SetColor(4, 0);
		printByxy(FRAME_X + FRAME_L + 4, FRAME_Y + 4, Lv[lv]);
		SetColor(7, 0);
	}
	Clear(FRAME_X + FRAME_L + 2, FRAME_Y, FRAME_L / 2 + 1, 20);
	hello();
}


