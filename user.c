#include "user.h"

/***************************************************************
	매개변수 : 없음
	기능	    : 나의 정보 메뉴 Print
****************************************************************/
void userDataMenu(){
   printf("\n\n");
   printf("\t┏━━━━━━━━━━━━━━━━━━━━━━┓\n");
   printf("\t┃                                            ┃ \n");
   printf("\t┃                                            ┃\n");
   printf("\t┃            아이디:                         ┃\n");
   printf("\t┃          비밀번호:                         ┃\n");
   printf("\t┃              이름:                         ┃\n");
   printf("\t┃              나이:                         ┃\n");
   printf("\t┃              성별:                         ┃\n");
   printf("\t┃            연락처:                         ┃\n");
   printf("\t┃                                            ┃\n");
   printf("\t┗━━━━━━━━━━━━━━━━━━━━━━┛\n");

}


/***************************************************************
	매개변수 : 없음
	기능	    : 사용자 메뉴 Print
****************************************************************/
void usermenu()
{
	printf("\n\n");
   printf("\t┏━━━━━━━━━━━━━━━━━━━━━━┓\n");
   printf("\t┃                                            ┃ \n");
   printf("\t┃                                            ┃\n");
   printf("\t┃                사용자  메뉴                ┃\n");
   printf("\t┃                                            ┃\n");
   printf("\t┃                                            ┃\n");
   printf("\t┃                                            ┃\n");
   printf("\t┃              1. 승차권 예약                ┃\n");
   printf("\t┃              2. 승차권 확인                ┃\n");
   printf("\t┃              3. 나의 정보                  ┃\n");
   printf("\t┃                                            ┃\n");
   printf("\t┃                                            ┃\n");
   printf("\t┃                                            ┃\n");
   printf("\t┃                                            ┃\n");
   printf("\t┃                                            ┃\n");
   printf("\t┃                                            ┃\n");
   printf("\t┗━━━━━━━━━━━━━━━━━━━━━━┛\n");
}



/***************************************************************
	매개변수 : 아이디
	기능	    : 해당아이디 데이터 출력
****************************************************************/
void userData(char *id){
	FILE *fp = fopen("Person.txt","r");
	char tmp_id[11];
	char tmp_pw[11];
	char tmp_name[11];
	char tmp_age[5];
	char tmp_gender[5];
	char tmp_phone[12];
	char tmp_mileage[5];

	if(fp == NULL){
		printf("ERROR OPEN FILE");
		exit(1);
	}
	userDataMenu();
	while(!feof(fp)){
		fscanf(fp,"%s",tmp_id);
		fscanf(fp,"%s",tmp_pw);
		fscanf(fp,"%s",tmp_name);
		fscanf(fp,"%s",tmp_phone);
		fscanf(fp,"%s",tmp_age);
		fscanf(fp,"%s",tmp_gender);
		fscanf(fp,"%s",tmp_mileage);		
		if(strcmp(id,tmp_id) == 0){			
			gotoxy(32,6);
			printf("%s",tmp_id);
			gotoxy(32,7);
			printf("%s",tmp_pw);
			gotoxy(32,8);
			printf("%s",tmp_name);
			gotoxy(32,9);
			printf("%s",tmp_age);
			gotoxy(32,10);
			printf("%s",tmp_gender);
			gotoxy(32,11);
			printf("%s",tmp_phone);
		}
	}
	fclose(fp);

	getchar();
}


/***************************************************************
	매개변수 : 아이디
	기능	    : 사용자 메인 함수
****************************************************************/
void userTitle(char* id){
	int key;
	curX=22;
	curY=10;
	while(1){
		system("cls");
		usermenu();
		gotoxy(curX,curY);
		printf("▶");
		key = get3MenuSelect();
		if(key == -1){
			curX=20;		curY=18;
			break;
		}
		if(key!=0){
			switch(key-9){
				showCursor();
				case 1:
					//예약
					system("cls");
					reserveTitle(id);
					curX=22;
					curY=10;					
					break;
				case 2:
					//확인
					system("cls");
					findReserve(id);
					curX=22;
					curY=11;					
					break;
				case 3:
					//나의 정보
					system("cls");
					userData(id);
					curX=22;
					curY=12;
					break;
			}
			hideCursor();
		}
	
	}
}
