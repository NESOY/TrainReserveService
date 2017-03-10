#include "signUp.h"



/***************************************************************
	매개변수 : 없음
	기능	    : 회원가입 메뉴 Print
****************************************************************/
void signUp(){
   printf("\n\n");
   printf("\t┏━━━━━━━━━━━━━━━━━━━━━━┓\n");
   printf("\t┃                                            ┃ \n");
   printf("\t┃                   회원가입                 ┃\n");
   printf("\t┃                                            ┃\n");
   printf("\t┃             개인정보를 입력하시오.         ┃\n");
   printf("\t┃                                            ┃\n");
   printf("\t┃            아이디:                         ┃\n");
   printf("\t┃          비밀번호:                         ┃\n");
   printf("\t┃          비밀번호:                         ┃\n");
   printf("\t┃              이름:                         ┃\n");
   printf("\t┃              나이:                         ┃\n");
   printf("\t┃              성별:                         ┃\n");
   printf("\t┃          (남/여 중 선택입력하시오)         ┃\n");
   printf("\t┃            연락처:                         ┃\n");
   printf("\t┃                                            ┃\n");
   printf("\t┗━━━━━━━━━━━━━━━━━━━━━━┛\n");

}


/***************************************************************
	매개변수 : 회원정보 구조체
	기능	    : ID 작성 예외처리
****************************************************************/
int getId(Person *p){
	FILE *fp = fopen("Person.txt","r");
	int i=0;
	char tmpId[12];
	if(fp == NULL){
		printf("Error Open File\n");
		exit(1);
	}

	//아이디 입력
	system("cls");
	signUp();
	gotoxy(30,9);
	gets(p->id);
	if(strlen(p->id) == 0){
				warntext();
				gotoxy(10,19);
				printf("필수입력 사항이므로 다시 입력해주세요.");
				showtext();
				Sleep(1000);
				return 0;
	}

	if(strlen(p->id) < 5 || strlen(p->id) > 10){
		warntext();
		gotoxy(10,19);
		printf("아이디는 영문 5~10 자리 , 한글 3~5자리로 입력해주세요.\n");
		showtext();
		Sleep(1000);
		return 0;
	}


	while(!feof(fp)){
		fscanf(fp,"%s",tmpId);
		if(strcmp(p->id,tmpId) == 0){
			warntext();
			gotoxy(22,17);
			printf("같은 아이디가 존재합니다!\n");
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
	매개변수 : 회원정보 구조체
	기능	    : PW 작성 예외처리
****************************************************************/
int getPw(Person *p){
	char tmpPw[15];//비밀번호 재확인을 위한 tmp

	//메뉴출력
	system("cls");
	signUp();
	gotoxy(30,9);
	printf("%s",p->id);	
	//비밀번호입력
	gotoxy(30,10);
	hidetext();
	gets(p->pw);

	if(strlen(p->pw) > 10 || strlen(p->pw) < 5){
		warntext();
		gotoxy(18,17);
		printf("비밀번호는 5~10자리 입력하세요!\n");
		showtext();
		Sleep(750);
		return 0;
	}
	//비밀번호확인
	gotoxy(30,11);
	gets(tmpPw);
	showtext(); // 입력이 끝나면 원래 색으로 복귀
	
	if( strcmp(tmpPw,p->pw) != 0){
		warntext();
		gotoxy(18,17);
		printf("비밀번호가 다릅니다!\n");
		showtext();
		Sleep(750);
		return 0;
	}
	return 1;
}


/***************************************************************
	매개변수 : 회원정보 구조체
	기능	    : 이름 작성 예외처리
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
	//이름입력
	gets(p->name);
	if(strlen(p->name) == 0){
		warntext();
		gotoxy(10,19);
		printf("필수입력 사항이므로 다시 입력해주세요.");
		showtext();
		Sleep(1000);
		return 0;
	}
	if(strlen(p->name) > 10){
		warntext();
		gotoxy(18,17);
		printf("이름은 5자이하로 입력하세요!\n");
		showtext();
		Sleep(750);
		return 0;
	}
	return 1;
}



/***************************************************************
	매개변수 : 회원정보 구조체
	기능	    : 나이 작성 예외처리
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
	//나이 입력
	gotoxy(30,13);
	scanf("%d", &p->age);
	if(p->age < 0 || p->age >100){
		warntext();
		gotoxy(15,17);
		printf("나이는 0~100세까지 입력해주세요!\n");
		showtext();
		Sleep(750);
		return 0;
	}
	return 1;
}



/***************************************************************
	매개변수 : 회원정보 구조체
	기능	    : 성별 작성 예외처리
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
		printf("필수입력 사항이므로 다시 입력해주세요.");
		showtext();
		Sleep(1000);
		return 0;	
	}
	if(strcmp(p->gender,"남") !=0 && strcmp(p->gender,"여") != 0){
		warntext();
		gotoxy(15,17);
		printf("성별은 '남','여'로 입력해주세요!\n");
		showtext();
		Sleep(750);
		return 0;
	}
	
	return 1;
}



/***************************************************************
	매개변수 : 회원정보 구조체
	기능	    : 전화번호 작성 예외처리
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
		printf("필수입력 사항이므로 다시 입력해주세요.");
		showtext();
		Sleep(1000);
		return 0;
	}
	if((strlen(p->phone) > 11 || strlen(p->phone) < 7) || key == 1 ){
		warntext();
		gotoxy(15,17);
		printf("숫자로만 7~11자리로 입력하세요!\n");
		showtext();
		Sleep(750);
		return 0;
	}
	return 1;
}



/***************************************************************
	매개변수 : 회원정보 구조체
	기능	    : Person.txt에 저장
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
