#pragma once
#pragma warning(disable:4996)
#include <stdio.h>
#include <conio.h>
#include "config.h"
#include "sprite.h"
#define FRAME_X 12
#define FRAME_Y 1
#define FRAME_L 65

/** ������� */
void frame();

/**  */
int getLv();

/**  */
int getPf();

/** ��ʾ��ǰѡ�� */
void showChoice();

/** ��ʾ��ѡ�� */
void showHellochoice();

/** ��ӭ���� */
void hello();

/** �µĿ�ʼ */
void play();

/** ��Ϸ��¼ */
void old();

/** ��ʾ��ǰ���� */
void configChoice();

/** ��ʾƤ��ʾ�� */
void showPf();

/** ���� */
void config();