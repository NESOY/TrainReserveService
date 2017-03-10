/******************************************
	콘솔을 담당하는 헤더파일
******************************************/

#include <stdio.h>
#include <conio.h>
#include <Windows.h>	//콘솔을 사용하기 위한 헤더 파일
#pragma warning(disable:4996)		//오류 제거

#ifndef CONSOLE_H
#define CONSOLE_H


// 키보드 입력값 정의
#define UP 72
#define DOWN 80
#define LEFT 75
#define RIGHT 77
#define ENTER 13
#define ESC 27
//좌표값보관 전역변수
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

