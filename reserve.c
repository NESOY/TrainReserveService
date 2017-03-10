#include "reserve.h"

/***************************************************************
	매개변수 : 없음
	기능	    : 예약 중 Print
****************************************************************/
void load(){
	int i=0;
	 printf("\n\n");
   printf("\t┏━━━━━━━━━━━━━━━━━━━━━━┓\n");
   printf("\t┃                                            ┃ \n");
   printf("\t┃                                            ┃\n");
    printf("\t┃                                            ┃\n");
    printf("\t┃                                            ┃\n");
   printf("\t┃                                            ┃\n");
   printf("\t┃                  예약중                    ┃\n");
   printf("\t┃                                            ┃\n");
   printf("\t┃\t ┏━━━━━━━━━━━┓\t      ┃\n");
   printf("\t┃\t ┃                      ┃\t      ┃\n");
   printf("\t┃\t ┗━━━━━━━━━━━┛\t      ┃\n");
   printf("\t┃                                            ┃\n");
   printf("\t┃                                            ┃\n");
   printf("\t┃                                            ┃\n");
   printf("\t┃                                            ┃\n");
   printf("\t┃                                            ┃\n");
   printf("\t┃                                            ┃\n");
   printf("\t┃                                            ┃\n");
   printf("\t┗━━━━━━━━━━━━━━━━━━━━━━┛\n");
   for(i=20;i<40;i++){
	gotoxy(i,12);
	printf(">>");
	Sleep(150);
   }
}


