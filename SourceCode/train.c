#include"train.h"

/***************************************************************
	매개변수 : 없음
	기능	    : 배차 메뉴 Print
****************************************************************/
void trainMenu(){
	printf("\n\n");
	printf("\t┏━━━━━━━━━━━━━━━━━━━━━━┓\n");
	printf("\t┃                                            ┃ \n");
	printf("\t┃                                            ┃\n");
	printf("\t┃                                            ┃\n");
	printf("\t┃               배차 추가/조회               ┃\n");
	printf("\t┃                                            ┃\n");
	printf("\t┃                                            ┃\n");
	printf("\t┃               1. 추가                      ┃\n");
	printf("\t┃               2. 조회                      ┃\n");
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
	기능	    : 배차 추가 Print
****************************************************************/
void trainCreateMenu(){
	printf("\n\n");
	printf("\t┏━━━━━━━━━━━━━━━━━━━━━━┓\n");
	printf("\t┃                                            ┃ \n");
	printf("\t┃                                            ┃\n");
	printf("\t┃                                            ┃\n");
	printf("\t┃                 배차 추가                  ┃\n");
	printf("\t┃                                            ┃\n");
	printf("\t┃      1. 열차번호 ->                        ┃\n");
	printf("\t┃      2. 열차종류 ->	 	              ┃\n");
	printf("\t┃      3. 출발역   ->                        ┃\n");
	printf("\t┃      4. 도착역   ->                        ┃\n");
	printf("\t┃      5. 출발시간 ->     :                  ┃\n");
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
	기능	    : 열차 조회 메뉴 Print
****************************************************************/
void trainCheckMenu(){
	printf("\n\n");
	printf("\t----------------------------------------------------------------------------------\n");
	printf("\t                              열차조회\n");
	printf("\t----------------------------------------------------------------------------------\n");
	printf("\t 열차번호  |   열차종류    |   출발역     |   도착역          |  출발시간  |\n");
	printf("\t----------------------------------------------------------------------------------\n");
}


/***************************************************************
	매개변수 : 배차정보 구조체
	기능	    : 기차번호 예외처리
****************************************************************/
int trainCheckNum(trainData *td){
	char trainNum[10];
	char checkNum[10];
	int key;
	int i;
	FILE *fp1 = fopen("Train.txt","r");
	if(fp1 == NULL){
		printf("ERROR OPEN FILE");
		exit(1);
	}
	showCursor();	
	do{
		system("cls");
		trainCreateMenu();
		gotoxy(33,9);
		gets(trainNum);
		for(i=0; i<strlen(trainNum); i++){
			if(trainNum[i]<48 || trainNum[i]>57)
				key = 1;
		}
		fseek(fp1,0,SEEK_SET);
		while(!feof(fp1) ){
			fscanf(fp1,"%s",&checkNum);
			if(strcmp(trainNum , checkNum)==0 || key == 1 ||  strlen(trainNum) <= 0 ||  strlen(trainNum) >=5){
					warntext();
					gotoxy(20,17);
					if(key == 1)
						printf("숫자로만 입력해주세요!\n");
					else if(strlen(trainNum)==0)
						printf("필수입력사항입니다!\n");
					else if(strlen(trainNum) >=5)
						printf("열차는 0~9999까지 입력합니다.");
					else
						printf("이미 열차번호가 있습니다!\n");
					showtext();
					Sleep(750);
					return 0;
					break;
			}
			else
				for(i=0; i<5; i++)
					fscanf(fp1,"%s ",&checkNum);
		}
	}while(!feof(fp1));

	strcpy(td->trainNum,trainNum);
	fclose(fp1);	
	return 1;
}


/***************************************************************
	매개변수 : 없음
	기능	    : 출발역 예외처리
****************************************************************/
char* trainCheckstartSt(){
	char startSt[11];
	
	int i=0,cnt=0;


	while(1){
		gotoxy(33,11);	
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
			gotoxy(33,11);
			printf("                   ");
		}
	}
	
	return startSt;
}


/***************************************************************
	매개변수 : 출발역
	기능	    : 도착역 예외처리
****************************************************************/
char* trainCheckdestSt(char* startSt){
	char destSt[11];
	int i=0,cnt=0;

	while(1){
		gotoxy(33,12);	
		gets(destSt);
		if(strcmp(startSt,destSt) == 0){
			warntext();
			gotoxy(20,17);
			printf("출발역과 도착역이 똑같습니다!\n");
			showtext();
			Sleep(750);
			gotoxy(20,17);
			printf("                              ");
			gotoxy(33,12);
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
				gotoxy(33,12);
				printf("                   ");
			}
		}
	}
	return destSt;
}	


/***************************************************************
	매개변수 : 출발역 넘버링 숫자, 도착역 넘버링 숫자, 열차 종류
	기능	    : 출발역과 도착역을 제외한 경로 작성
****************************************************************/
void path(int start,int end,char *train){
	if(Path[start][end] != -1){
		path(start,Path[start][end],train);
		if(strcmp(train,"KTX") == 0){
			if(st[Path[start][end]][Path[start][end]].edge >2){
				cnt++;
				strcat(route,st[Path[start][end]][0].k.startSt);
				strcat(route," ");
			}
		}
		else{
			cnt++;
			strcat(route,st[Path[start][end]][0].k.startSt);
			strcat(route," ");
		}
		path(Path[start][end],end,train);
	}
}


