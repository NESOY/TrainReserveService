/******************************************
	예약을 담당하는 헤더파일
******************************************/

#include "console.h"
#include "train.h"
#include "station.h"
#include <time.h>
#ifndef RESERVE_H
#define RESERVE_H
#pragma warning(disable:4996)	//오류제거
//예약정보구조체
typedef struct bookData{
	char id[11];		//아이디
	char startDate[7];	//날짜
	char startSt[11];	//출발역
	char destSt[11];	//도착역
	char transfer[11];	//환승역
	char st_trainNum[11];	//기차번호
	char tr_trainNum[11];
	int st_hNum,st_mNum;	//출발시간/분
	int sttr_hNum,sttr_mNum;//출발환승 시간/분
	int trdt_hNum,trdt_mNum;//환승도착 시간/분
	int dt_hNum,dt_mNum;	//도착시간/분
	int pNum;				//예약인원수
	int pay;				//요금
	int check;				//직행/환승 정보

}bookData;
//배차정보
typedef struct element{
	int trainNum;
	int st_time;
	int dt_time;
	int pay;
	char trainClass[10];
	char startSt[10];
	char destSt[10];
}element;
//리스트
typedef struct List{
	element data;
	struct List * link;
}List;

void selectMenu();
void insert_node(List **phead, List *p, int trainNum, int st_time , int dt_time,int pay,char trainClass[],char startSt[], char destSt[]);
void ShowList();
void ShowReserve();
void reserveMenu();
char* CheckstartSt();
char* CheckdestSt(char* startSt);
void showTD(List *p);
char* CheckTD(char* trainNum,char* startSt,char* destSt);
bookData makeReserve(char startSt[],char destSt[]);
void inputReserve(bookData book);
void findReserve(char* inputid);
void reserveTitle(char id[]);

#endif