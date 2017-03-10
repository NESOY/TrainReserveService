#include "console.h"
#include <stdlib.h>
#pragma warning(disable:4996)
#ifndef STATION_H
#define STATION_H
#define stMAX 50


//����ȭ ����ü
typedef struct Mstation{
	int time;
	int pay;
	char startSt[11];
	char destSt[11];
}Mstation;

//KTX ����ü
typedef struct Kstation{
	int time;
	int pay;
	char startSt[11];
	char destSt[11];
}Kstation;


//����ȭ KTX ���� ����ü
typedef struct Station{
	struct Mstation m;
	struct Kstation k;
	int edge;
}Station;



extern Station st[stMAX][stMAX];	//�������� �� 50X50 Matrix
extern int Path[stMAX][stMAX];		//��������� ��ȣ�� ������ 50X50 Matrix


void makeStation();

#endif