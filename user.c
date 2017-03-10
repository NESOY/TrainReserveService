#include "user.h"

/***************************************************************
	�Ű����� : ����
	���	    : ���� ���� �޴� Print
****************************************************************/
void userDataMenu(){
   printf("\n\n");
   printf("\t������������������������������������������������\n");
   printf("\t��                                            �� \n");
   printf("\t��                                            ��\n");
   printf("\t��            ���̵�:                         ��\n");
   printf("\t��          ��й�ȣ:                         ��\n");
   printf("\t��              �̸�:                         ��\n");
   printf("\t��              ����:                         ��\n");
   printf("\t��              ����:                         ��\n");
   printf("\t��            ����ó:                         ��\n");
   printf("\t��                                            ��\n");
   printf("\t������������������������������������������������\n");

}


/***************************************************************
	�Ű����� : ����
	���	    : ����� �޴� Print
****************************************************************/
void usermenu()
{
	printf("\n\n");
   printf("\t������������������������������������������������\n");
   printf("\t��                                            �� \n");
   printf("\t��                                            ��\n");
   printf("\t��                �����  �޴�                ��\n");
   printf("\t��                                            ��\n");
   printf("\t��                                            ��\n");
   printf("\t��                                            ��\n");
   printf("\t��              1. ������ ����                ��\n");
   printf("\t��              2. ������ Ȯ��                ��\n");
   printf("\t��              3. ���� ����                  ��\n");
   printf("\t��                                            ��\n");
   printf("\t��                                            ��\n");
   printf("\t��                                            ��\n");
   printf("\t��                                            ��\n");
   printf("\t��                                            ��\n");
   printf("\t��                                            ��\n");
   printf("\t������������������������������������������������\n");
}



/***************************************************************
	�Ű����� : ���̵�
	���	    : �ش���̵� ������ ���
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
	�Ű����� : ���̵�
	���	    : ����� ���� �Լ�
****************************************************************/
void userTitle(char* id){
	int key;
	curX=22;
	curY=10;
	while(1){
		system("cls");
		usermenu();
		gotoxy(curX,curY);
		printf("��");
		key = get3MenuSelect();
		if(key == -1){
			curX=20;		curY=18;
			break;
		}
		if(key!=0){
			switch(key-9){
				showCursor();
				case 1:
					//����
					system("cls");
					reserveTitle(id);
					curX=22;
					curY=10;					
					break;
				case 2:
					//Ȯ��
					system("cls");
					findReserve(id);
					curX=22;
					curY=11;					
					break;
				case 3:
					//���� ����
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
