#include"login.h"


/***************************************************************
	매개변수 : 없음
	기능	    : 로그인 작성 메뉴 Print
****************************************************************/
void loginMenu()
{
	//로그인
   printf("\n\n");
   printf("\t┏━━━━━━━━━━━━━━━━━━━━━━┓\n");
   printf("\t┃                                            ┃ \n");
   printf("\t┃                                            ┃\n");
   printf("\t┃                                            ┃\n");
   printf("\t┃                   Login                    ┃\n");
   printf("\t┃                                            ┃\n");
   printf("\t┃                                            ┃\n");
   printf("\t┃              ID:                           ┃\n");
   printf("\t┃                                            ┃\n");
   printf("\t┃              PW:                           ┃\n");
   printf("\t┃                                            ┃\n");
   printf("\t┃                                            ┃\n");
   printf("\t┃                                            ┃\n");
   printf("\t┃                                            ┃\n");
   printf("\t┃                                            ┃\n");
   printf("\t┗━━━━━━━━━━━━━━━━━━━━━━┛\n");
}




/***************************************************************
	매개변수 : 아이디, 패스워드
	기능	    : 로그인 체크(아이디와 패스워드가 맞는지)
****************************************************************/
int loginCheck(char id[], char pw[]){
	FILE *fp = fopen("Person.txt","r");
	int i;
	char checkid[12];
	char checkpw[15];
	if(fp == NULL){
		printf("Error Open File\n");
		exit(1);
	}
	while(!feof(fp)){
		fscanf(fp,"%s",checkid);
		//아이디같을경우
		if(strcmp(checkid,id) == 0){
			fscanf(fp,"%s",&checkpw);
			//패스워드같을경우
			if(strcmp(checkpw,pw) == 0)	return 1;
			else{
				warntext();
				gotoxy(22,17);
				printf("패스워드가 틀립니다.\n");
				showtext();
				Sleep(950);
				return 0;				
			}
		}
		else{
				for(i=0; i<6; i++)
					fscanf(fp,"%s",checkid);
		}
	}
	warntext();
	gotoxy(22,17);
	printf("입력한 아이디가 없습니다.\n");
	showtext();
	Sleep(950);
	fclose(fp);
	return 0;	
}




/***************************************************************
	매개변수 : 없음
	기능	    : 로그인 메인 함수
****************************************************************/
void login(){	
	char id[11];
	char pw[15];
	loginMenu();
	gotoxy(29,10);
	gets(id);
	gotoxy(29,12);
	hidetext();
	gets(pw);
	showtext();
	if(loginCheck(id,pw) == 1){
		//역생성
		makeStation();
		//관리자
		if(strcmp(id ,"root") == 0){
			manager();
		}
		//일반로그인
		else
			userTitle(id);
	}
}
