#include"login.h"


/***************************************************************
	�Ű����� : ����
	���	    : �α��� �ۼ� �޴� Print
****************************************************************/
void loginMenu()
{
	//�α���
   printf("\n\n");
   printf("\t������������������������������������������������\n");
   printf("\t��                                            �� \n");
   printf("\t��                                            ��\n");
   printf("\t��                                            ��\n");
   printf("\t��                   Login                    ��\n");
   printf("\t��                                            ��\n");
   printf("\t��                                            ��\n");
   printf("\t��              ID:                           ��\n");
   printf("\t��                                            ��\n");
   printf("\t��              PW:                           ��\n");
   printf("\t��                                            ��\n");
   printf("\t��                                            ��\n");
   printf("\t��                                            ��\n");
   printf("\t��                                            ��\n");
   printf("\t��                                            ��\n");
   printf("\t������������������������������������������������\n");
}




/***************************************************************
	�Ű����� : ���̵�, �н�����
	���	    : �α��� üũ(���̵�� �н����尡 �´���)
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
		//���̵������
		if(strcmp(checkid,id) == 0){
			fscanf(fp,"%s",&checkpw);
			//�н����尰�����
			if(strcmp(checkpw,pw) == 0)	return 1;
			else{
				warntext();
				gotoxy(22,17);
				printf("�н����尡 Ʋ���ϴ�.\n");
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
	printf("�Է��� ���̵� �����ϴ�.\n");
	showtext();
	Sleep(950);
	fclose(fp);
	return 0;	
}




/***************************************************************
	�Ű����� : ����
	���	    : �α��� ���� �Լ�
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
		//������
		makeStation();
		//������
		if(strcmp(id ,"root") == 0){
			manager();
		}
		//�Ϲݷα���
		else
			userTitle(id);
	}
}
