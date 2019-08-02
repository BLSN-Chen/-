#pragma once
#include <cstdlib>
#include <ctime>
#define MAX_SIZE 255

/** ���ݽṹ */
typedef struct
{
	int x;
	int y;
	int pos;
}ElementType;

/** �߽ṹ */
typedef struct
{
	ElementType datas[MAX_SIZE];//��Ԫ�ؼ���
	int length;                 //��ǰ�߳���
	bool died;					//���Ƿ�����
	int Dir;                    //��ͷ����
}Snake;

/** ��ʼ���� */
void InitSnake(Snake * snake);

/** �������� */
void InsertElement(Snake * snake, ElementType lement);

/** ��ӡ�� */
void PrintSnake(Snake * snake);

bool isDied(Snake * snake);

/** ʳ���� */
typedef struct Food
{
	int X;
	int Y;
}Food;

void setXY(Food * food, Snake * snake);

int getX(Food * food);

int getY(Food * food);

void PrintFood(Food * food);

/** �ƶ��ߣ����ط��� */
int MoveSnake(Food * food, Snake * snake, int * Time);