#include "manager.h"



/***************************************************************
	�Ű����� : ����
	���	    : ������ �޴� Print
****************************************************************/
void managerMenu(){
	printf("\n\n");
	printf("\t������������������������������������������������\n");
	printf("\t��                                            �� \n");
	printf("\t��                                            ��\n");
	printf("\t��                ������  ����                ��\n");
	printf("\t��                                            ��\n");
	printf("\t��                                            ��\n");
	printf("\t��                                            ��\n");
	printf("\t��              1. ����� ����                ��\n");
	printf("\t��              2. ���� �߰�/��ȸ             ��\n");
	printf("\t��                                            ��\n");
	printf("\t��                                            ��\n");
	printf("\t��                                            ��\n");
	printf("\t��                                            ��\n");
	printf("\t��                                            ��\n");
	printf("\t��                                            ��\n");
	printf("\t������������������������������������������������\n");
}


/***************************************************************
	�Ű����� : ����
	���	    : ������ ���� �Լ�
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
		printf("��");
		key = get2MenuSelect();
		if(key == -1){
			curX=20;		curY=18;
			break;
		}
		if(key!=0){
			switch(key-9){
				case 1:
					//����ڰ���
					system("cls");
					printf("���̵� �Է����ּ��� : ");
					scanf("%s",id);
					findReserve(id);
					getchar();
					getchar();
					curX=22;
					curY=10;
					break;
				case 2:
					//�����߰�/��ȸ
					system("cls");
					trainTitle();
					curX=22;
					curY=10;
					break;
			}
		}
	
	}
}
