#include "reserve.h"

/***************************************************************
	�Ű����� : ����
	���	    : ���� �� Print
****************************************************************/
void load(){
	int i=0;
	 printf("\n\n");
   printf("\t������������������������������������������������\n");
   printf("\t��                                            �� \n");
   printf("\t��                                            ��\n");
    printf("\t��                                            ��\n");
    printf("\t��                                            ��\n");
   printf("\t��                                            ��\n");
   printf("\t��                  ������                    ��\n");
   printf("\t��                                            ��\n");
   printf("\t��\t ��������������������������\t      ��\n");
   printf("\t��\t ��                      ��\t      ��\n");
   printf("\t��\t ��������������������������\t      ��\n");
   printf("\t��                                            ��\n");
   printf("\t��                                            ��\n");
   printf("\t��                                            ��\n");
   printf("\t��                                            ��\n");
   printf("\t��                                            ��\n");
   printf("\t��                                            ��\n");
   printf("\t��                                            ��\n");
   printf("\t������������������������������������������������\n");
   for(i=20;i<40;i++){
	gotoxy(i,12);
	printf(">>");
	Sleep(150);
   }
}


/***************************************************************
	�Ű����� : ����
	���	    : ���� �Ϸ� Print
****************************************************************/
void load2(){
	 printf("\n\n");
   printf("\t������������������������������������������������\n");
   printf("\t��                                            �� \n");
   printf("\t��                                            ��\n");
   printf("\t��                                            ��\n");
   printf("\t��                                            ��\n");
   printf("\t��                                            ��\n");
   printf("\t��                                            ��\n");
   printf("\t��           ������ �Ϸ� �Ǿ����ϴ�.          ��\n");
   printf("\t��                                            ��\n");
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
	���	    : ����/ȯ�� Print
****************************************************************/
void selectMenu()
{
   printf("\n\n");
   printf("\t������������������������������������������������\n");
   printf("\t��                                            �� \n");
   printf("\t��                                            ��\n");
   printf("\t��                                            ��\n");
   printf("\t��                 ����/ȯ��                  ��\n");
   printf("\t��                                            ��\n");
   printf("\t��                                            ��\n");
   printf("\t��                 1. ����                    ��\n");
   printf("\t��                 2. ȯ��                    ��\n");
   printf("\t��                                            ��\n");
   printf("\t��                                            ��\n");
   printf("\t��                                            ��\n");
   printf("\t��                                            ��\n");
   printf("\t��                                            ��\n");
   printf("\t��                                            ��\n");
   printf("\t������������������������������������������������\n");
}


/***************************************************************
	�Ű����� : ���Ḯ��Ʈ ���������, ���Ḯ��Ʈ ������, ������ȣ, ��߽ð�, �����ð�, ���, ��������, ��߿�, ������
	���	    :  ���Ḯ��Ʈ�� �������� ����
****************************************************************/
void insert_node(List **phead, List *p, int trainNum, int st_time , int dt_time,int pay,char trainClass[],char startSt[], char destSt[]){
	List *tmp = (List *) malloc(sizeof(List));
	if( tmp == NULL){
		printf("Error Allocate Memory");
		exit(1);
	}
	tmp->data.trainNum = trainNum;
	tmp->data.st_time = st_time;
	tmp->data.dt_time = dt_time;
	tmp->data.pay = pay;
	strcpy(tmp->data.trainClass,trainClass);
	strcpy(tmp->data.startSt,startSt);
	strcpy(tmp->data.destSt,destSt);
	if(*phead == NULL){
		tmp->link = NULL;
		*phead = tmp;
	}
	else{
		tmp->link = p->link;
		p->link = tmp;
	}
}


/***************************************************************
	�Ű����� : ����
	���	    :  ���� ������ �������� Print
****************************************************************/
void ShowList(){
	printf("\n\n");
	printf("\t  ������ȣ    |     ��������    |    ���    |    ��߽ð�    |    ����    |    �����ð�    |    ���ӿ��  \n");
	printf("\t---------------------------------------------------------------------------------------------------------\n");
}

/***************************************************************
	�Ű����� : ����
	���	    : ������ �������� Print
****************************************************************/
void ShowReserve(){
	printf("\n\n");
	printf("\t  ��߳�¥ |   ������ȣ   |   ���    |    ��߽ð�     |    ����    |    �����ð�    |    ���ӿ��   |  ȣ��  |  �¼� \n");
	printf("\t----------------------------------------------------------------------------------------------------------------------\n");
}

/***************************************************************
	�Ű����� : ����
	���	    : ���������� �Է��� �޴� Print
****************************************************************/
void reserveMenu(){
   printf("\n\n");
   printf("\t������������������������������������������������\n");
   printf("\t��                                            �� \n");
   printf("\t��                                            ��\n");
   printf("\t��                                            ��\n");
   printf("\t��           ���������� �Է����ּ���          ��\n");
   printf("\t��                                            ��\n");
   printf("\t��        ��߳�¥  :	                      ��\n");   
   printf("\t��        ��߿�    :                         ��\n");
   printf("\t��        ������    :                         ��\n");
   printf("\t��        �ο�      :                         ��\n");
   printf("\t��                                            ��\n");
   printf("\t��                                            ��\n");
   printf("\t��                                            ��\n");
   printf("\t��                                            ��\n");
   printf("\t��                                            ��\n");
   printf("\t��                                            ��\n");
   printf("\t��                                            ��\n");
   printf("\t��                                            ��\n");
   printf("\t�� ���� TIP                                   ��\n");
   printf("\t��1. ��߳�¥�� ex(2015��1��1��->150101 �Է�) ��\n");
   printf("\t��2. ���,�������� ex(���￪ -> ���� �Է�)    ��\n");
   printf("\t��3. �ο��� 1~9 ������ �ϳ��� ���� �Է�       ��\n");
   printf("\t������������������������������������������������\n");
}

/***************************************************************
	�Ű����� : ����
	���	    : ��߿� ����ó��
****************************************************************/
char* CheckstartSt(){
	char startSt[11];
	int i=0,cnt=0;

	while(1){
		gotoxy(31,10);	
		gets(startSt);
		for(i=0; i<50; i++){
			if(strcmp(st[i][0].k.startSt,startSt) ==0)
				cnt++;
		}
		if(cnt == 1)
			break;
		else{
			warntext();
			gotoxy(20,17);
			printf("���� ���������ʽ��ϴ�!\n");
			showtext();
			Sleep(750);
			gotoxy(20,17);
			printf("                      ");
			gotoxy(31,10);
			printf("                   ");
		}
	}
	return startSt;
}

/***************************************************************
	�Ű����� : ��߿�
	���	    : ������ ����ó��
****************************************************************/
char* CheckdestSt(char* startSt){
	char destSt[11];
	int i=0,cnt=0;

	while(1){
		gotoxy(31,11);	
		gets(destSt);
		if(strcmp(startSt,destSt) == 0){
			warntext();
			gotoxy(20,17);
			printf("��߿��� �������� �Ȱ����ϴ�!\n");
			showtext();
			Sleep(750);
			gotoxy(20,17);
			printf("                              ");
			gotoxy(31,11);
			printf("                   ");
		}
		else{
			for(i=0; i<50; i++){
				if(strcmp(st[i][0].k.startSt,destSt) ==0)
					cnt++;
			}
			if(cnt == 1)
				break;
			else{
				warntext();
				gotoxy(20,17);
				printf("���� ���������ʽ��ϴ�!\n");
				showtext();
				Sleep(750);
				gotoxy(20,17);
				printf("                      ");
				gotoxy(31,11);
				printf("                   ");
			}
		}
	}
	return destSt;
}	

/***************************************************************
	�Ű����� : ��߿�,������
	���	    : �Ű������� �����ϴ� ���� Print �� ���� ������ �ް�
				  �¼� Print �� �¼� ������ �ް�
				  ���������� �������� ����ü�� �ۼ� �� ������������ü Return
****************************************************************/
bookData makeReserve(char startSt[],char destSt[]){
	FILE *fp = fopen("Train.txt","r");
	FILE *fp2 = fopen("TrainRoute.txt","r");
	char trainName[11];	//����������
	char trainClass[11];	//��������
	char trainNum[11];			//������ȣ
	char size[5];				//��Ʈ����
	char start[11];			//Train.txt ��߿�
	char transfer[11];		//ȯ�¿�
	char dest[11];			//Train.txt ������
	char temp[11];
	char hour[5],min[5];
	int key;
	int i,j,k,cnt=0;		
	int stSum=0;	//	��߽ð� ����
	int pay=0;		//	������
	int st_hNum,st_mNum;		//��� �ð�/������
	int dt_hNum,dt_mNum;		//���� �ð�/������
	int stIndex,dtIndex;			//��� ���� ȯ�� �ε���
	int f1_index,f2_index;		//���������� ��ġ.
	int r_index;
	List *directData = NULL;	
	List *sttrData = NULL;
	List *trdtData = NULL;
	List *h,*p;
	bookData reserve;
	if(fp == NULL || fp2== NULL){
		printf("ERROR FILE OPEN");
		exit(1);
	}
	
	while(!feof(fp) && !feof(fp2)){	
		fscanf(fp,"%s",temp);
		fscanf(fp2,"%s",trainNum);
		fscanf(fp2,"%s",size);
		stSum =	pay = st_hNum = st_mNum = dt_hNum = dt_mNum = 0;
		r_index = ftell(fp2);
		for(i=0,cnt = 0; i<atoi(size); i++){
			fscanf(fp2,"%s",trainName);
			if(strcmp(trainName,startSt) == 0 && cnt==0){	//�������� üũ�ȵȻ��¿��� ��߿� ��
				cnt++;
				stIndex = i;
			}
			else if(cnt ==1 && strcmp(trainName,destSt) == 0){	//��߿�üũ�ǰ� ������ ��
				cnt++;
				dtIndex = i;
			}
		}
		f2_index = ftell(fp2);
		if(cnt == 2){	//����Ver
				fscanf(fp,"%s",trainClass);
				fscanf(fp,"%s",start);
				fscanf(fp,"%s",dest);
				fscanf(fp,"%s",hour);
				fscanf(fp,"%s",min);			

				stSum += atoi(hour)*60;
				stSum += atoi(min);
				//��߽ð����
				if(strcmp(startSt,start) != 0){	//���� ��߿��� �Է���߿��� �ٸ���
					for(i=0; i<50; i++){
						for(j=0; j<50; j++){
							if(strcmp(st[i][j].k.startSt,start) == 0 && strcmp(st[i][j].k.destSt,startSt) == 0){
								if(strcmp("KTX",trainClass) == 0){	//KTX ��� �ð����ϱ�
									stSum += st[i][j].k.time + stIndex*5;		//�����ð� 5���߰�								
								}
								else{										//����ȭ ��� �ð����ϱ�
									stSum += st[i][j].m.time + stIndex*5;								
								}
							}
						}
					}					
				}
				
				
				st_hNum = stSum / 60;
				st_mNum = stSum % 60;
				
				//�����ð����
				for(i=0; i<50; i++){
					for(j=0; j<50; j++){
						if(strcmp(st[i][j].k.startSt,startSt) == 0 && strcmp(st[i][j].k.destSt,destSt) == 0){
							if(strcmp("KTX",trainClass) == 0){	//KTX ��� �ð����ϱ�
								stSum += st[i][j].k.time;
								pay  += st[i][j].k.pay; 
							}
							else{										//����ȭ ��� �ð����ϱ�
								stSum += st[i][j].m.time;
								pay += st[i][j].m.pay;
							}
						}
					}
				}				
			
				dt_hNum = (stSum+((dtIndex-1)*5)) / 60;
				dt_mNum = (stSum+((dtIndex-1)*5)) % 60;
				
				insert_node(&directData , directData , atoi(trainNum) , st_hNum*60+st_mNum , dt_hNum*60+dt_mNum , pay, trainClass ,startSt , destSt );	//���Ḯ��Ʈ�� ������ �Է�.
		}
		else if(cnt == 1){//ȯ��Ver
				fscanf(fp,"%s",trainClass);
				fscanf(fp,"%s",start);
				fscanf(fp,"%s",dest);
				fscanf(fp,"%s",hour);
				fscanf(fp,"%s",min);
				f1_index = ftell(fp);		//���ư� FILE FP ����

				stSum += atoi(hour)*60;
				stSum += atoi(min);
				//��߽ð����
				if(strcmp(startSt,start) != 0){	//���� ��߿��� �Է���߿��� �ٸ���
					for(i=0; i<50; i++){
						for(j=0; j<50; j++){
							if(strcmp(st[i][j].k.startSt,start) == 0 && strcmp(st[i][j].k.destSt,startSt) == 0){
								if(strcmp("KTX",trainClass) == 0){	//KTX ��� �ð����ϱ�
									stSum += st[i][j].k.time + stIndex*5;		//�����ð� 5���߰�						
								}
								else{										//����ȭ ��� �ð����ϱ�
									stSum += st[i][j].m.time + stIndex*5;									
								}
							}
						}
					}					
				}
				
				st_hNum = stSum / 60;
				st_mNum = stSum % 60;
				

				//ȯ�¿��ޱ�
				fseek(fp2,r_index,SEEK_SET);	//���� ������ ��Ʈ ó������ �̵�;
				fscanf(fp2,"%s",transfer);
				for(i=0; i<stIndex; i++)		//��߿����� �̵�.
					fscanf(fp2,"%s",transfer);
				for(k=stIndex; k<atoi(size)-1; k++){		//��߿������� ������ ��� ȯ�¿����� �����Ͽ� �ִ´�.
					fscanf(fp2,"%s",transfer);
					//ȯ�¿������ð����
					stSum= st_hNum * 60 + st_mNum;
					pay = dt_hNum = dt_mNum = 0;
					for(i=0; i<50; i++){
						for(j=0; j<50; j++){
							if(strcmp(st[i][j].k.startSt,startSt) == 0 && strcmp(st[i][j].k.destSt,transfer) == 0){
								if(strcmp("KTX",trainClass) == 0){	//KTX ��� �ð����ϱ�
									stSum += st[i][j].k.time;
									pay  += st[i][j].k.pay; 
								}
								else{										//����ȭ ��� �ð����ϱ�
									stSum += st[i][j].m.time;
									pay += st[i][j].m.pay;
								}
							}
						}
					}

					
					dt_hNum = (stSum+(k*5)) / 60;
					dt_mNum = (stSum+(k*5)) % 60;

					
					insert_node(&sttrData , sttrData , atoi(trainNum) , st_hNum*60+st_mNum , dt_hNum*60+dt_mNum , pay, trainClass ,startSt , transfer );	//���Ḯ��Ʈ�� ������ �Է�.
				}
				fseek(fp,0,SEEK_SET);//ó������ �̵�.
				fseek(fp2,0,SEEK_SET);	//ó������ �̵�.
				
				while(!feof(fp2) && !feof(fp)){
					fscanf(fp2,"%s",trainNum);
					fscanf(fp2,"%s",size);
					fscanf(fp,"%s",temp);
					fscanf(fp,"%s",trainClass);
					fscanf(fp,"%s",start);
					fscanf(fp,"%s",dest);
					fscanf(fp,"%s",hour);
					fscanf(fp,"%s",min);
					r_index = ftell(fp2);
					
					h = sttrData;
					while(h != NULL){	//ȯ�¿� ã��.
						cnt = stSum =	pay = st_hNum = st_mNum = dt_hNum = dt_mNum = stIndex = dtIndex=0;
						fseek(fp2,r_index,SEEK_SET);		//��Ʈó������ �̵�
						for(i=0; i<atoi(size); i++){								
							fscanf(fp2,"%s",trainName);	//��Ʈ ���̸� ��������
							if(strcmp(trainName,h->data.destSt) == 0 && cnt==0){	//�������� üũ�ȵȻ��¿��� ȯ�¿� ��
								cnt++;
								stIndex = i;								
							}
							else if(cnt ==1 && strcmp(trainName,destSt) == 0){	//������ ã��.
								cnt++;
								dtIndex = i;
							}
						}
						if(cnt == 2){	//ȯ�� && ������ ����
							stSum += atoi(hour)*60;
							stSum += atoi(min);
							//ȯ����߽ð����
							if(strcmp(h->data.destSt,start) != 0){	//���� ��߿��� ȯ�¿��� �ٸ���
								for(i=0; i<50; i++){
									for(j=0; j<50; j++){
										if(strcmp(st[i][j].k.startSt,start) == 0 && strcmp(st[i][j].k.destSt,h->data.destSt) == 0){
											if(strcmp("KTX",trainClass) == 0){	//KTX ��� �ð����ϱ�
												stSum += st[i][j].k.time + stIndex*5;		//�����ð� 5���߰�			
											}
											else{										//����ȭ ��� �ð����ϱ�
												stSum += st[i][j].m.time + stIndex*5;												
											}
										}
									}
								}					
							}


							st_hNum = stSum / 60;
							st_mNum = stSum % 60;

							
							//ȯ�µ����ð����
							for(i=0; i<50; i++){
								for(j=0; j<50; j++){
									if(strcmp(st[i][j].k.startSt,h->data.destSt) == 0 && strcmp(st[i][j].k.destSt,destSt) == 0){		//ȯ�¿��� ������ ��Ʈ.
										if(strcmp("KTX",trainClass) == 0){	//KTX ��� �ð����ϱ�
											stSum += st[i][j].k.time;
											pay  += st[i][j].k.pay; 
										}
										else{										//����ȭ ��� �ð����ϱ�
											stSum += st[i][j].m.time;
											pay += st[i][j].m.pay;
										}
									}
								}
							}

							
							dt_hNum = (stSum+((dtIndex-stIndex-1)*5)) / 60;
							dt_mNum = (stSum+((dtIndex-stIndex-1)*5)) % 60;
							
							p = trdtData; 
							while(p != NULL){
								if((p->data.st_time ==  st_hNum*60+st_mNum) && strcmp(p->data.startSt,h->data.destSt) == 0  )	//�ߺ�check
									break;
								p = p->link;
							}
							if(p == NULL){
								insert_node(&trdtData , trdtData , atoi(trainNum) , st_hNum*60+st_mNum , dt_hNum*60+dt_mNum , pay, trainClass ,h->data.destSt , destSt );	//���Ḯ��Ʈ�� ������ �Է�.				
							}
						}
						h = h->link;
					}



				}
				//���ƿ���
				fseek(fp,f1_index,SEEK_SET);
				fseek(fp2,f2_index,SEEK_SET);				
			}
		

		else{//��߿��� �������� �ʴ´�.
				for(i=0; i<5; i++)
					fscanf(fp,"%s",temp);
		}
	}
	curX=25;
	curY=10;
	hideCursor();
	while(1){
		system("cls");
		
		selectMenu();
		key = get2MenuSelect();
		if(key == -1){
			curX=25;		curY=10;
			reserve.check = -1;
			break;
		}
		if(key != 0){
			switch(key-9){
			case 1://����				
				system("cls");
				ShowList();
				h = directData;
				while(h != NULL){
					printf("%15d%20s%15s ",h->data.trainNum,h->data.trainClass,h->data.startSt);
					printf("%10d:%2d\t%7s ",(h->data.st_time / 60) , h->data.st_time % 60 , h->data.destSt);
					if( h->data.dt_time/60 > 24)
						printf("%10d:%2d %15d\n", h->data.dt_time/60-24, h->data.dt_time%60,h->data.pay);
					else
						printf("%10d:%2d %15d\n", h->data.dt_time/60, h->data.dt_time%60,h->data.pay);
					h = h->link;
				}
				gotoxy(125,9);
				printf("���Ͻô� ������ �Է��ϼ���\n");
				gotoxy(125,10);
				warntext();
				printf("�����÷��� exit�� �Է��ϼ���\n");
				showtext();
				gotoxy(125,11);
				printf("�� ");
				gotoxy(128, 11);
				showCursor();

Reselect:
				h = directData;
				cnt=0;
				scanf("%s",trainNum);
				hideCursor();
				if(strcmp(trainNum,"exit")==0) break;
				while(h != NULL){
					if(atoi(trainNum) == h->data.trainNum){
						strcpy(reserve.st_trainNum ,trainNum);	//���������� ������ȣ �Է�
						strcpy(reserve.startSt,startSt);	//���������� ��߿� �Է�
						reserve.st_hNum = (h->data.st_time/60 > 24) ? (h->data.st_time/60 - 24) : (h->data.st_time/60) ;	//���������� ��߽ð� �Է�
						reserve.st_mNum = h->data.st_time%60;	//���������� ��ߺ� �Է�

						strcpy(reserve.destSt,destSt);		//���������� ������ �Է�
						reserve.dt_hNum = h->data.dt_time/60;	//���������� �����ð� �Է�
						reserve.dt_mNum = h->data.dt_time%60;	//���������� ������ �Է�	
						reserve.pay = h->data.pay;				//���������� ��� �Է�

						cnt++;
					}
					h= h->link;
				}
				if(cnt == 0){
					warntext();
					gotoxy(125, 13);
					printf("�Է��Ͻ� ��ȣ�� ��ũ���� �����ϴ�.");
					Sleep(750);
					gotoxy(125, 13);
					printf("                                              ");
					showtext();
					gotoxy(128, 11);
					printf("                                   ");
					gotoxy(128, 11);
					goto Reselect;
				}
				
				

				return reserve;
				break;
				
			case 2:	//ȯ���Է�
				//ȯ�����
				system("cls");
				ShowList();
				p = trdtData; 
				while(p != NULL){
					h = sttrData;
					while(h != NULL){
						if(strcmp(p->data.startSt,h->data.destSt) == 0 && h->data.dt_time < p->data.st_time){
							if(h->data.dt_time/60 > 24)
								printf("%15d%20s%15s %10d:%2d\t%7s %10d:%2d %15d\n",h->data.trainNum,h->data.trainClass,h->data.startSt,h->data.st_time / 60 , h->data.st_time % 60 , h->data.destSt, h->data.dt_time/60-24, h->data.dt_time%60,h->data.pay);
							else
								printf("%15d%20s%15s %10d:%2d\t%7s %10d:%2d %15d\n",h->data.trainNum,h->data.trainClass,h->data.startSt,h->data.st_time / 60 , h->data.st_time % 60 , h->data.destSt, h->data.dt_time/60, h->data.dt_time%60,h->data.pay);
							if(p->data.dt_time/60 > 24)
								printf("%15d%20s%15s %10d:%2d\t%7s %10d:%2d %15d\n",p->data.trainNum,p->data.trainClass,p->data.startSt,p->data.st_time / 60 , p->data.st_time % 60 , p->data.destSt, p->data.dt_time/60-24, p->data.dt_time%60,p->data.pay);
							else
								printf("%15d%20s%15s %10d:%2d\t%7s %10d:%2d %15d\n",p->data.trainNum,p->data.trainClass,p->data.startSt,p->data.st_time / 60 , p->data.st_time % 60 , p->data.destSt, p->data.dt_time/60, p->data.dt_time%60,p->data.pay);
							yellowtext();
							printf("\t\t\t\t\t\t\t\t\t\t\t    Total Pay = %d\n\n",h->data.pay+p->data.pay);
							showtext();
						}
						h = h->link;
					}
					p = p->link;
				}
				gotoxy(125,9);
				printf("���Ͻô� ������ �Է��ϼ���\n");
				gotoxy(125,10);
				warntext();
				printf("�����÷��� exit�� �Է��ϼ���\n");
				showtext();
				gotoxy(125,11);
				printf("�� ");
				gotoxy(128, 11);
				showCursor();

Reselect2:		//��߿��� �Է�
				h = sttrData;				
				cnt=0;
				scanf("%s",trainNum);
				hideCursor();
				if(strcmp(trainNum,"exit")==0) break;
				while(h != NULL){
					if(atoi(trainNum) == h->data.trainNum){		
						cnt++;
					}
					h= h->link;
				}
				if(cnt == 0){
					warntext();
					gotoxy(125, 17);
					printf("�Է��Ͻ� ��ȣ�� ��ũ���� �����ϴ�.");
					Sleep(750);
					gotoxy(125, 17);
					printf("                                              ");
					showtext();
					gotoxy(128, 11);
					printf("                                   ");
					gotoxy(128, 11);
					goto Reselect2;
				}
				gotoxy(125,12);
				printf("���Ͻô� ȯ�¿��� �Է��ϼ���\n");
				gotoxy(125,13);
				printf("�� ");
				gotoxy(128, 13);


Reselect3:		//ȯ�¿� �Է�
				h = trdtData;				
				cnt=0;
				scanf("%s",trainName);
				while(h != NULL){
					if(strcmp(trainName,h->data.startSt)==0)
						cnt++;
					h= h->link;
				}
				if(cnt == 0){
					warntext();
					gotoxy(125, 17);
					printf("�Է��Ͻ� ��ȣ�� ��ũ���� �����ϴ�.");
					Sleep(750);
					gotoxy(125, 17);
					printf("                                              ");
					showtext();
					gotoxy(128, 13);
					printf("                                   ");
					gotoxy(128, 13);
					goto Reselect3;
				}
				//��߿��� �����Է�.
				h = sttrData;
				while(h != NULL){
					if(strcmp(trainName,h->data.destSt)==0 && (atoi(trainNum) == h->data.trainNum)){
						strcpy(reserve.st_trainNum ,trainNum);	//���������� ������ȣ �Է�
						strcpy(reserve.startSt,startSt);	//���������� ��߿� �Է�
						reserve.st_hNum = (h->data.st_time/60 > 24) ? (h->data.st_time/60 - 24) : (h->data.st_time/60) ;	//���������� ��߽ð� �Է�
						reserve.st_mNum = h->data.st_time%60;	//���������� ��ߺ� �Է�

						strcpy(reserve.transfer,trainName);		//���������� ȯ�¿� �Է�
						reserve.sttr_hNum = h->data.dt_time/60;	//���������� ȯ�µ����ð� �Է�
						reserve.sttr_mNum = h->data.dt_time%60;	//���������� ȯ�µ����� �Է�
						reserve.pay = h->data.pay;
					}
					h= h->link;
				}



				gotoxy(125,14);
				printf("���Ͻô� ȯ�¿����� �Է��ϼ���\n");
				gotoxy(125,15);
				printf("�� ");
				gotoxy(128, 15);

Reselect4:		//ȯ�¿��� �Է�
				h = trdtData;				
				cnt=0;
				scanf("%s",trainNum);
				
				while(h != NULL){
					if(atoi(trainNum) == h->data.trainNum && strcmp(trainName,h->data.startSt) == 0)
						cnt++;
					h= h->link;
				}
				if(cnt == 0){
					warntext();
					gotoxy(125, 17);
					printf("�Է��Ͻ� ��ȣ�� ��ũ���� �����ϴ�.");
					Sleep(750);
					gotoxy(125, 17);
					printf("                                              ");
					showtext();
					gotoxy(128, 15);
					printf("                                   ");
					gotoxy(128, 15);
					goto Reselect4;
				}

				//�������� �����Է�.
				h = trdtData;
				while(h != NULL){
					if(strcmp(trainName,h->data.startSt)==0 && (atoi(trainNum) == h->data.trainNum)){
						strcpy(reserve.tr_trainNum ,trainNum);	//���������� ȯ�¿�����ȣ �Է�
						strcpy(reserve.transfer,trainName);	//���������� ȯ�¿� �Է�
						reserve.trdt_hNum = (h->data.st_time/60 > 24) ? (h->data.st_time/60 - 24) : (h->data.st_time/60) ;	//���������� ��߽ð� �Է�
						reserve.trdt_mNum = h->data.st_time%60;	//���������� ��ߺ� �Է�

						strcpy(reserve.destSt,destSt);		//���������� ������ �Է�
						reserve.dt_hNum = h->data.dt_time/60;	//���������� ȯ�µ����ð� �Է�
						reserve.dt_mNum = h->data.dt_time%60;	//���������� ȯ�µ����� �Է�
						reserve.pay += h->data.pay;
						reserve.check = 1;
					}
					h= h->link;
				}
				hideCursor();
				return reserve;
				break;
			}
		}
	}
	
	return reserve;
	fclose(fp2);
	fclose(fp);
	
	
	
}



/***************************************************************
	�Ű����� : �������� ����ü
	���	    : ���������� Reserve.txt �ۼ� �� ����ó��
****************************************************************/
void inputReserve(bookData book){
	
	FILE *fp = fopen("Train.txt","r");
	FILE *fp2 = fopen("TrainRoute.txt","r");
	FILE *fp3 = fopen("Reserve.txt","r");
	FILE *fp4 = fopen("Reserve.txt","a");
	int st_arr[3][5][5] = {0};	//����¼�
	int tr_arr[3][5][5] = {0};	//ȯ���¼�
	char dtHnum[5];		//�������� �����ð�
	char dtMnum[5];		//�������� ������
	char st_date[11];	//�������� ��߳�¥
	char tmp[11];
	char tmp_id[11];
	char tmp_trainNum[11];
	char tmp_ho[5];
	char tmp_row[5];
	char tmp_col[5];
	int rev_sum=0;	//���൵���ð� 
	int use_sum =0;	//�������߽ð�
	int i,j,cnt=0;		
	int stSum=0;	//	��߽ð� ����
	int pay=0;		//	������
	int ho,row,col;
	char rowCol[5];
	if(fp == NULL || fp2== NULL || fp3 == NULL || fp4 == NULL){
		printf("ERROR FILE OPEN");
		exit(1);
	}

	//�¼����
	while(!feof(fp3)){
		rev_sum = use_sum = 0;		
		fscanf(fp3,"%s",tmp_id);
		fscanf(fp3,"%s",st_date);
		fscanf(fp3,"%s",tmp_trainNum);
		fscanf(fp3,"%s",tmp);		//��߿�
		fscanf(fp3,"%s",tmp);		//��߽ð�
		fscanf(fp3,"%s",tmp);		//��ߺ�
		fscanf(fp3,"%s",tmp);		//������
		fscanf(fp3,"%s",dtHnum);		//�����ð�
		fscanf(fp3,"%s",dtMnum);	//������
		fscanf(fp3,"%s",tmp);			//���
		fscanf(fp3,"%s",tmp_ho);		//ȣ��
		fscanf(fp3,"%s",tmp_row);		//��
		fscanf(fp3,"%s",tmp_col);		//��
		if(strcmp(book.startDate,st_date) == 0){	//��¥ ����
			if(strcmp(book.st_trainNum,tmp_trainNum) == 0){	//��߱�����ȣ������
				rev_sum = atoi(dtHnum) * 60 + atoi(dtMnum);	//������� �����ð�
				use_sum = book.st_hNum*60 + book.st_mNum;	//�������� ��߽ð�
				if(rev_sum - use_sum > 0 ) st_arr[atoi(tmp_ho)][atoi(tmp_row)][atoi(tmp_col)]= 1;
			}
			else if(strcmp(book.tr_trainNum,tmp_trainNum) == 0){//ȯ�±�����ȣ������
				rev_sum = atoi(dtHnum) * 60 + atoi(dtMnum);	//������� �����ð�
				use_sum = book.trdt_hNum*60 + book.trdt_mNum;	//�������� ȯ�¿����� ��߽ð�
				if(rev_sum - use_sum > 0 ) tr_arr[atoi(tmp_ho)][atoi(tmp_row)][atoi(tmp_col)]= 1;
			}
		}
	}
	//���࿹��
	system("cls");
	printf("\t\t%s ���ο����Ȳ\n\n",book.st_trainNum);
	for(cnt=0; cnt<3; cnt++){
		printf("\n\n\t\tA  B  C  D\n");
		for(i=0; i<5; i++){
			if(i==2)
				printf("\t%dȣ��  %d",cnt+1,i+1);
			else
				printf("\t       %d",i+1);
			
			for(j=0; j<5; j++){
				if(st_arr[cnt][i][j] == 1)
					printf("��");
				else if(j ==2)
					printf("  ");
				else
					printf("��");
			}
			printf("\n");
		}
		printf("\n\n");
	}
Reselect:
	showCursor();
	gotoxy(60,15);
	printf("ȣ���� �Է����ּ���(1~3) : ");
	scanf("%d",&ho);
	//�¼� �߸� �Է½�
	while(ho>3||ho<1){
				fflush(stdin);
				warntext();
				gotoxy(60,20);
				printf("�Է��Ͻ� ��ȣ�� ���� ȣ���Դϴ�.");
				showtext();
				Sleep(1500);
				gotoxy(60,20);
				printf("                                  ");
				gotoxy(87,15);
				printf("         ");
				gotoxy(87,15);
				scanf("%d",&ho);
	}
	gotoxy(60,16);
	printf("�¼��� �Է����ּ���(�� : 1~5)(�� : A~D) : ");
	scanf("%s",rowCol);
	while((rowCol[0] != '1' && rowCol[0] != '2' && rowCol[0] != '3'&& rowCol[0] != '4'&& rowCol[0] != '5') ||( rowCol[1] !=65 && rowCol[1] !=66 && rowCol[1] !=67 && rowCol[1] !=68 )){
			fflush(stdin);
			warntext();
			gotoxy(60,20);
			printf("�Է��Ͻ� �¼��� ���� �¼��Դϴ�.");
			showtext();
			Sleep(1500);
			gotoxy(60,20);
			printf("                                ");
			gotoxy(102,16);
			printf("         ");
			gotoxy(102,16);
			scanf("%s", rowCol);
						 //�迭[0] ó���� 1~5����
	}
	
	
	//�¼� �ߺ�����
	row = (int)rowCol[0] - 49;
	col = (int)rowCol[1]- 65;
	if(col >= 2) col++;

	if(st_arr[ho-1][row][col] == 1){
		warntext();
		gotoxy(60,17);
		printf("�̹� ����� �ڸ��Դϴ�.");
		Sleep(750);
		gotoxy(60,17);
		printf("                                          ");
		gotoxy(60,15);
		printf("                                          ");
		gotoxy(60,16);
		printf("                                            ");
		showtext();
		goto Reselect;
	}
	if(book.check != 1)
		fprintf(fp4,"%s %s %s %s %d %d %s %d %d %d %d %d %d\n",book.id,book.startDate,book.st_trainNum,book.startSt,book.st_hNum,book.st_mNum,book.destSt,book.dt_hNum,book.dt_mNum,book.pay,ho-1,row,col);
	else
		fprintf(fp4,"%s %s %s %s %d %d %s %d %d %d %d %d %d\n",book.id,book.startDate,book.st_trainNum,book.startSt,book.st_hNum,book.st_mNum,book.transfer,book.sttr_hNum,book.sttr_mNum,book.pay,ho-1,row,col);
	//ȯ�¿���
	if(book.check == 1){
		system("cls");
		printf("\t\t%s ���ο����Ȳ\n\n",book.tr_trainNum);
		for(cnt=0; cnt<3; cnt++){
			printf("\n\n\t\tA  B  C  D\n");
			for(i=0; i<5; i++){
				if(i==2)
					printf("\t%dȣ��  %d",cnt+1,i+1);
				else
					printf("\t       %d",i+1);

				for(j=0; j<5; j++){
					if(tr_arr[cnt][i][j] == 1)
						printf("��");
					else if(j ==2)
						printf("  ");
					else
						printf("��");
				}
				printf("\n");
			}
			printf("\n\n");
		}
ReselectSeat:
		showCursor();
			gotoxy(60,15);
			printf("ȣ���� �Է����ּ���(1~3) : ");
			scanf("%d",&ho);
		while(ho>3 || ho<1){			
			warntext();
			gotoxy(60,20);
			printf("�Է��Ͻ� ��ȣ�� ���� ȣ���Դϴ�.");
			showtext();
			Sleep(1500);
			gotoxy(60,20);
			printf("                                  ");
			gotoxy(87,15);
			printf("         ");
			gotoxy(87,15);
			scanf("%d",&ho);
		}

		gotoxy(60,16);
		printf("�¼��� �Է����ּ���(�� : 1~5)(�� : A~C) : ");
		scanf("%s",rowCol);
		while((rowCol[0] != '1' && rowCol[0] != '2' && rowCol[0] != '3'&& rowCol[0] != '4'&& rowCol[0] != '5') ||( rowCol[1] !=65 && rowCol[1] !=66 && rowCol[1] !=67 && rowCol[1] !=68 )){
			fflush(stdin);
			warntext();
			gotoxy(60,20);
			printf("�Է��Ͻ� �¼��� ���� �¼��Դϴ�.");
			showtext();
			Sleep(1500);
			gotoxy(60,20);
			printf("                                ");
			gotoxy(102,16);
			printf("         ");
			gotoxy(102,16);
			scanf("%s", rowCol);
			//�迭[0] ó���� 1~5����
		}
	

		row = (int)rowCol[0] - 49;
		col = (int)rowCol[1]- 65;
		if(col >= 2) col++;

		if(tr_arr[ho-1][row][col] == 1){
			warntext();
			gotoxy(60,17);
			printf("�̹� ����� �ڸ��Դϴ�.");
			Sleep(750);
			gotoxy(60,17);
			printf("                                       ");
			gotoxy(60,15);
			printf("                                       ");
			gotoxy(60,16);
			printf("                                       ");
			showtext();
			goto ReselectSeat;
		}
		fprintf(fp4,"%s %s %s %s %d %d %s %d %d %d %d %d %d\n",book.id,book.startDate,book.tr_trainNum,book.transfer,book.trdt_hNum,book.trdt_mNum,book.destSt,book.dt_hNum,book.dt_mNum,book.pay,ho-1,row,col);
	}
	fclose(fp4);	
	fclose(fp3);
	fclose(fp2);
	fclose(fp);

}

/***************************************************************
	�Ű����� : ���̵�
	���	    : �ش� ���̵� ������ �������� ���
****************************************************************/
void findReserve(char* inputid){
	char id[11];
	char startDate[15];
	char trainNum[5];
	char startSt[11];
	char destSt[11];
	char st_hNum[5];
	char st_mNum[5];
	char dt_hNum[5];
	char dt_mNum[5];
	char pay[11];
	char ho[5];
	char row[5];
	char col[5];
	int nRow;
	int nCol;
	FILE *fp = fopen("Reserve.txt","r");
	if(fp == NULL){
		printf("ERROR OPEN FILE\n");
		exit(1);
	}
	ShowReserve();
	while(!feof(fp)){
		fscanf(fp,"%s",id);			//���̵�
		fscanf(fp,"%s",startDate);	//��߳�¥
		fscanf(fp,"%s",trainNum);	//������ȣ
		fscanf(fp,"%s",startSt);		//��߿�
		fscanf(fp,"%s",st_hNum);	//��߽ð�
		fscanf(fp,"%s",st_mNum);	//��� ��
		fscanf(fp,"%s",destSt);		//����
		fscanf(fp,"%s",dt_hNum);	//�����ð�
		fscanf(fp,"%s",dt_mNum);//���� ��
		fscanf(fp,"%s",pay);		//����
		fscanf(fp,"%s",ho);		//ȣ��
		fscanf(fp,"%s",row);		//�¼� ��
		nRow = atoi(row)+1;
		fscanf(fp,"%s",col);		//�¼� ��
		nCol = atoi(col)+65;
		if(nCol >= 67) nCol--;
		if(strcmp(id,inputid) == 0){
			printf("\t   %s\t",startDate);
			printf("%s\t",trainNum);
			printf("     %s\t    ",startSt);
			printf("%s :",st_hNum);
			printf(" %s\t",st_mNum);
			printf("      %s\t",destSt);
			if(atoi(dt_hNum) >=24)
				printf("  %d :",atoi(dt_hNum)-24);
			else
				printf("  %d :",atoi(dt_hNum));
			printf(" %s\t",dt_mNum);
			printf("     %s\t",pay);
			printf("   %d\t",atoi(ho)+1);
			printf("   %d",nRow);
			printf("%c\n",(char)nCol);
		}
	}
	getchar();
	
	fclose(fp);
}

/***************************************************************
	�Ű����� : ����
	���	    : ���� ���� �Լ�
****************************************************************/
void reserveTitle(char id[]){
	time_t timer;      //���� �ð�                                                 
	struct tm *t;		//���� �ð� ����ü
	int year, month, day;  
	char startDate[7];	//��߳�¥	
	int pNum;
	int i;
	bookData book;
	FILE *fp = fopen("Reserve.txt","a");
	if(fp == NULL){
		printf("ERROR OPEN FILE\n");
		exit(1);
	}
	reserveMenu();
	showCursor();
	while(1)   //��¥ Check
	{
		timer = time(NULL); // ���� �ð��� �� ������ ���
		t = localtime(&timer); // �� ������ �ð��� �и��Ͽ� ����ü�� 
		gotoxy(31,9);
		printf("                       ");
		gotoxy(31,9);
		fflush(stdin);
		gets(startDate);						//��¥�Է�
		year= (*(startDate+0)-'0')*10 + (*(startDate+1)-'0')+100;  //t->tm_year�� 114�̹Ƿ� �⵵�� +100 
		month = (*(startDate+2)-'0')*10 +(*(startDate+3)-'0'); 
		day = (*(startDate+4)-'0')*10 +(*(startDate+5)-'0');
		if(strlen(startDate)==6)//���̰� 6�϶�
		{
			/*if(year>=t->tm_year && month >= t->tm_mon + 1 && day >= t->tm_mday)*/
			if(year > t->tm_year)
			{
				if(month<=0||month>12)  //1~12��
					goto ONE;
				if(day<=0||day>31)      //0~31��
					goto ONE;
				if(month==4)      //30�� ���� ex)4�� 31�� ����
					if(day>30)
						goto ONE;
				if(month==6)
					if(day>30)
						goto ONE;
				if(month==9)
					if(day>30)
						goto ONE;
				if(month==11)
					if(day>30)
						goto ONE;
				if(month==2)   
				{
					if(day>29)
					{
						goto ONE;
					}
					if(day==29)
					{
						if(year%4==0 && year%100!=0 || year%400==0 ) //����
						{
							break;
						}
						else goto ONE;
					}
				}
				break;
			}

			else if(year < t->tm_year)
			{
				goto ONE;
			}

			else if(year = t->tm_year)    //���� �⵵�� �Է¹��� �⵵�� �����ܿ�
			{
				if( month < t->tm_mon + 1)
					goto ONE;

				if( month >= t->tm_mon +1)
					if(day < t->tm_mday)
						goto ONE;

				if(month<=0||month>12)  //1~12��
					goto ONE;
				if(day<=0||day>31)      //0~31��
					goto ONE;
				if(month==4)      //30�� ���� ex)4�� 31�� ����
					if(day>30)
						goto ONE;
				if(month==6)
					if(day>30)
						goto ONE;
				if(month==9)
					if(day>30)
						goto ONE;
				if(month==11)
					if(day>30)
						goto ONE;
				if(month==2)   
				{
					if(day>29)
					{
						goto ONE;
					}
					if(day==29)
					{
						if(year%4==0 && year%100!=0 || year%400==0 ) //����
						{
							break;
						}
						else goto ONE;
					}
				}
				break;
			}

			else 
				break;
			
		}
		else 
			goto ONE;
			


ONE:
		warntext();
		gotoxy(19,17);
		printf("��߳�¥�� �߸��Է��ϼ̽��ϴ�.\n");
		showtext();
		Sleep(750);
		gotoxy(19,17);
		printf("                               ");
	}   //��¥ Check


	strcpy(book.startDate,startDate);











	fflush(stdin);

	strcpy(book.startSt,CheckstartSt());	//��߿�
	strcpy(book.destSt,CheckdestSt(book.startSt));	//������
	gotoxy(31,12);
	scanf("%d",&pNum);				//�ο���
	while(pNum > 9 || pNum <= 0){								//9��Ѿ�� �����޽��� ���
		warntext();
		gotoxy(19,17);
		printf("�ο� ���� 1~9���Դϴ�.\n");
		showtext();
		Sleep(750);
		gotoxy(19,17);
		printf("                               ");
		gotoxy(31,12);
		printf("                    ");
		gotoxy(31,12);
		fflush(stdin);
		scanf("%d",&pNum);
	}
	book = makeReserve(book.startSt,book.destSt);	//��ȣ�Է�
	strcpy(book.startDate,startDate);
	book.pNum = pNum;
	strcpy(book.id,id);
	if(book.check != -1){	
		for(i=0; i<book.pNum; i++){	//�ο�����ŭ �Է�
			inputReserve(book);
		}
		//���� �޴�
		system("cls");
		load();
		system("cls");
		load2();
		Sleep(1000);
	}
	hideCursor();						
}

