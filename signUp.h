/******************************************
	ȸ�������� ����ϴ� �������
******************************************/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "console.h"
#pragma warning(disable:4996)	//���� ����
#ifndef SIGN_UP
#define SIGN_UP




//ȸ�����Ա���ü
typedef struct Person{
	int age;
	int mileage;
	char gender[11];
	char name[11];
	char id[11];
	char pw[15];
	char phone[12];
}Person;




//�Լ�
void signUp();
int getId(Person *p);
int getPw(Person *p);
int getName(Person *p);
int getAge(Person *p);
int getGender(Person *p);
int getPhonNum(Person *p);
void inputPerson(Person *p);

#endif