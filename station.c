#include"station.h"




/***************************************************************
	매개변수 : 없음
	기능	    : 역 정보 생성
****************************************************************/
void makeStation(){
	int size;
	int i,k,j;
	int cnt=0;
	int indexSt1,indexSt2;
	FILE *fp = fopen("무궁화.txt","r");
	FILE *fp2 = fopen("KTX.txt","r");
	
	if(fp == NULL || fp2 == NULL){
		printf("Error Open File\n");
		exit(1);
	}
	//배열 초기화
	for(i=0; i<50; i++)
		for(j=0; j<50; j++){
			st[i][j].k.time = 999;
			st[i][j].m.time = 999;
			Path[i][j] = -1;
			st[i][j].edge = 0;
		}

	//무궁화 데이터 입력
	fscanf(fp,"%d",&size);
	for(i=0; i<size; i++){
		fscanf(fp,"%d",&indexSt1);
		fscanf(fp,"%d",&indexSt2);
		fscanf(fp,"%d",&st[indexSt1][indexSt2].m.time);
		st[indexSt2][indexSt1].m.time = st[indexSt1][indexSt2].m.time;
		fscanf(fp,"%d",&st[indexSt1][indexSt2].m.pay);
		st[indexSt2][indexSt1].m.pay = st[indexSt1][indexSt2].m.pay;
		fscanf(fp,"%s",&st[indexSt1][indexSt2].m.startSt);
		fscanf(fp,"%s",&st[indexSt1][indexSt2].m.destSt);
		for(j=0;j<50; j++){
			strcpy(st[indexSt1][j].m.startSt,st[indexSt1][indexSt2].m.startSt);	//출발역
			strcpy(st[j][indexSt1].m.destSt,st[indexSt1][indexSt2].m.startSt);	//입력
		}
		for(j=0;j<50; j++){
			strcpy(st[indexSt2][j].m.startSt,st[indexSt1][indexSt2].m.destSt);	//도착역
			strcpy(st[j][indexSt2].m.destSt,st[indexSt1][indexSt2].m.destSt);	//입력
		}
	}
	//KTX 데이터 입력
	fscanf(fp2,"%d",&size);
	for(i=0; i<size; i++){
		fscanf(fp2,"%d",&indexSt1);
		fscanf(fp2,"%d",&indexSt2);
		fscanf(fp2,"%d",&st[indexSt1][indexSt2].k.time);
		st[indexSt2][indexSt1].k.time = st[indexSt1][indexSt2].k.time;
		fscanf(fp2,"%d",&st[indexSt1][indexSt2].k.pay);
		st[indexSt2][indexSt1].k.pay = st[indexSt1][indexSt2].k.pay;
		fscanf(fp2,"%s",&st[indexSt1][indexSt2].k.startSt);
		fscanf(fp2,"%s",&st[indexSt1][indexSt2].k.destSt);
		for(j=0;j<50; j++){
			strcpy(st[indexSt1][j].k.startSt,st[indexSt1][indexSt2].k.startSt);
			strcpy(st[j][indexSt1].k.destSt,st[indexSt1][indexSt2].k.startSt);
		}
		for(j=0;j<50; j++){
			strcpy(st[indexSt2][j].k.startSt,st[indexSt1][indexSt2].k.destSt);
			strcpy(st[j][indexSt2].k.destSt,st[indexSt1][indexSt2].k.destSt);
		}
	}
	//간선의 개수 확인.
	for(i=0; i<50; i++){
		for(j=0; j<50; j++){
			if(st[i][j].k.time != 999)
				st[i][i].edge++;
		}
	}


	//Floyd Algorithm
	for(k=0; k<50; k++){
		for(i=0; i<50; i++){
			for(j=0; j<50; j++){
				//Ktx 가중치값 비교
				if(st[i][k].k.time+st[k][j].k.time < st[i][j].k.time){
					if(i !=j){
						st[i][j].k.pay = st[i][k].k.pay+st[k][j].k.pay;
						st[i][j].k.time = st[i][k].k.time+st[k][j].k.time;
						Path[i][j] = k;
					}
				}
				//무궁화 가중치값 비교
				if(st[i][k].m.time+st[k][j].m.time < st[i][j].m.time){
					if(i != j){
					st[i][j].m.pay = st[i][k].m.pay+st[k][j].m.pay;
					st[i][j].m.time = st[i][k].m.time+st[k][j].m.time;
					}
				}		
			}
		}
	}


	fclose(fp);
	fclose(fp2);
}

