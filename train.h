/******************************************
	������ ����ϴ� �������
******************************************/

#include "console.h"
#include "station.h"
#pragma warning(disable:4996)
#ifndef TRAIN_H
#define TRAIN_H

typedef struct trainData{
	char startSt[11];
	char destSt[11];
	char trainClass[10];
	char trainNum[11];
	int hour,min;
}trainData;

Station st[stMAX][stMAX];
int Path[stMAX][stMAX];
char route[150];			//��Ʈ�� ������ ����
int cnt;					//������ ����
void trainMenu();
void trainCreateMenu();
void trainCheckMenu();
int trainClass(trainData *td);
int trainCheckNum(trainData *td);
char* trainCheckstartSt();
char* trainCheckdestSt();
void path(int start,int end,char *train);
void trainRoute(char *startSt,char *destSt,char *train);
void trainCreate();
void trainAsk();
void trainTitle();
#endif