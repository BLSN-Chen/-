//
//                       _oo0oo_
//                      o8888888o
//                      88" . "88
//                      (| -_- |)
//                      0\  =  /0
//                    ___/`---'\___
//                  .' \\|     |// '.
//                 / \\|||  :  |||// \
//                / _||||| -:- |||||- \
//               |   | \\\  -  /// |   |
//               | \_|  ''\---/''  |_/ |
//               \  .-\__  '-'  ___/-. /
//             ___'. .'  /--.--\  `. .'___
//          ."" '<  `.___\_<|>_/___.' >' "".
//         | | :  `- \`.;`\ _ /`;.`/ - ` : | |
//         \  \ `_.   \_ __\ /__ _/   .-` /  /
//     =====`-.____`.___ \_____/___.-`___.-'=====
//                       `=---='
//
//
//     ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
//
//               ���汣��         ����BUG
//
//

#pragma once
#include<iostream>
#include<string>
#include<windows.h>
#include<Mmsystem.h>
#pragma comment(lib,"winmm.lib")
using namespace std;

/* ��������ǰ��ɫ�ͱ���ɫ */
/****************************************************************************************************************************
	* 0-��ɫ��1-��ɫ��2-��ɫ��3-ǳ��ɫ��4-��ɫ��5-��ɫ��6-��ɫ��7-��ɫ��8-��ɫ
	* 9-����ɫ��10-����ɫ��11-��ǳ��ɫ��12-����ɫ��13-����ɫ��14-����ɫ��15-����ɫ
	**************************************************************************************************************************/
void SetColor(int foreColor, int backColor);

void hide_cursor();//���ع��

void show_cursor();//��ʾ���

void SetPosition(int x, int y);//�������� 

void printByxy(int x, int y, string msg);// ��ӡ����

void printByxy(int x, int y, int num);// ��ӡ����

void Clear(int x, int y, int rowCount, int a);//����x,y��ʼ��rowCount��,ÿ������a������