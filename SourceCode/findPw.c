#include "findPw.h"

/***************************************************************
	�Ű����� : ����
	���	    : �н����� �ۼ� �޴� Print
****************************************************************/
void findPwMenu()
{
   printf("\n\n");
   printf("\t������������������������������������������������\n");
   printf("\t��                                            �� \n");
   printf("\t��                                            ��\n");
   printf("\t��                                            ��\n");
   printf("\t��                ��й�ȣ ã��               ��\n");
   printf("\t��                                            ��\n");
   printf("\t��                                            ��\n");
   printf("\t��             ID:                            ��\n");
   printf("\t��                                            ��\n");
   printf("\t��           �̸�:                            ��\n");
   printf("\t��                                            ��\n");
   printf("\t��             HP:                            ��\n");
   printf("\t��                                            ��\n");
   printf("\t��                                            ��\n");
   printf("\t��                                            ��\n");
   printf("\t��                                            ��\n");
   printf("\t��                                            ��\n");
   printf("\t��                                            ��\n");
   printf("\t������������������������������������������������\n");
}


/***************************************************************
	�Ű����� : ���̵�, �̸�, ��ȭ��ȣ
	���	    : �Ű������� ���� ������ �´��� Ȯ���ϴ� �Լ�.
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
		fscanf(fp,"%s",&checkpw);	//�ϴ� �н����� �޾Ƴ���
		fscanf(fp,"%s",&checkName);
		fscanf(fp,"%s",&checkPhone);
			//���̵� �̸� ���ѹ� �������
			if(strcmp(checkid,id) == 0 && strcmp(checkName,name) == 0 && strcmp(checkPhone,phone) == 0){
							yellowtext();
							gotoxy(22,17);
							printf("�� Your PassWord ��%s",checkpw);
							showtext();
							Sleep(3000);
							break;
					}
			else if(strcmp(checkid,id) == 0){	//���̵� �������
				if(strcmp(checkName,name) != 0 && strcmp(checkPhone,phone)==0){	//�̸��� �ٸ����
							warntext();
							gotoxy(22,17);
							printf("�� �̸��� �߸� �Է��ϼ̽��ϴ�.");
							showtext();
							Sleep(3000);
							break;
				}
				else if(strcmp(checkName,name) == 0 && strcmp(checkPhone,phone)!=0){	//��ȭ��ȣ�� �ٸ����
							warntext();
							gotoxy(22,17);
							printf("����ȭ��ȣ�� �߸� �Է��ϼ̽��ϴ�.");
							showtext();
							Sleep(3000);
							break;
				}
				else{//�Ѵ�Ʋ�����
							warntext();
							gotoxy(15,17);
							printf("���̸��� ��ȭ��ȣ�� �߸� �Է��ϼ̽��ϴ�.");
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
	�Ű����� : ����
	���	    : �н����� ã�� ���� �Լ�
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
			printf("ã�� ���̵� ���������ʽ��ϴ�!\n");
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
