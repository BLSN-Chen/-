#pragma once
#include <cstdlib>
#include <ctime>
#define MAX_SIZE 255

/** 数据结构 */
typedef struct
{
	int x;
	int y;
	int pos;
}ElementType;

/** 蛇结构 */
typedef struct
{
	ElementType datas[MAX_SIZE];//蛇元素集合
	int length;                 //当前蛇长度
	bool died;					//蛇是否死亡
	int Dir;                    //蛇头方向
}Snake;

/** 初始化蛇 */
void InitSnake(Snake * snake);

/** 插入蛇身 */
void InsertElement(Snake * snake, ElementType lement);

/** 打印蛇 */
void PrintSnake(Snake * snake);

bool isDied(Snake * snake);

/** 食物类 */
typedef struct Food
{
	int X;
	int Y;
}Food;

void setXY(Food * food, Snake * snake);

int getX(Food * food);

int getY(Food * food);

void PrintFood(Food * food);

/** 移动蛇，返回分数 */
int MoveSnake(Food * food, Snake * snake, int * Time);