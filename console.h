/******************************************
	�ܼ��� ����ϴ� �������
******************************************/

#include <stdio.h>
#include <conio.h>
#include <Windows.h>	//�ܼ��� ����ϱ� ���� ��� ����
#pragma warning(disable:4996)		//���� ����

#ifndef CONSOLE_H
#define CONSOLE_H


// Ű���� �Է°� ����
#define UP 72
#define DOWN 80
#define LEFT 75
#define RIGHT 77
#define ENTER 13
#define ESC 27
//��ǥ������ ��������
int curX;
int curY;


void gotoxy(int x, int y);
void hideCursor();
void showCursor();			
void hidetext();				
void showtext();				
void warntext();				
void yellowtext();		
int get4MenuSelect();		
int get3MenuSelect();		
int get2MenuSelect();		

#endif

