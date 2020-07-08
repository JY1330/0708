#include <stdio.h> //ǥ�� ����� ��ġ ��� ���� ��� 
#include <stdlib.h> //ǥ�� ���̺귯�� ��� ���� ��� 
#include <conio.h> // �ܼ� ����� ��� ���� ��� 
#include <windows.h> // ������ ��� ���� ��� 

void move_arrow_key(char chr, int *x, int *y, int x_b, int y_b); //����Ű �Լ� ����
void gotoxy(int x, int y); //Ŀ�� ���� �Լ� ����
void draw_check01(int c, int r);; //�׸� �׸��� �Լ� ����
void game_control(void); //���� ���� �Լ� ����
void display_stone(int matrix[][20][20]); // �ٵϾ� ���� �Լ� ���� 

int main(void) // main �Լ� ���� 
{
	game_control(); // ���� ���� �Լ� ���� 
	return 0;
}


void gotoxy(int x, int y) //Ŀ�� ���� �Լ� ���� 
{
   COORD Pos = {x - 1, y - 1};
   SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), Pos);
}

void draw_check01(int c, int r) //�׸� �׸��� �Լ� ���� 
{
    int i, j; //int ���� i, j ���� 
    unsigned char a=0xa6; //unsigned char ���� a ���� 
    unsigned char b[12]; //unsigned char ���� b ���� 
    for(i=1;i<12;i++)
		b[i]=0xa0+i; //���� i�� 1���� 12�̸����� b[i]�� ���� 1�� ������ �ݺ� 
    printf("%c%c",a, b[3]);  //ȭ�鿡 ���� a�� b[3]�� ���
    for(i=0;i<c-1;i++)
		printf("%c%c", a, b[8]); //���� i�� 0���� c-1 �̸� ���� ȭ�鿡 ���� a�� b[8]�� ����� �ݺ� 
    printf("%c%c", a, b[4]); //ȭ�鿡 ���� a�� b[4]�� ���
    printf("\n"); //�� �ٲ� 
    for(i=0;i<r-1;i++) //���� i�� 0���� r-1�̸� ���� �Ʒ� ������� �ݺ� 
    {
		printf("%c%c", a, b[7]);  //ȭ�鿡 ���� a�� b[7]�� ���
		for(j=0;j<c-1;j++)
	    	printf("%c%c", a, b[11]); // ���� j�� 0���� c-1�̸� ���� ȭ�鿡 ���� a�� b[3]�� ����� �ݺ� 
		printf("%c%c",a, b[9]);  //ȭ�鿡 ���� a�� b[9]�� ���
		printf("\n"); //�� �ٲ� 
    }
    printf("%c%c", a, b[6]); //ȭ�鿡 ���� a�� b[6]�� ���
    for(i=0;i<c-1;i++)
		printf("%c%c", a, b[10]); // ���� i�� 0���� c-1 �̸� ����ȭ�鿡 ���� a�� b[3]�� ����� �ݺ� 
    printf("%c%c", a, b[5]); //ȭ�鿡 ���� a�� b[5]�� ���
    printf("\n"); //�� �ٲ� 
}

void game_control(void) // ���� ���� �Լ� ���� 
{
   int x=1, y=1, other=0; //int ���� x, y, other ���� 
   int matrix[2][20][20]={0};//int ���� matrix ���� 
   char key; //char ���� key ���� 
   char *stone[2]={"��","��"}; //char ���� *stone ���� 
   do // �Ʒ� ������� �ݺ� 
   {
	gotoxy(1,1);
	draw_check01(18, 18);
	gotoxy(x, y);
	printf("%s", stone[other]);
	display_stone(matrix);
	gotoxy(1, 20);
	printf("����Ű�� �����̰� ");
	printf("�����̽� Ű�� �����ÿ�.");
	gotoxy(1,21);
        printf("���� �������� ���� �����Դϴ�. ");
	key=getch();
	if (key==27)
		exit(0);
	else if(key==32)
	{
		matrix[other][(x+1)/2][y]=1;
                other=1-other;  //������ �κ�(ȹ��)
	}
	else if (key>=72)
		move_arrow_key(key, &x, &y, 37, 19);
   }while(1);
}

void display_stone(int matrix[][20][20]) // �ٵϾ� ���� �Լ� ���� 
{
	int i, x, y; //int ���� i, x, y ���� 
	char *stone[2]={"��", "��"}; //char ���� *stone ���� 

	for(i=0;i<2;i++) //���� i�� 0���� 2�̸����� �Ʒ� ������� �ݺ� 
		for(x=1;x<20;x++) //���� x�� 1���� 20�̸����� �Ʒ� ������� �ݺ� 
			for(y=1;y<20;y++) //���� y�� 1���� 20�̸����� �Ʒ� ������� �ݺ� 
			{
				if (matrix[i][x][y]==1) // matrix[i][x][y]�� 1�϶� �Ʒ� �ڵ���� ���� 
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
	case 72:  //����(��) ������ ȭ��ǥ Ű �Է�
		*y1=*y1-1;
		if (*y1<1)	*y1=1; //y��ǥ�� �ּҰ�
		break;
	case 75:  //����(��) ������ ȭ��ǥ Ű �Է�
		*x1=*x1-2;             //������������ 2�� ����
		if (*x1<1)	*x1=1; //x��ǥ�� �ּҰ�
		break;
	case 77:  //������(��) ������ ȭ��ǥ Ű �Է�
		*x1=*x1+2;               //������������ 2�� ����
		if (*x1>x_b)  *x1=x_b; //x��ǥ�� �ִ밪(���)
		break;
	case 80:  //�Ʒ���(��) ������ ȭ��ǥ Ű �Է�
		*y1=*y1+1;
		if (*y1>y_b)  *y1=y_b; //y��ǥ�� �ִ밪(���)
		break;
	default:
		return;
	}
}
