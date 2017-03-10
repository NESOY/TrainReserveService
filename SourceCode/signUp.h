/******************************************
	회원가입을 담당하는 헤더파일
******************************************/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "console.h"
#pragma warning(disable:4996)	//오류 제거
#ifndef SIGN_UP
#define SIGN_UP




//회원가입구조체
typedef struct Person{
	int age;
	int mileage;
	char gender[11];
	char name[11];
	char id[11];
	char pw[15];
	char phone[12];
}Person;




//함수
void signUp();
int getId(Person *p);
int getPw(Person *p);
int getName(Person *p);
int getAge(Person *p);
int getGender(Person *p);
int getPhonNum(Person *p);
void inputPerson(Person *p);

#endif