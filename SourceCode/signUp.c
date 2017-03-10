#include "signUp.h"



/***************************************************************
	�Ű����� : ����
	���	    : ȸ������ �޴� Print
****************************************************************/
void signUp(){
   printf("\n\n");
   printf("\t������������������������������������������������\n");
   printf("\t��                                            �� \n");
   printf("\t��                   ȸ������                 ��\n");
   printf("\t��                                            ��\n");
   printf("\t��             ���������� �Է��Ͻÿ�.         ��\n");
   printf("\t��                                            ��\n");
   printf("\t��            ���̵�:                         ��\n");
   printf("\t��          ��й�ȣ:                         ��\n");
   printf("\t��          ��й�ȣ:                         ��\n");
   printf("\t��              �̸�:                         ��\n");
   printf("\t��              ����:                         ��\n");
   printf("\t��              ����:                         ��\n");
   printf("\t��          (��/�� �� �����Է��Ͻÿ�)         ��\n");
   printf("\t��            ����ó:                         ��\n");
   printf("\t��                                            ��\n");
   printf("\t������������������������������������������������\n");

}


/***************************************************************
	�Ű����� : ȸ������ ����ü
	���	    : ID �ۼ� ����ó��
****************************************************************/
int getId(Person *p){
	FILE *fp = fopen("Person.txt","r");
	int i=0;
	char tmpId[12];
	if(fp == NULL){
		printf("Error Open File\n");
		exit(1);
	}

	//���̵� �Է�
	system("cls");
	signUp();
	gotoxy(30,9);
	gets(p->id);
	if(strlen(p->id) == 0){
				warntext();
				gotoxy(10,19);
				printf("�ʼ��Է� �����̹Ƿ� �ٽ� �Է����ּ���.");
				showtext();
				Sleep(1000);
				return 0;
	}

	if(strlen(p->id) < 5 || strlen(p->id) > 10){
		warntext();
		gotoxy(10,19);
		printf("���̵�� ���� 5~10 �ڸ� , �ѱ� 3~5�ڸ��� �Է����ּ���.\n");
		showtext();
		Sleep(1000);
		return 0;
	}


	while(!feof(fp)){
		fscanf(fp,"%s",tmpId);
		if(strcmp(p->id,tmpId) == 0){
			warntext();
			gotoxy(22,17);
			printf("���� ���̵� �����մϴ�!\n");
			showtext();
			Sleep(750);
			return 0;
		}
		else{
			for(i=0; i<6; i++)
				fscanf(fp,"%s",tmpId);
		}
	}
	
	
	fclose(fp);
	return 1;
}


/***************************************************************
	�Ű����� : ȸ������ ����ü
	���	    : PW �ۼ� ����ó��
****************************************************************/
int getPw(Person *p){
	char tmpPw[15];//��й�ȣ ��Ȯ���� ���� tmp

	//�޴����
	system("cls");
	signUp();
	gotoxy(30,9);
	printf("%s",p->id);	
	//��й�ȣ�Է�
	gotoxy(30,10);
	hidetext();
	gets(p->pw);

	if(strlen(p->pw) > 10 || strlen(p->pw) < 5){
		warntext();
		gotoxy(18,17);
		printf("��й�ȣ�� 5~10�ڸ� �Է��ϼ���!\n");
		showtext();
		Sleep(750);
		return 0;
	}
	//��й�ȣȮ��
	gotoxy(30,11);
	gets(tmpPw);
	showtext(); // �Է��� ������ ���� ������ ����
	
	if( strcmp(tmpPw,p->pw) != 0){
		warntext();
		gotoxy(18,17);
		printf("��й�ȣ�� �ٸ��ϴ�!\n");
		showtext();
		Sleep(750);
		return 0;
	}
	return 1;
}


/***************************************************************
	�Ű����� : ȸ������ ����ü
	���	    : �̸� �ۼ� ����ó��
****************************************************************/
int getName(Person *p){
	system("cls");
	signUp();
	gotoxy(30,9);
	printf("%s",p->id);	
	gotoxy(30,10);
	hidetext();
	printf("%s", p->pw);
	gotoxy(30,11);
	printf("%s", p->pw);
	showtext();
	gotoxy(30,12);
	//�̸��Է�
	gets(p->name);
	if(strlen(p->name) == 0){
		warntext();
		gotoxy(10,19);
		printf("�ʼ��Է� �����̹Ƿ� �ٽ� �Է����ּ���.");
		showtext();
		Sleep(1000);
		return 0;
	}
	if(strlen(p->name) > 10){
		warntext();
		gotoxy(18,17);
		printf("�̸��� 5�����Ϸ� �Է��ϼ���!\n");
		showtext();
		Sleep(750);
		return 0;
	}
	return 1;
}



