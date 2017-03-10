/******************************************
	패스워드 찾는 헤더 파일
******************************************/

#include "console.h"
#pragma warning(disable:4996)	//오류 제거


#ifndef FINDPW_H
#define FINDPW_H


void findPwMenu();
void checkPw(char id[],char name[],char phone[]);
void findPw();

#endif