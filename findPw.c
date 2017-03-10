#include "findPw.h"

/***************************************************************
	매개변수 : 없음
	기능	    : 패스워드 작성 메뉴 Print
****************************************************************/
void findPwMenu()
{
   printf("\n\n");
   printf("\t┏━━━━━━━━━━━━━━━━━━━━━━┓\n");
   printf("\t┃                                            ┃ \n");
   printf("\t┃                                            ┃\n");
   printf("\t┃                                            ┃\n");
   printf("\t┃                비밀번호 찾기               ┃\n");
   printf("\t┃                                            ┃\n");
   printf("\t┃                                            ┃\n");
   printf("\t┃             ID:                            ┃\n");
   printf("\t┃                                            ┃\n");
   printf("\t┃           이름:                            ┃\n");
   printf("\t┃                                            ┃\n");
   printf("\t┃             HP:                            ┃\n");
   printf("\t┃                                            ┃\n");
   printf("\t┃                                            ┃\n");
   printf("\t┃                                            ┃\n");
   printf("\t┃                                            ┃\n");
   printf("\t┃                                            ┃\n");
   printf("\t┃                                            ┃\n");
   printf("\t┗━━━━━━━━━━━━━━━━━━━━━━┛\n");
}


/***************************************************************
	매개변수 : 아이디, 이름, 전화번호
	기능	    : 매개변수를 통해 정보가 맞는지 확인하는 함수.
****************************************************************/
void checkPw(char id[],char name[],char phone[]){
	FILE *fp = fopen("Person.txt","r");
	int i;
	char checkid[12];
	char checkName[12];
	char checkPhone[13];
	char checkpw[15];
	if(fp == NULL){
		printf("Error Open File\n");
		exit(1);
	}
	while(!feof(fp)){
		fscanf(fp,"%s",&checkid);
		fscanf(fp,"%s",&checkpw);	//일단 패스워드 받아놓기
		fscanf(fp,"%s",&checkName);
		fscanf(fp,"%s",&checkPhone);
			//아이디 이름 폰넘버 같을경우
			if(strcmp(checkid,id) == 0 && strcmp(checkName,name) == 0 && strcmp(checkPhone,phone) == 0){
							yellowtext();
							gotoxy(22,17);
							printf("※ Your PassWord ▶%s",checkpw);
							showtext();
							Sleep(3000);
							break;
					}
			else if(strcmp(checkid,id) == 0){	//아이디 같은경우
				if(strcmp(checkName,name) != 0 && strcmp(checkPhone,phone)==0){	//이름만 다를경우
							warntext();
							gotoxy(22,17);
							printf("※ 이름을 잘못 입력하셨습니다.");
							showtext();
							Sleep(3000);
							break;
				}
				else if(strcmp(checkName,name) == 0 && strcmp(checkPhone,phone)!=0){	//전화번호만 다를경우
							warntext();
							gotoxy(22,17);
							printf("※전화번호를 잘못 입력하셨습니다.");
							showtext();
							Sleep(3000);
							break;
				}
				else{//둘다틀릴경우
							warntext();
							gotoxy(15,17);
							printf("※이름과 전화번호를 잘못 입력하셨습니다.");
							showtext();
							Sleep(3000);
				}					
			}
			else{
					for(i=0; i<3; i++)
						fscanf(fp,"%s",checkid);
			}
	}

}



/***************************************************************
	매개변수 : 없음
	기능	    : 패스워드 찾기 메인 함수
****************************************************************/
void findPw(){
	FILE *fp = fopen("Person.txt","r");
	int i=0;
	int count=0;
	char tmpId[12];
	char inputId[12];
	char name[11];
	char phone[12];
	if(fp == NULL){
		printf("Error Open File\n");
		exit(1);
	}
	showCursor();
	findPwMenu();
	gotoxy(29,10);
	gets(inputId);

	while(!feof(fp)){
		fscanf(fp,"%s",tmpId);
		if(strcmp(inputId,tmpId) == 0){
			count++;
		}
		else{
			for(i=0; i<6; i++)
				fscanf(fp,"%s",tmpId);
		}
	}
	if(count == 0){
			warntext();
			gotoxy(22,17);
			printf("찾는 아이디가 존재하지않습니다!\n");
			showtext();
			Sleep(750);
	}
	else{
		gotoxy(29,12);
		gets(name);
		gotoxy(29,14);
		gets(phone);
		checkPw(inputId,name,phone);
	}
	hideCursor();
	fclose(fp);	
}