/***************************************************************
	매개변수 : 출발역, 도착역, 열차 종류
	기능	    : 전체 경로 작성
****************************************************************/
void trainRoute(char *startSt,char *destSt,char *train){
	int startIndex,destIndex;
	int i;
	for(i=0; i<50; i++){
		if(strcmp(startSt,st[i][0].k.startSt) == 0)
			startIndex = i;
		else if(strcmp(destSt,st[i][0].k.startSt) ==0)
			destIndex = i;
	}
	cnt = 2;
	memset(route,NULL,150);
	strcat(route,st[startIndex][0].k.startSt);
	strcat(route," ");
	path(startIndex,destIndex,train);
	strcat(route,st[destIndex][0].k.startSt);
	
}

/***************************************************************
	매개변수 : 배차정보 구조체
	기능	    : 배차종류 예외처리
****************************************************************/
int trainClass(trainData *td){
	char train[10];
	//KTX 무궁화 입력
	gotoxy(33,10);
	gets(train);
	if(strcmp(train, "무궁화") != 0 && strcmp(train, "KTX") != 0 ){
		warntext();
		gotoxy(20,17);
		if(strlen(train) == 0)
			printf("필수입력사항입니다!\n");
		else
			printf("무궁화 또는 KTX가 아닙니다!\n");
		showtext();
		Sleep(750);
		gotoxy(33,10);
		printf("      ");
		gotoxy(20,17);
		printf("                           ");
		return 0;
	}
	else{
		fflush(stdin);
		strcpy(td->trainClass,train);
	}
	return 1;
}

/***************************************************************
	매개변수 : 없음
	기능	    : 배차생성
****************************************************************/
void trainCreate(){
	trainData td;

	FILE *fp = fopen("Train.txt","a");
	FILE *fp2 = fopen("TrainRoute.txt","a");
	if(fp == NULL || fp2 == NULL){
		printf("ERROR OPEN FILE\n");
		exit(1);
	}

	while(trainCheckNum(&td)!=1);		//열차번호검사
	fflush(stdin);			
	while(trainClass(&td) != 1);		//종류 검사
	strcpy(td.startSt,trainCheckstartSt());	//출발역 검사	
	strcpy(td.destSt,trainCheckdestSt(td.startSt));	//도착역 검사
	gotoxy(33,13);
	scanf("%d",&td.hour);
	while(td.hour > 23 || td.hour < 0){
			fflush(stdin);
			warntext();
			gotoxy(20,17);
			printf("시간은 0~23으로 입력해주세요!\n");
			showtext();
			Sleep(750);
			gotoxy(20,17);
			printf("                             ");
			gotoxy(33,13);
			printf("   :                      ");
			gotoxy(33,13);
			fflush(stdin);
			scanf("%d",&td.hour);
		}

	gotoxy(38,13);
	fflush(stdin);
	scanf("%d",&td.min);
	while(td.min < 0 || td.min > 59){
			fflush(stdin);
			warntext();
			gotoxy(20,17);
			printf("분은 0~59로 입력해주세요!\n");
			showtext();
			Sleep(750);
			gotoxy(20,17);
			printf("                             ");
			gotoxy(38,13);
			printf("   ");
			gotoxy(38,13);
			fflush(stdin);
			scanf("%d",&td.min);
	}

	fprintf(fp,"%s ",td.trainNum);	//열차번호
	fprintf(fp,"%s ",td.trainClass);//열차종류
	fprintf(fp,"%s ",td.startSt);	//출발역
	fprintf(fp,"%s ",td.destSt);	//도착역
	fprintf(fp,"%d ",td.hour);		//출발시간
	fprintf(fp,"%d\n",td.min);		//출발 분


	trainRoute(td.startSt,td.destSt,td.trainClass);
	fprintf(fp2,"%s ",td.trainNum);
	fprintf(fp2,"%d\n", cnt);
	fprintf(fp2,"%s\n",route);
	hideCursor();
	fclose(fp);
	fclose(fp2);
}



/***************************************************************
	매개변수 : 없음
	기능	    : 배차 조회
****************************************************************/
void trainAsk(){
	FILE *fp = fopen("Train.txt","r");
	char trainNum[10];
	char trainClass[10];
	char startSt[10];
	char destSt[10];
	char st_hNum[5];
	char st_mNum[5];
	if(fp == NULL){
		printf("ERROR FILE OPEN");
		exit(1);
	}
	trainCheckMenu();
	while(1){
		fscanf(fp,"%s",trainNum);
		fscanf(fp,"%s",trainClass);
		fscanf(fp,"%s",startSt);
		fscanf(fp,"%s",destSt);
		fscanf(fp,"%s",st_hNum);
		fscanf(fp,"%s",st_mNum);
		if(feof(fp)) break;
		printf("%15s",trainNum);
		printf("%15s",trainClass);
		printf("%15s",startSt);
		printf("%15s",destSt);
		printf("%15s",st_hNum);
		printf(" :%2s\n",st_mNum);
	}
	fflush(stdin);
	getchar();
	fclose(fp);
}




/***************************************************************
	매개변수 : 없음
	기능	    : 배차 메인 함수
****************************************************************/
void trainTitle(){
	int key;
	curX=22;
	curY=10;
	while(1){
		system("cls");
		trainMenu();
		gotoxy(curX,curY);
		printf("▶");
		key = get2MenuSelect();
		if(key == -1){
			curX=20;		curY=19;
			break;
		}
		if(key!=0){
			switch(key-9){
				case 1:
					//배차추가
					system("cls");
					fflush(stdin);
					trainCreate();
					curX=22;
					curY=10;
					break;
				case 2:
					//배차조회
					system("cls");
					trainAsk();
					curX=22;
					curY=10;
					break;
			}
		}
	
	}
	
}