/***************************************************************
	매개변수 : 없음
	기능	    : 예약 완료 Print
****************************************************************/
void load2(){
	 printf("\n\n");
   printf("\t┏━━━━━━━━━━━━━━━━━━━━━━┓\n");
   printf("\t┃                                            ┃ \n");
   printf("\t┃                                            ┃\n");
   printf("\t┃                                            ┃\n");
   printf("\t┃                                            ┃\n");
   printf("\t┃                                            ┃\n");
   printf("\t┃                                            ┃\n");
   printf("\t┃           예약이 완료 되었습니다.          ┃\n");
   printf("\t┃                                            ┃\n");
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
	기능	    : 직행/환승 Print
****************************************************************/
void selectMenu()
{
   printf("\n\n");
   printf("\t┏━━━━━━━━━━━━━━━━━━━━━━┓\n");
   printf("\t┃                                            ┃ \n");
   printf("\t┃                                            ┃\n");
   printf("\t┃                                            ┃\n");
   printf("\t┃                 직행/환승                  ┃\n");
   printf("\t┃                                            ┃\n");
   printf("\t┃                                            ┃\n");
   printf("\t┃                 1. 직행                    ┃\n");
   printf("\t┃                 2. 환승                    ┃\n");
   printf("\t┃                                            ┃\n");
   printf("\t┃                                            ┃\n");
   printf("\t┃                                            ┃\n");
   printf("\t┃                                            ┃\n");
   printf("\t┃                                            ┃\n");
   printf("\t┃                                            ┃\n");
   printf("\t┗━━━━━━━━━━━━━━━━━━━━━━┛\n");
}


/***************************************************************
	매개변수 : 연결리스트 헤더포인터, 연결리스트 포인터, 열차번호, 출발시간, 도착시간, 요금, 열차종류, 출발역, 도착역
	기능	    :  연결리스트에 열차정보 삽입
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
	매개변수 : 없음
	기능	    :  예약 가능한 배차정보 Print
****************************************************************/
void ShowList(){
	printf("\n\n");
	printf("\t  열차번호    |     열차종류    |    출발    |    출발시간    |    도착    |    도착시간    |    운임요금  \n");
	printf("\t---------------------------------------------------------------------------------------------------------\n");
}

/***************************************************************
	매개변수 : 없음
	기능	    : 예약한 배차정보 Print
****************************************************************/
void ShowReserve(){
	printf("\n\n");
	printf("\t  출발날짜 |   열차번호   |   출발    |    출발시간     |    도착    |    도착시간    |    운임요금   |  호수  |  좌석 \n");
	printf("\t----------------------------------------------------------------------------------------------------------------------\n");
}

/***************************************************************
	매개변수 : 없음
	기능	    : 예약정보를 입력할 메뉴 Print
****************************************************************/
void reserveMenu(){
   printf("\n\n");
   printf("\t┏━━━━━━━━━━━━━━━━━━━━━━┓\n");
   printf("\t┃                                            ┃ \n");
   printf("\t┃                                            ┃\n");
   printf("\t┃                                            ┃\n");
   printf("\t┃           예약정보를 입력해주세요          ┃\n");
   printf("\t┃                                            ┃\n");
   printf("\t┃        출발날짜  :	                      ┃\n");   
   printf("\t┃        출발역    :                         ┃\n");
   printf("\t┃        도착역    :                         ┃\n");
   printf("\t┃        인원      :                         ┃\n");
   printf("\t┃                                            ┃\n");
   printf("\t┃                                            ┃\n");
   printf("\t┃                                            ┃\n");
   printf("\t┃                                            ┃\n");
   printf("\t┃                                            ┃\n");
   printf("\t┃                                            ┃\n");
   printf("\t┃                                            ┃\n");
   printf("\t┃                                            ┃\n");
   printf("\t┃ 예약 TIP                                   ┃\n");
   printf("\t┃1. 출발날짜는 ex(2015년1월1일->150101 입력) ┃\n");
   printf("\t┃2. 출발,도착역은 ex(서울역 -> 서울 입력)    ┃\n");
   printf("\t┃3. 인원은 1~9 숫자중 하나의 숫자 입력       ┃\n");
   printf("\t┗━━━━━━━━━━━━━━━━━━━━━━┛\n");
}

/***************************************************************
	매개변수 : 없음
	기능	    : 출발역 예외처리
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
			printf("역이 존재하지않습니다!\n");
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
	매개변수 : 출발역
	기능	    : 도착역 예외처리
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
			printf("출발역과 도착역이 똑같습니다!\n");
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
				printf("역이 존재하지않습니다!\n");
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
	매개변수 : 출발역,도착역
	기능	    : 매개변수에 충족하는 열차 Print 및 열차 선택을 받고
				  좌석 Print 및 좌석 선택을 받고
				  예약정보를 예약정보 구조체에 작성 후 예약정보구조체 Return
****************************************************************/
bookData makeReserve(char startSt[],char destSt[]){
	FILE *fp = fopen("Train.txt","r");
	FILE *fp2 = fopen("TrainRoute.txt","r");
	char trainName[11];	//열차정차역
	char trainClass[11];	//열차종류
	char trainNum[11];			//열차번호
	char size[5];				//루트갯수
	char start[11];			//Train.txt 출발역
	char transfer[11];		//환승역
	char dest[11];			//Train.txt 도착역
	char temp[11];
	char hour[5],min[5];
	int key;
	int i,j,k,cnt=0;		
	int stSum=0;	//	출발시간 저장
	int pay=0;		//	돈저장
	int st_hNum,st_mNum;		//출발 시간/분저장
	int dt_hNum,dt_mNum;		//도착 시간/분저장
	int stIndex,dtIndex;			//출발 도착 환승 인덱스
	int f1_index,f2_index;		//파일포인터 위치.
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
			if(strcmp(trainName,startSt) == 0 && cnt==0){	//도착역이 체크안된상태에서 출발역 비교
				cnt++;
				stIndex = i;
			}
			else if(cnt ==1 && strcmp(trainName,destSt) == 0){	//출발역체크되고 도착역 비교
				cnt++;
				dtIndex = i;
			}
		}
		f2_index = ftell(fp2);
		if(cnt == 2){	//직행Ver
				fscanf(fp,"%s",trainClass);
				fscanf(fp,"%s",start);
				fscanf(fp,"%s",dest);
				fscanf(fp,"%s",hour);
				fscanf(fp,"%s",min);			

				stSum += atoi(hour)*60;
				stSum += atoi(min);
				//출발시간계산
				if(strcmp(startSt,start) != 0){	//기차 출발역과 입력출발역이 다를때
					for(i=0; i<50; i++){
						for(j=0; j<50; j++){
							if(strcmp(st[i][j].k.startSt,start) == 0 && strcmp(st[i][j].k.destSt,startSt) == 0){
								if(strcmp("KTX",trainClass) == 0){	//KTX 출발 시간더하기
									stSum += st[i][j].k.time + stIndex*5;		//정차시간 5분추가								
								}
								else{										//무궁화 출발 시간더하기
									stSum += st[i][j].m.time + stIndex*5;								
								}
							}
						}
					}					
				}
				
				
				st_hNum = stSum / 60;
				st_mNum = stSum % 60;
				
				//도착시간계산
				for(i=0; i<50; i++){
					for(j=0; j<50; j++){
						if(strcmp(st[i][j].k.startSt,startSt) == 0 && strcmp(st[i][j].k.destSt,destSt) == 0){
							if(strcmp("KTX",trainClass) == 0){	//KTX 출발 시간더하기
								stSum += st[i][j].k.time;
								pay  += st[i][j].k.pay; 
							}
							else{										//무궁화 출발 시간더하기
								stSum += st[i][j].m.time;
								pay += st[i][j].m.pay;
							}
						}
					}
				}				
			
				dt_hNum = (stSum+((dtIndex-1)*5)) / 60;
				dt_mNum = (stSum+((dtIndex-1)*5)) % 60;
				
				insert_node(&directData , directData , atoi(trainNum) , st_hNum*60+st_mNum , dt_hNum*60+dt_mNum , pay, trainClass ,startSt , destSt );	//연결리스트에 데이터 입력.
		}
		else if(cnt == 1){//환승Ver
				fscanf(fp,"%s",trainClass);
				fscanf(fp,"%s",start);
				fscanf(fp,"%s",dest);
				fscanf(fp,"%s",hour);
				fscanf(fp,"%s",min);
				f1_index = ftell(fp);		//돌아갈 FILE FP 저장

				stSum += atoi(hour)*60;
				stSum += atoi(min);
				//출발시간계산
				if(strcmp(startSt,start) != 0){	//기차 출발역과 입력출발역이 다를때
					for(i=0; i<50; i++){
						for(j=0; j<50; j++){
							if(strcmp(st[i][j].k.startSt,start) == 0 && strcmp(st[i][j].k.destSt,startSt) == 0){
								if(strcmp("KTX",trainClass) == 0){	//KTX 출발 시간더하기
									stSum += st[i][j].k.time + stIndex*5;		//정차시간 5분추가						
								}
								else{										//무궁화 출발 시간더하기
									stSum += st[i][j].m.time + stIndex*5;									
								}
							}
						}
					}					
				}
				
				st_hNum = stSum / 60;
				st_mNum = stSum % 60;
				

				//환승역받기
				fseek(fp2,r_index,SEEK_SET);	//파일 포인터 루트 처음으로 이동;
				fscanf(fp2,"%s",transfer);
				for(i=0; i<stIndex; i++)		//출발역으로 이동.
					fscanf(fp2,"%s",transfer);
				for(k=stIndex; k<atoi(size)-1; k++){		//출발역이후의 역들을 모두 환승역으로 간주하여 넣는다.
					fscanf(fp2,"%s",transfer);
					//환승역도착시간계산
					stSum= st_hNum * 60 + st_mNum;
					pay = dt_hNum = dt_mNum = 0;
					for(i=0; i<50; i++){
						for(j=0; j<50; j++){
							if(strcmp(st[i][j].k.startSt,startSt) == 0 && strcmp(st[i][j].k.destSt,transfer) == 0){
								if(strcmp("KTX",trainClass) == 0){	//KTX 출발 시간더하기
									stSum += st[i][j].k.time;
									pay  += st[i][j].k.pay; 
								}
								else{										//무궁화 출발 시간더하기
									stSum += st[i][j].m.time;
									pay += st[i][j].m.pay;
								}
							}
						}
					}

					
					dt_hNum = (stSum+(k*5)) / 60;
					dt_mNum = (stSum+(k*5)) % 60;

					
					insert_node(&sttrData , sttrData , atoi(trainNum) , st_hNum*60+st_mNum , dt_hNum*60+dt_mNum , pay, trainClass ,startSt , transfer );	//연결리스트에 데이터 입력.
				}
				fseek(fp,0,SEEK_SET);//처음으로 이동.
				fseek(fp2,0,SEEK_SET);	//처음으로 이동.
				
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
					while(h != NULL){	//환승역 찾기.
						cnt = stSum =	pay = st_hNum = st_mNum = dt_hNum = dt_mNum = stIndex = dtIndex=0;
						fseek(fp2,r_index,SEEK_SET);		//루트처음으로 이동
						for(i=0; i<atoi(size); i++){								
							fscanf(fp2,"%s",trainName);	//루트 역이름 가져오기
							if(strcmp(trainName,h->data.destSt) == 0 && cnt==0){	//도착역이 체크안된상태에서 환승역 비교
								cnt++;
								stIndex = i;								
							}
							else if(cnt ==1 && strcmp(trainName,destSt) == 0){	//도착역 찾기.
								cnt++;
								dtIndex = i;
							}
						}
						if(cnt == 2){	//환승 && 도착역 존재
							stSum += atoi(hour)*60;
							stSum += atoi(min);
							//환승출발시간계산
							if(strcmp(h->data.destSt,start) != 0){	//기차 출발역과 환승역이 다를때
								for(i=0; i<50; i++){
									for(j=0; j<50; j++){
										if(strcmp(st[i][j].k.startSt,start) == 0 && strcmp(st[i][j].k.destSt,h->data.destSt) == 0){
											if(strcmp("KTX",trainClass) == 0){	//KTX 출발 시간더하기
												stSum += st[i][j].k.time + stIndex*5;		//정차시간 5분추가			
											}
											else{										//무궁화 출발 시간더하기
												stSum += st[i][j].m.time + stIndex*5;												
											}
										}
									}
								}					
							}


							st_hNum = stSum / 60;
							st_mNum = stSum % 60;

							
							//환승도착시간계산
							for(i=0; i<50; i++){
								for(j=0; j<50; j++){
									if(strcmp(st[i][j].k.startSt,h->data.destSt) == 0 && strcmp(st[i][j].k.destSt,destSt) == 0){		//환승역과 도착역 루트.
										if(strcmp("KTX",trainClass) == 0){	//KTX 출발 시간더하기
											stSum += st[i][j].k.time;
											pay  += st[i][j].k.pay; 
										}
										else{										//무궁화 출발 시간더하기
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
								if((p->data.st_time ==  st_hNum*60+st_mNum) && strcmp(p->data.startSt,h->data.destSt) == 0  )	//중복check
									break;
								p = p->link;
							}
							if(p == NULL){
								insert_node(&trdtData , trdtData , atoi(trainNum) , st_hNum*60+st_mNum , dt_hNum*60+dt_mNum , pay, trainClass ,h->data.destSt , destSt );	//연결리스트에 데이터 입력.				
							}
						}
						h = h->link;
					}



				}
				//돌아오기
				fseek(fp,f1_index,SEEK_SET);
				fseek(fp2,f2_index,SEEK_SET);				
			}
		

		else{//출발역이 존재하지 않는다.
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
			case 1://직행				
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
				printf("원하시는 열차를 입력하세요\n");
				gotoxy(125,10);
				warntext();
				printf("나가시려면 exit를 입력하세요\n");
				showtext();
				gotoxy(125,11);
				printf("▶ ");
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
						strcpy(reserve.st_trainNum ,trainNum);	//예약정보에 열차번호 입력
						strcpy(reserve.startSt,startSt);	//예약정보에 출발역 입력
						reserve.st_hNum = (h->data.st_time/60 > 24) ? (h->data.st_time/60 - 24) : (h->data.st_time/60) ;	//예약정보에 출발시간 입력
						reserve.st_mNum = h->data.st_time%60;	//예약정보에 출발분 입력

						strcpy(reserve.destSt,destSt);		//예약정보에 도착역 입력
						reserve.dt_hNum = h->data.dt_time/60;	//예약정보에 도착시간 입력
						reserve.dt_mNum = h->data.dt_time%60;	//예약정보에 도착분 입력	
						reserve.pay = h->data.pay;				//예약정보에 요금 입력

						cnt++;
					}
					h= h->link;
				}
				if(cnt == 0){
					warntext();
					gotoxy(125, 13);
					printf("입력하신 번호가 스크린에 없습니다.");
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
				
			case 2:	//환승입력
				//환승출력
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
				printf("원하시는 열차를 입력하세요\n");
				gotoxy(125,10);
				warntext();
				printf("나가시려면 exit를 입력하세요\n");
				showtext();
				gotoxy(125,11);
				printf("▶ ");
				gotoxy(128, 11);
				showCursor();

Reselect2:		//출발열차 입력
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
					printf("입력하신 번호가 스크린에 없습니다.");
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
				printf("원하시는 환승역을 입력하세요\n");
				gotoxy(125,13);
				printf("▶ ");
				gotoxy(128, 13);


Reselect3:		//환승역 입력
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
					printf("입력하신 번호가 스크린에 없습니다.");
					Sleep(750);
					gotoxy(125, 17);
					printf("                                              ");
					showtext();
					gotoxy(128, 13);
					printf("                                   ");
					gotoxy(128, 13);
					goto Reselect3;
				}
				//출발열차 정보입력.
				h = sttrData;
				while(h != NULL){
					if(strcmp(trainName,h->data.destSt)==0 && (atoi(trainNum) == h->data.trainNum)){
						strcpy(reserve.st_trainNum ,trainNum);	//예약정보에 열차번호 입력
						strcpy(reserve.startSt,startSt);	//예약정보에 출발역 입력
						reserve.st_hNum = (h->data.st_time/60 > 24) ? (h->data.st_time/60 - 24) : (h->data.st_time/60) ;	//예약정보에 출발시간 입력
						reserve.st_mNum = h->data.st_time%60;	//예약정보에 출발분 입력

						strcpy(reserve.transfer,trainName);		//예약정보에 환승역 입력
						reserve.sttr_hNum = h->data.dt_time/60;	//예약정보에 환승도착시간 입력
						reserve.sttr_mNum = h->data.dt_time%60;	//예약정보에 환승도착분 입력
						reserve.pay = h->data.pay;
					}
					h= h->link;
				}



				gotoxy(125,14);
				printf("원하시는 환승열차를 입력하세요\n");
				gotoxy(125,15);
				printf("▶ ");
				gotoxy(128, 15);

Reselect4:		//환승열차 입력
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
					printf("입력하신 번호가 스크린에 없습니다.");
					Sleep(750);
					gotoxy(125, 17);
					printf("                                              ");
					showtext();
					gotoxy(128, 15);
					printf("                                   ");
					gotoxy(128, 15);
					goto Reselect4;
				}

				//도착열차 정보입력.
				h = trdtData;
				while(h != NULL){
					if(strcmp(trainName,h->data.startSt)==0 && (atoi(trainNum) == h->data.trainNum)){
						strcpy(reserve.tr_trainNum ,trainNum);	//예약정보에 환승열차번호 입력
						strcpy(reserve.transfer,trainName);	//예약정보에 환승역 입력
						reserve.trdt_hNum = (h->data.st_time/60 > 24) ? (h->data.st_time/60 - 24) : (h->data.st_time/60) ;	//예약정보에 출발시간 입력
						reserve.trdt_mNum = h->data.st_time%60;	//예약정보에 출발분 입력

						strcpy(reserve.destSt,destSt);		//예약정보에 도착역 입력
						reserve.dt_hNum = h->data.dt_time/60;	//예약정보에 환승도착시간 입력
						reserve.dt_mNum = h->data.dt_time%60;	//예약정보에 환승도착분 입력
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
	매개변수 : 예약정보 구조체
	기능	    : 예약정보를 Reserve.txt 작성 및 예외처리
****************************************************************/
void inputReserve(bookData book){
	
	FILE *fp = fopen("Train.txt","r");
	FILE *fp2 = fopen("TrainRoute.txt","r");
	FILE *fp3 = fopen("Reserve.txt","r");
	FILE *fp4 = fopen("Reserve.txt","a");
	int st_arr[3][5][5] = {0};	//출발좌석
	int tr_arr[3][5][5] = {0};	//환승좌석
	char dtHnum[5];		//예약정보 도착시간
	char dtMnum[5];		//예약정보 도착분
	char st_date[11];	//예약정보 출발날짜
	char tmp[11];
	char tmp_id[11];
	char tmp_trainNum[11];
	char tmp_ho[5];
	char tmp_row[5];
	char tmp_col[5];
	int rev_sum=0;	//예약도착시간 
	int use_sum =0;	//사용자출발시간
	int i,j,cnt=0;		
	int stSum=0;	//	출발시간 저장
	int pay=0;		//	돈저장
	int ho,row,col;
	char rowCol[5];
	if(fp == NULL || fp2== NULL || fp3 == NULL || fp4 == NULL){
		printf("ERROR FILE OPEN");
		exit(1);
	}

	//좌석계산
	while(!feof(fp3)){
		rev_sum = use_sum = 0;		
		fscanf(fp3,"%s",tmp_id);
		fscanf(fp3,"%s",st_date);
		fscanf(fp3,"%s",tmp_trainNum);
		fscanf(fp3,"%s",tmp);		//출발역
		fscanf(fp3,"%s",tmp);		//출발시간
		fscanf(fp3,"%s",tmp);		//출발분
		fscanf(fp3,"%s",tmp);		//도착역
		fscanf(fp3,"%s",dtHnum);		//도착시간
		fscanf(fp3,"%s",dtMnum);	//도착분
		fscanf(fp3,"%s",tmp);			//요금
		fscanf(fp3,"%s",tmp_ho);		//호수
		fscanf(fp3,"%s",tmp_row);		//행
		fscanf(fp3,"%s",tmp_col);		//열
		if(strcmp(book.startDate,st_date) == 0){	//날짜 같고
			if(strcmp(book.st_trainNum,tmp_trainNum) == 0){	//출발기차번호같을때
				rev_sum = atoi(dtHnum) * 60 + atoi(dtMnum);	//예약고객의 도착시간
				use_sum = book.st_hNum*60 + book.st_mNum;	//예약자의 출발시간
				if(rev_sum - use_sum > 0 ) st_arr[atoi(tmp_ho)][atoi(tmp_row)][atoi(tmp_col)]= 1;
			}
			else if(strcmp(book.tr_trainNum,tmp_trainNum) == 0){//환승기차번호같을때
				rev_sum = atoi(dtHnum) * 60 + atoi(dtMnum);	//예약고객의 도착시간
				use_sum = book.trdt_hNum*60 + book.trdt_mNum;	//예약자의 환승역에서 출발시간
				if(rev_sum - use_sum > 0 ) tr_arr[atoi(tmp_ho)][atoi(tmp_row)][atoi(tmp_col)]= 1;
			}
		}
	}
	//직행예약
	system("cls");
	printf("\t\t%s 내부예약상황\n\n",book.st_trainNum);
	for(cnt=0; cnt<3; cnt++){
		printf("\n\n\t\tA  B  C  D\n");
		for(i=0; i<5; i++){
			if(i==2)
				printf("\t%d호차  %d",cnt+1,i+1);
			else
				printf("\t       %d",i+1);
			
			for(j=0; j<5; j++){
				if(st_arr[cnt][i][j] == 1)
					printf("■");
				else if(j ==2)
					printf("  ");
				else
					printf("□");
			}
			printf("\n");
		}
		printf("\n\n");
	}
Reselect:
	showCursor();
	gotoxy(60,15);
	printf("호차를 입력해주세요(1~3) : ");
	scanf("%d",&ho);
	//좌석 잘못 입력시
	while(ho>3||ho<1){
				fflush(stdin);
				warntext();
				gotoxy(60,20);
				printf("입력하신 번호는 없는 호차입니다.");
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
	printf("좌석을 입력해주세요(행 : 1~5)(열 : A~D) : ");
	scanf("%s",rowCol);
	while((rowCol[0] != '1' && rowCol[0] != '2' && rowCol[0] != '3'&& rowCol[0] != '4'&& rowCol[0] != '5') ||( rowCol[1] !=65 && rowCol[1] !=66 && rowCol[1] !=67 && rowCol[1] !=68 )){
			fflush(stdin);
			warntext();
			gotoxy(60,20);
			printf("입력하신 좌석은 없는 좌석입니다.");
			showtext();
			Sleep(1500);
			gotoxy(60,20);
			printf("                                ");
			gotoxy(102,16);
			printf("         ");
			gotoxy(102,16);
			scanf("%s", rowCol);
						 //배열[0] 처음이 1~5사이
	}
	
	
	//좌석 중복여부
	row = (int)rowCol[0] - 49;
	col = (int)rowCol[1]- 65;
	if(col >= 2) col++;

	if(st_arr[ho-1][row][col] == 1){
		warntext();
		gotoxy(60,17);
		printf("이미 예약된 자리입니다.");
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
	//환승예약
	if(book.check == 1){
		system("cls");
		printf("\t\t%s 내부예약상황\n\n",book.tr_trainNum);
		for(cnt=0; cnt<3; cnt++){
			printf("\n\n\t\tA  B  C  D\n");
			for(i=0; i<5; i++){
				if(i==2)
					printf("\t%d호차  %d",cnt+1,i+1);
				else
					printf("\t       %d",i+1);

				for(j=0; j<5; j++){
					if(tr_arr[cnt][i][j] == 1)
						printf("■");
					else if(j ==2)
						printf("  ");
					else
						printf("□");
				}
				printf("\n");
			}
			printf("\n\n");
		}
ReselectSeat:
		showCursor();
			gotoxy(60,15);
			printf("호차를 입력해주세요(1~3) : ");
			scanf("%d",&ho);
		while(ho>3 || ho<1){			
			warntext();
			gotoxy(60,20);
			printf("입력하신 번호는 없는 호차입니다.");
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
		printf("좌석을 입력해주세요(열 : 1~5)(행 : A~C) : ");
		scanf("%s",rowCol);
		while((rowCol[0] != '1' && rowCol[0] != '2' && rowCol[0] != '3'&& rowCol[0] != '4'&& rowCol[0] != '5') ||( rowCol[1] !=65 && rowCol[1] !=66 && rowCol[1] !=67 && rowCol[1] !=68 )){
			fflush(stdin);
			warntext();
			gotoxy(60,20);
			printf("입력하신 좌석은 없는 좌석입니다.");
			showtext();
			Sleep(1500);
			gotoxy(60,20);
			printf("                                ");
			gotoxy(102,16);
			printf("         ");
			gotoxy(102,16);
			scanf("%s", rowCol);
			//배열[0] 처음이 1~5사이
		}
	

		row = (int)rowCol[0] - 49;
		col = (int)rowCol[1]- 65;
		if(col >= 2) col++;

		if(tr_arr[ho-1][row][col] == 1){
			warntext();
			gotoxy(60,17);
			printf("이미 예약된 자리입니다.");
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
	매개변수 : 아이디
	기능	    : 해당 아이디가 예약한 예약정보 출력
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
		fscanf(fp,"%s",id);			//아이디
		fscanf(fp,"%s",startDate);	//출발날짜
		fscanf(fp,"%s",trainNum);	//기차번호
		fscanf(fp,"%s",startSt);		//출발역
		fscanf(fp,"%s",st_hNum);	//출발시간
		fscanf(fp,"%s",st_mNum);	//출발 분
		fscanf(fp,"%s",destSt);		//도착
		fscanf(fp,"%s",dt_hNum);	//도착시간
		fscanf(fp,"%s",dt_mNum);//도착 분
		fscanf(fp,"%s",pay);		//가격
		fscanf(fp,"%s",ho);		//호수
		fscanf(fp,"%s",row);		//좌석 행
		nRow = atoi(row)+1;
		fscanf(fp,"%s",col);		//좌석 열
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
	매개변수 : 없음
	기능	    : 예약 메인 함수
****************************************************************/
void reserveTitle(char id[]){
	time_t timer;      //현재 시간                                                 
	struct tm *t;		//현재 시간 구조체
	int year, month, day;  
	char startDate[7];	//출발날짜	
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
	while(1)   //날짜 Check
	{
		timer = time(NULL); // 현재 시각을 초 단위로 얻기
		t = localtime(&timer); // 초 단위의 시간을 분리하여 구조체에 
		gotoxy(31,9);
		printf("                       ");
		gotoxy(31,9);
		fflush(stdin);
		gets(startDate);						//날짜입력
		year= (*(startDate+0)-'0')*10 + (*(startDate+1)-'0')+100;  //t->tm_year가 114이므로 년도에 +100 
		month = (*(startDate+2)-'0')*10 +(*(startDate+3)-'0'); 
		day = (*(startDate+4)-'0')*10 +(*(startDate+5)-'0');
		if(strlen(startDate)==6)//길이가 6일때
		{
			/*if(year>=t->tm_year && month >= t->tm_mon + 1 && day >= t->tm_mday)*/
			if(year > t->tm_year)
			{
				if(month<=0||month>12)  //1~12달
					goto ONE;
				if(day<=0||day>31)      //0~31일
					goto ONE;
				if(month==4)      //30일 날들 ex)4월 31일 오류
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
						if(year%4==0 && year%100!=0 || year%400==0 ) //윤년
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

			else if(year = t->tm_year)    //현재 년도와 입력받은 년도가 같은겨우
			{
				if( month < t->tm_mon + 1)
					goto ONE;

				if( month >= t->tm_mon +1)
					if(day < t->tm_mday)
						goto ONE;

				if(month<=0||month>12)  //1~12달
					goto ONE;
				if(day<=0||day>31)      //0~31일
					goto ONE;
				if(month==4)      //30일 날들 ex)4월 31일 오류
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
						if(year%4==0 && year%100!=0 || year%400==0 ) //윤년
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
		printf("출발날짜를 잘못입력하셨습니다.\n");
		showtext();
		Sleep(750);
		gotoxy(19,17);
		printf("                               ");
	}   //날짜 Check


	strcpy(book.startDate,startDate);











	fflush(stdin);

	strcpy(book.startSt,CheckstartSt());	//출발역
	strcpy(book.destSt,CheckdestSt(book.startSt));	//도착역
	gotoxy(31,12);
	scanf("%d",&pNum);				//인원수
	while(pNum > 9 || pNum <= 0){								//9명넘어가면 에러메시지 출력
		warntext();
		gotoxy(19,17);
		printf("인원 수는 1~9명입니다.\n");
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
	book = makeReserve(book.startSt,book.destSt);	//번호입력
	strcpy(book.startDate,startDate);
	book.pNum = pNum;
	strcpy(book.id,id);
	if(book.check != -1){	
		for(i=0; i<book.pNum; i++){	//인원수만큼 입력
			inputReserve(book);
		}
		//결제 메뉴
		system("cls");
		load();
		system("cls");
		load2();
		Sleep(1000);
	}
	hideCursor();						
}

