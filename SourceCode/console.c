#include"console.h"







/***************************************************************
	매개변수 : 없음
	기능	    : 콘솔이동 및 커서
****************************************************************/
void gotoxy(int x, int y)//내가 원하는 위치로 커서 이동
{
    COORD pos = {x-1, y-1};//커서가 X좌표에서 -1 한값. Y좌표에서 -1한 값으로 이동
    SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), pos);// WIN32API 함수입니다. 이건 알필요 없어요
}


/***************************************************************
	매개변수 : 없음
	기능	    : 커서 숨기기
****************************************************************/
void hideCursor()
{
	CONSOLE_CURSOR_INFO CurInfo;
	CurInfo.dwSize=1;
	 CurInfo.bVisible=FALSE;
	 SetConsoleCursorInfo(GetStdHandle(STD_OUTPUT_HANDLE),&CurInfo);
}


/***************************************************************
	매개변수 : 없음
	기능	    : 커서 보여주기
****************************************************************/
void showCursor(){
	CONSOLE_CURSOR_INFO CurInfo;
	CurInfo.dwSize=1;
	 CurInfo.bVisible=TRUE;
	 SetConsoleCursorInfo(GetStdHandle(STD_OUTPUT_HANDLE),&CurInfo);
}


/***************************************************************
	매개변수 : 없음
	기능	    : 입력값 숨기기
****************************************************************/
void hidetext(){
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 0x77);
}


/***************************************************************
	매개변수 : 없음
	기능	    : 입력값 보여주기
****************************************************************/
void showtext(){
SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),FOREGROUND_INTENSITY|FOREGROUND_RED|FOREGROUND_BLUE|FOREGROUND_GREEN); 
}


/***************************************************************
	매개변수 : 없음
	기능	    : 경고메세지 색깔 설정
****************************************************************/
void warntext(){
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),FOREGROUND_INTENSITY|FOREGROUND_RED);
}



/***************************************************************
	매개변수 : 없음
	기능	    : 중요메세지 색깔 설정
****************************************************************/
void yellowtext(){
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),FOREGROUND_INTENSITY|FOREGROUND_RED|FOREGROUND_GREEN); // YELLOW
}


/***************************************************************
	매개변수 : 없음
	기능	    : 4가지메뉴 입력 함수
****************************************************************/
int get4MenuSelect(){
	int key;
	gotoxy(curX,curY);
	printf("▶");
	key = getch();
	if(key==224)
		key = getch();
		switch(key){
			case UP:
				curY--;
				if(curY < 18)		curY = 18;
				break;
			case DOWN:
				curY++;
				if(curY > 21)		curY = 21;
				break;	
			case ENTER:
				return curY;
		}
	
	
	return 0;
}


/***************************************************************
	매개변수 : 없음
	기능	    : 3가지메뉴 입력 함수
****************************************************************/
int get3MenuSelect(){
	int key;
	gotoxy(curX,curY);
	printf("▶");
	key = getch();
	if(key==224)
		key = getch();
		switch(key){
			case UP:
				curY--;
				if(curY < 10)		curY = 10;
				break;				
			case DOWN:
				curY++;
				if(curY > 12)		curY = 12;
				break;			
			case ENTER:
				return curY;
			case ESC:
				return -1;
		}
	return 0;
}



/***************************************************************
	매개변수 : 없음
	기능	    : 2가지메뉴 입력 함수
****************************************************************/
int get2MenuSelect(){
	int key;
	gotoxy(curX,curY);
	printf("▶");
	key = getch();
	if(key==224)
		key = getch();
		switch(key){
			case UP:
				curY--;
				if(curY < 10)		curY = 10;
				break;				
			case DOWN:
				curY++;
				if(curY > 11)		curY = 11;
				break;			
			case ENTER:
				return curY;
			case ESC:
				return -1;
		}
	return 0;
	
	
}