/***************************************************************
	�Ű����� : ȸ������ ����ü
	���	    : ���� �ۼ� ����ó��
****************************************************************/
int getAge(Person *p){
	system("cls");
	signUp();
	gotoxy(30,9);
	printf("%s",p->id);	
	gotoxy(30,10);
	hidetext();
	printf("%s", p->pw);
	gotoxy(30,11);
	printf("%s", p->pw);
	showtext();
	gotoxy(30,12);
	printf("%s", p->name);
	//���� �Է�
	gotoxy(30,13);
	scanf("%d", &p->age);
	if(p->age < 0 || p->age >100){
		warntext();
		gotoxy(15,17);
		printf("���̴� 0~100������ �Է����ּ���!\n");
		showtext();
		Sleep(750);
		return 0;
	}
	return 1;
}



/***************************************************************
	�Ű����� : ȸ������ ����ü
	���	    : ���� �ۼ� ����ó��
****************************************************************/
int getGender(Person *p){
	system("cls");
	fflush(stdin);
	signUp();
	gotoxy(30,9);
	printf("%s",p->id);	
	gotoxy(30,10);
	hidetext();
	printf("%s", p->pw);
	gotoxy(30,11);
	printf("%s", p->pw);
	showtext();
	gotoxy(30,12);
	printf("%s", p->name);
	gotoxy(30,13);
	printf("%d", p->age);
	gotoxy(30,14);
	gets(p->gender);
	if(strlen(p->gender) == 0){
		warntext();
		gotoxy(10,19);
		printf("�ʼ��Է� �����̹Ƿ� �ٽ� �Է����ּ���.");
		showtext();
		Sleep(1000);
		return 0;	
	}
	if(strcmp(p->gender,"��") !=0 && strcmp(p->gender,"��") != 0){
		warntext();
		gotoxy(15,17);
		printf("������ '��','��'�� �Է����ּ���!\n");
		showtext();
		Sleep(750);
		return 0;
	}
	
	return 1;
}



/***************************************************************
	�Ű����� : ȸ������ ����ü
	���	    : ��ȭ��ȣ �ۼ� ����ó��
****************************************************************/
int getPhonNum(Person *p){
	int key=0;
	int i=0;
	system("cls");
	signUp();
	gotoxy(30,9);
	printf("%s",p->id);	
	gotoxy(30,10);
	hidetext();
	printf("%s", p->pw);
	gotoxy(30,11);
	printf("%s", p->pw);
	showtext();
	gotoxy(30,12);
	printf("%s", p->name);
	gotoxy(30,13);
	printf("%d", p->age);
	gotoxy(30,14);
	printf("%s",p->gender);
	gotoxy(30,16);
	gets(p->phone);
	for(i=0; i<strlen(p->phone); i++){
		if(p->phone[i]<48 || p->phone[i]>57)
			key = 1;
	}
	if(strlen(p->phone) == 0){
		warntext();
		gotoxy(10,19);
		printf("�ʼ��Է� �����̹Ƿ� �ٽ� �Է����ּ���.");
		showtext();
		Sleep(1000);
		return 0;
	}
	if((strlen(p->phone) > 11 || strlen(p->phone) < 7) || key == 1 ){
		warntext();
		gotoxy(15,17);
		printf("���ڷθ� 7~11�ڸ��� �Է��ϼ���!\n");
		showtext();
		Sleep(750);
		return 0;
	}
	return 1;
}



/***************************************************************
	�Ű����� : ȸ������ ����ü
	���	    : Person.txt�� ����
****************************************************************/
void inputPerson(Person *p){
	FILE *fp = fopen("Person.txt","a");
	p->mileage =0;
	if(fp == NULL){
		printf("Error Open File\n");
		exit(1);
	}
	fprintf(fp,"%s\n",p->id);
	fprintf(fp,"%s\n",p->pw);
	fprintf(fp,"%s\n",p->name);
	fprintf(fp,"%s\n",p->phone);
	fprintf(fp,"%d\n",p->age);
	fprintf(fp,"%s\n",p->gender);
	fprintf(fp,"%d\n\n",p->mileage);
	
	fclose(fp);
}
