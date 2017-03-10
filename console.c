#include"console.h"







/***************************************************************
	�Ű����� : ����
	���	    : �ܼ��̵� �� Ŀ��
****************************************************************/
void gotoxy(int x, int y)//���� ���ϴ� ��ġ�� Ŀ�� �̵�
{
    COORD pos = {x-1, y-1};//Ŀ���� X��ǥ���� -1 �Ѱ�. Y��ǥ���� -1�� ������ �̵�
    SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), pos);// WIN32API �Լ��Դϴ�. �̰� ���ʿ� �����
}


/***************************************************************
	�Ű����� : ����
	���	    : Ŀ�� �����
****************************************************************/
void hideCursor()
{
	CONSOLE_CURSOR_INFO CurInfo;
	CurInfo.dwSize=1;
	 CurInfo.bVisible=FALSE;
	 SetConsoleCursorInfo(GetStdHandle(STD_OUTPUT_HANDLE),&CurInfo);
}


/***************************************************************
	�Ű����� : ����
	���	    : Ŀ�� �����ֱ�
****************************************************************/
void showCursor(){
	CONSOLE_CURSOR_INFO CurInfo;
	CurInfo.dwSize=1;
	 CurInfo.bVisible=TRUE;
	 SetConsoleCursorInfo(GetStdHandle(STD_OUTPUT_HANDLE),&CurInfo);
}


/***************************************************************
	�Ű����� : ����
	���	    : �Է°� �����
****************************************************************/
void hidetext(){
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 0x77);
}


/***************************************************************
	�Ű����� : ����
	���	    : �Է°� �����ֱ�
****************************************************************/
void showtext(){
SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),FOREGROUND_INTENSITY|FOREGROUND_RED|FOREGROUND_BLUE|FOREGROUND_GREEN); 
}


/***************************************************************
	�Ű����� : ����
	���	    : ���޼��� ���� ����
****************************************************************/
void warntext(){
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),FOREGROUND_INTENSITY|FOREGROUND_RED);
}



/***************************************************************
	�Ű����� : ����
	���	    : �߿�޼��� ���� ����
****************************************************************/
void yellowtext(){
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),FOREGROUND_INTENSITY|FOREGROUND_RED|FOREGROUND_GREEN); // YELLOW
}


/***************************************************************
	�Ű����� : ����
	���	    : 4�����޴� �Է� �Լ�
****************************************************************/
int get4MenuSelect(){
	int key;
	gotoxy(curX,curY);
	printf("��");
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
	�Ű����� : ����
	���	    : 3�����޴� �Է� �Լ�
****************************************************************/
int get3MenuSelect(){
	int key;
	gotoxy(curX,curY);
	printf("��");
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
	�Ű����� : ����
	���	    : 2�����޴� �Է� �Լ�
****************************************************************/
int get2MenuSelect(){
	int key;
	gotoxy(curX,curY);
	printf("��");
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


