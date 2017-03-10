#include "manager.h"



/***************************************************************
	매개변수 : 없음
	기능	    : 관리자 메뉴 Print
****************************************************************/
void managerMenu(){
	printf("\n\n");
	printf("\t┏━━━━━━━━━━━━━━━━━━━━━━┓\n");
	printf("\t┃                                            ┃ \n");
	printf("\t┃                                            ┃\n");
	printf("\t┃                관리자  정보                ┃\n");
	printf("\t┃                                            ┃\n");
	printf("\t┃                                            ┃\n");
	printf("\t┃                                            ┃\n");
	printf("\t┃              1. 사용자 관리                ┃\n");
	printf("\t┃              2. 배차 추가/조회             ┃\n");
	printf("\t┃                                            ┃\n");
	printf("\t┃                                            ┃\n");
	printf("\t┃                                            ┃\n");
	printf("\t┃                                            ┃\n");
	printf("\t┃                                            ┃\n");
	printf("\t┃                                            ┃\n");
	printf("\t┗━━━━━━━━━━━━━━━━━━━━━━┛\n");
}


/***************************************************************
	매개변수 : 없음
	기능	    : 관리자 메인 함수
****************************************************************/
void manager(){
	int key;
	char id[11];
	curX=22;
	curY=10;
	while(1){
		system("cls");
		managerMenu();
		gotoxy(curX,curY);
		printf("▶");
		key = get2MenuSelect();
		if(key == -1){
			curX=20;		curY=18;
			break;
		}
		if(key!=0){
			switch(key-9){
				case 1:
					//사용자관리
					system("cls");
					printf("아이디를 입력해주세영 : ");
					scanf("%s",id);
					findReserve(id);
					getchar();
					getchar();
					curX=22;
					curY=10;
					break;
				case 2:
					//배차추가/조회
					system("cls");
					trainTitle();
					curX=22;
					curY=10;
					break;
			}
		}
	
	}
}
