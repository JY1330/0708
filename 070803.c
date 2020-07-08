#include <stdio.h> //표준 입출력 장치 헤더 파일 사용 
#include <stdlib.h> //표준 라이브러리 헤더 파일 사용 
#include <conio.h> // 콘솔 입출력 헤더 파일 사용 
#include <windows.h> // 윈도우 헤더 파일 사용 

void move_arrow_key(char chr, int *x, int *y, int x_b, int y_b); //방향키 함수 정의
void gotoxy(int x, int y); //커서 제어 함수 정의
void draw_check01(int c, int r);; //그림 그리기 함수 정의
void game_control(void); //게임 제어 함수 정의
void display_stone(int matrix[][20][20]); // 바둑알 놓기 함수 정의 

int main(void) // main 함수 생성 
{
	game_control(); // 게임 제어 함수 실행 
	return 0;
}


void gotoxy(int x, int y) //커서 제어 함수 생성 
{
   COORD Pos = {x - 1, y - 1};
   SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), Pos);
}

void draw_check01(int c, int r) //그림 그리기 함수 생성 
{
    int i, j; //int 변수 i, j 생성 
    unsigned char a=0xa6; //unsigned char 변수 a 생성 
    unsigned char b[12]; //unsigned char 변수 b 생성 
    for(i=1;i<12;i++)
		b[i]=0xa0+i; //변수 i가 1부터 12미만까지 b[i]의 값에 1씩 증가를 반복 
    printf("%c%c",a, b[3]);  //화면에 변수 a와 b[3]을 출력
    for(i=0;i<c-1;i++)
		printf("%c%c", a, b[8]); //변수 i가 0부터 c-1 미만 까지 화면에 변수 a와 b[8]을 출력을 반복 
    printf("%c%c", a, b[4]); //화면에 변수 a와 b[4]을 출력
    printf("\n"); //줄 바꿈 
    for(i=0;i<r-1;i++) //변수 i가 0부터 r-1미만 까지 아래 실행들을 반복 
    {
		printf("%c%c", a, b[7]);  //화면에 변수 a와 b[7]을 출력
		for(j=0;j<c-1;j++)
	    	printf("%c%c", a, b[11]); // 변수 j가 0부터 c-1미만 까지 화면에 변수 a와 b[3]을 출력을 반복 
		printf("%c%c",a, b[9]);  //화면에 변수 a와 b[9]을 출력
		printf("\n"); //줄 바꿈 
    }
    printf("%c%c", a, b[6]); //화면에 변수 a와 b[6]을 출력
    for(i=0;i<c-1;i++)
		printf("%c%c", a, b[10]); // 변수 i가 0부터 c-1 미만 까지화면에 변수 a와 b[3]을 출력을 반복 
    printf("%c%c", a, b[5]); //화면에 변수 a와 b[5]을 출력
    printf("\n"); //줄 바꿈 
}

void game_control(void) // 게임 제어 함수 생성 
{
   int x=1, y=1, other=0; //int 변수 x, y, other 생성 
   int matrix[2][20][20]={0};//int 변수 matrix 생성 
   char key; //char 변수 key 생성 
   char *stone[2]={"○","●"}; //char 변수 *stone 생성 
   do // 아래 실행들을 반복 
   {
	gotoxy(1,1);
	draw_check01(18, 18);
	gotoxy(x, y);
	printf("%s", stone[other]);
	display_stone(matrix);
	gotoxy(1, 20);
	printf("방향키로 움직이고 ");
	printf("스페이스 키를 누르시오.");
	gotoxy(1,21);
        printf("돌을 놓았으면 상대방 차례입니다. ");
	key=getch();
	if (key==27)
		exit(0);
	else if(key==32)
	{
		matrix[other][(x+1)/2][y]=1;
                other=1-other;  //수정한 부분(획인)
	}
	else if (key>=72)
		move_arrow_key(key, &x, &y, 37, 19);
   }while(1);
}

void display_stone(int matrix[][20][20]) // 바둑알 놓기 함수 생성 
{
	int i, x, y; //int 변수 i, x, y 생성 
	char *stone[2]={"○", "●"}; //char 변수 *stone 생성 

	for(i=0;i<2;i++) //변수 i가 0부터 2미만까지 아래 실행들을 반복 
		for(x=1;x<20;x++) //변수 x가 1부터 20미만까지 아래 실행들을 반복 
			for(y=1;y<20;y++) //변수 y가 1부터 20미만까지 아래 실행들을 반복 
			{
				if (matrix[i][x][y]==1) // matrix[i][x][y]가 1일때 아래 코드들을 실행 
				{
					gotoxy(x*2-1, y);
					printf("%s", stone[i]);
				}
			}
}

void move_arrow_key(char key, int *x1, int *y1, int x_b, int y_b)
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

