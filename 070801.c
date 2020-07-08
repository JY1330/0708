#include <stdio.h> //표준 입출력 장치 헤더 파일 사용 
#include <stdlib.h> //표준 라이브러리 헤더 파일 사용 
#include <conio.h> // 콘솔 입출력 헤더 파일 사용 
#include <windows.h> // 윈도우 헤더 파일 사용 

void move_arrow_key(char chr, int *x, int *y, int x_b, int y_b); //방향키 함수 정의
void gotoxy(int x, int y); //커서 제어 함수 정의
void draw_check01(int c, int r); //그림 그리기 함수 정의
void game_control(void); //게임 제어 함수 정의

int main(void) // main 함수 생성
{
	game_control(); //게임 제어 함수 실행
	return 0;
}

void gotoxy(int x, int y) //커서 제어 함수 생성
{
   COORD Pos = {x - 1, y - 1};
   SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), Pos);
}

void draw_check01(int c, int r) //그림 그리기 함수 생성
{
    int i, j;
    unsigned char a=0xa6; //char 변수 a 정의  
    unsigned char b[12]; //char 변수 b 정의
    for(i=1;i<12;i++)
	b[i]=0xa0+i; //b[1] 부터 b[11]까지 점차 1씩 증가를 반복 
    printf("%c%c",a, b[3]); //화면에 변수 a와 변수 b[3]를 출력 
    for(i=0;i<c-1;i++)
		printf("%c%c", a, b[8]); //변수 i가 0부터 c-1미만까지 화면에 변수 a와 변수 b[4]를 반복 출력 
    printf("%c%c", a, b[4]); //화면에 변수 a와 변수 b[4]를 출력
    printf("\n"); //줄 바꿈
    for(i=0;i<r-1;i++) //변수 i가 0부터 r-1미만까지 아래 아래 실행들을 반복 
    {
	printf("%c%c", a, b[7]); //화면에 변수 a와 변수 b[7]를 출력
	for(j=0;j<c-1;j++)  
	    printf("%c%c", a, b[11]); //변수 j가 0부터 c-1미만까지 화면에 변수 a와 변수 b[11]를 반복 출력
	printf("%c%c",a, b[9]); //화면에 변수 a와 변수 b[9]를 출력
	printf("\n"); //줄 바꿈
    }
    printf("%c%c", a, b[6]); //화면에 변수 a와 변수 b[9]를 출력
    for(i=0;i<c-1;i++) 
		printf("%c%c", a, b[10]); //변수 i가 0부터 c-1미만까지 화면에 변수 a와 변수 b[10]를 반복 출력
    printf("%c%c", a, b[5]); //화면에 변수 a와 변수 b[5]를 출력
    printf("\n"); //줄 바꿈
}

void game_control(void) // 게임 제어 함수 생성 
{
    int x=1, y=1; //int 변수 x,y 정의 
    char key; //char 변수 key 정의 
    do // 아래 실행들을 반복 
    {
	gotoxy(1,1);
	draw_check01(18, 18);
	gotoxy(x, y);
	printf("○");
	gotoxy(1, 21);
	printf("방향키를 누르시오.");
	key=getch();
	if (key==27)
		exit(0);
	else if (key>=72)
		move_arrow_key(key, &x, &y, 37, 19); //수정부분
   }while(1);
}

void move_arrow_key(char key, int *x1, int *y1, int x_b, int y_b) // 방향키 제어 함수 생성 
{
	switch(key)
	{
	case 72:  //위쪽(상) 방향의 화살표 키 입력
		*y1=*y1-1;
		if (*y1<1)	*y1=1; //y좌표의 최소값
		break;
	case 75:  //왼쪽(좌) 방향의 화살표 키 입력
		*x1=*x1-2;             //좌측방향으로 2씩 감소
		if (*x1<1)	*x1=1; //x좌표의 최소값
		break;
	case 77:  //오른쪽(우) 방향의 화살표 키 입력
		*x1=*x1+2;               //우측방향으로 2씩 증가
		if (*x1>x_b)  *x1=x_b; //x좌표의 최대값(경계)
		break;
	case 80:  //아래쪽(하) 방향의 화살표 키 입력
		*y1=*y1+1;
		if (*y1>y_b)  *y1=y_b; //y좌표의 최대값(경계)
		break;
	default:
		return;
	}
}

