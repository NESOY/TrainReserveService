#include "console.h"
#include <stdlib.h>
#pragma warning(disable:4996)
#ifndef STATION_H
#define STATION_H
#define stMAX 50


//무궁화 구조체
typedef struct Mstation{
	int time;
	int pay;
	char startSt[11];
	char destSt[11];
}Mstation;

//KTX 구조체
typedef struct Kstation{
	int time;
	int pay;
	char startSt[11];
	char destSt[11];
}Kstation;


//무궁화 KTX 통합 구조체
typedef struct Station{
	struct Mstation m;
	struct Kstation k;
	int edge;
}Station;



extern Station st[stMAX][stMAX];	//전역변수 역 50X50 Matrix
extern int Path[stMAX][stMAX];		//이전노드의 번호를 저장할 50X50 Matrix


void makeStation();

#endif