#include "Game.h"


char Key;//记录按键
int lastX, lastY;//记录蛇尾坐标
clock_t startTime;
clock_t nowTime;
int marks = 0;

void InitSnake(Snake * snake)
{
	snake->length = 2;
	snake->died = false;
	snake->Dir = 4;
	snake->datas[0] = { FRAME_X + FRAME_L / 2 - 1, FRAME_Y + FRAME_L / 4, 1 };
	snake->datas[1] = { snake->datas[0].x - 2 , snake->datas[0].y, 2 };
}

void InsertElement(Snake * snake, ElementType element)
{
	if (snake->length + 1 > MAX_SIZE)
	{
		printByxy(FRAME_X + FRAME_L + 2, FRAME_Y + 7, "蛇已经撑死了!!!");
		return;
	}
	snake->datas[snake->length] = element;
	snake->length++;
}

void PrintSnake(Snake * snake)
{

	if (getPf() == 1)
	{
		SetColor(7, 0);
		for (int i = 0; i < snake->length; i++)
		{
			if (i == 0)
				printByxy(snake->datas[i].x, snake->datas[i].y, "＠");
			else
				printByxy(snake->datas[i].x, snake->datas[i].y, "■");
		}
	}
	if (getPf() == 2)
	{
		SetColor(11, 0);
		for (int i = 0; i < snake->length; i++)
		{
			if (i == 0)
				printByxy(snake->datas[i].x, snake->datas[i].y, "＠");
			else
				printByxy(snake->datas[i].x, snake->datas[i].y, "■");
		}
	}
	if (getPf() == 3)
	{
		for (int i = 0; i < snake->length; i++)
		{
			if (i % 3 == 0)
				SetColor(7, 0);
			if(i % 3 == 1)
				SetColor(11, 0);
			if (i % 3 == 2)
				SetColor(14, 0);
			if (i == 0)
				printByxy(snake->datas[i].x, snake->datas[i].y, "＠");
			else
				printByxy(snake->datas[i].x, snake->datas[i].y, "■");
		}
	}
	SetColor(7, 0);
}

bool isDied(Snake * snake)
{
	if(snake->datas[0].x <= FRAME_X || snake->datas[0].x == FRAME_X + FRAME_L || snake->datas[0].y == FRAME_Y || snake->datas[0].y == FRAME_Y + FRAME_L / 2 + 1)
		return true;
	for (int i = 1; i < snake->length; i++)
	{
		if (snake->datas[0].x == snake->datas[i].x && snake->datas[0].y == snake->datas[i].y)
			return true;
	}
	return false;
}


void setXY(Food * food, Snake * snake)
{
	srand((unsigned)time(0));
	bool ok = false;
	while (!ok)
	{
		food->X = FRAME_X + rand() % 63 + 1;//x范围(1-63)
		if (food->X % 2 == 1)
		{
			food->Y = FRAME_Y + rand() % 32 + 1;//y范围(1-32)
			for (int i = 0; i < snake->length; i++)
			{
				if (food->X == snake->datas[i].x && food->Y == snake->datas[i].y)
				{
					ok = false;
					break;
				}
				ok = true;
			}
		}
	}
}


int getX(Food * food)
{
	return food->X;
}

int getY(Food * food)
{
	return food->Y;
}

void PrintFood(Food * food)
{
	SetColor(4, 0);
	printByxy(food->X, food->Y, "●");
	SetColor(7, 0);
}


int MoveSnake(Food * food, Snake * snake, int * Time)
{
	startTime = clock();
	marks = 0;
	*Time = 0;
	while (!snake->died)//没有死亡就循环
	{
		nowTime = clock();
		SetPosition(FRAME_X + FRAME_L + 7, FRAME_Y + 5);
		*Time = (nowTime - startTime) / 1000;
		cout << *Time << "s";
		if (!_kbhit())//如果用户没有击键
		{
			lastX = snake->datas[snake->length - 1].x;
			lastY = snake->datas[snake->length - 1].y;
			for (int i = snake->length; i > 1; i--)
			{
				snake->datas[i - 1].x = snake->datas[i - 2].x;
				snake->datas[i - 1].y = snake->datas[i - 2].y;
			}
			switch (snake->Dir)
			{
			case 1:
				snake->datas[0].y--;
				break;
			case 2:
				snake->datas[0].y++;
				break;
			case 3:
				snake->datas[0].x -= 2;
				break;
			case 4:
				snake->datas[0].x += 2;
				break;
			}
			Sleep(50 * (5 - getLv()));
			PrintSnake(snake);
			printByxy(lastX, lastY, "  ");
			if (snake->datas[0].x == getX(food) && snake->datas[0].y == getY(food))//吃到食物
			{
				InsertElement(snake, { lastX, lastY, snake->length });
				setXY(food, snake);
				PrintFood(food);
				marks += (3 + getLv());
				SetPosition(FRAME_X + FRAME_L + 7, FRAME_Y + 7);
				cout << marks << "分";
			}
			snake->died = isDied(snake);
			continue;
		}
		Key = _getch();
		switch (Key)
		{
		case 72:
			if (snake->Dir != 2)
				snake->Dir = 1;
			else
				snake->Dir = 2;
			break;
		case 80:
			if (snake->Dir != 1)
				snake->Dir = 2;
			else
				snake->Dir = 1;
			break;
		case 75:
			if (snake->Dir != 4)
				snake->Dir = 3;
			else
				snake->Dir = 4;
			break;
		case 77:
			if (snake->Dir != 3)
				snake->Dir = 4;
			else
				snake->Dir = 3;
			break;
		default:
			break;
		}
		continue;
	}
	return marks;
}
