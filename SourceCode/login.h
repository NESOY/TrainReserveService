/******************************************
	�α����� ����ϴ� �������
******************************************/


#include <string.h>
#include "station.h"
#include "console.h"
#include "train.h"
#include "station.h"
#include "reserve.h"
#include "manager.h"
#include "user.h"
#pragma warning(disable:4996)	// ��������


#ifndef LOGIN_H
#define LOGIN_H


void loginMenu();
int loginCheck(char id[], char pw[]);
void login();


#endif