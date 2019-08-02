#pragma once
#pragma warning(disable:4996)
#include <stdio.h>
#include <conio.h>
#include "config.h"
#include "sprite.h"
#define FRAME_X 12
#define FRAME_Y 1
#define FRAME_L 65

/** 基本框架 */
void frame();

/**  */
int getLv();

/**  */
int getPf();

/** 显示当前选项 */
void showChoice();

/** 显示主选项 */
void showHellochoice();

/** 欢迎界面 */
void hello();

/** 新的开始 */
void play();

/** 游戏记录 */
void old();

/** 显示当前设置 */
void configChoice();

/** 显示皮肤示例 */
void showPf();

/** 设置 */
void config();