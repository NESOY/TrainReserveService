/******************************************
	������ ����ϴ� �������
******************************************/

#include "console.h"
#include "train.h"
#include "station.h"
#include <time.h>
#ifndef RESERVE_H
#define RESERVE_H
#pragma warning(disable:4996)	//��������
//������������ü
typedef struct bookData{
	char id[11];		//���̵�
	char startDate[7];	//��¥
	char startSt[11];	//��߿�
	char destSt[11];	//������
	char transfer[11];	//ȯ�¿�
	char st_trainNum[11];	//������ȣ
	char tr_trainNum[11];
	int st_hNum,st_mNum;	//��߽ð�/��
	int sttr_hNum,sttr_mNum;//���ȯ�� �ð�/��
	int trdt_hNum,trdt_mNum;//ȯ�µ��� �ð�/��
	int dt_hNum,dt_mNum;	//�����ð�/��
	int pNum;				//�����ο���
	int pay;				//���
	int check;				//����/ȯ�� ����

}bookData;
//��������
typedef struct element{
	int trainNum;
	int st_time;
	int dt_time;
	int pay;
	char trainClass[10];
	char startSt[10];
	char destSt[10];
}element;
//����Ʈ
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