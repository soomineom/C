#include <stdio.h>
#include <time.h>
#include <stdlib.h>

#define CLASS 4
#define Student 20
int score[CLASS][Student];

void inputscore();
void upsort();
void downsort();
void getscore();
void Avarage();
void Highscore();
void Lowscore();

int main()
{
	inputscore();
	for (int i = 0; i < CLASS; i++)
	{
		if (i % 2 == 0)
		{
			upsort(i);
		}
		else
		{
			downsort(i);
		}
	}
	getscore();
}

void inputscore()
{
	srand(time(NULL));
	for (int i = 0; i < CLASS; i++)
	{
		for (int j = 0; j < Student; j++)
		{
			score[i][j] = rand() % 100;
		}
	}
}

void upsort(int classnumber)
{
	for (int i = 0; i < CLASS; i++)
	{
		for (int j = 0; j < Student; j++)
		{
			if (score[i][j] > score[i][j + 1])
			{
				int temp;
				temp = score[i][j];
				score[i][j] = score[i][j + 1];
				score[i][j + 1] = temp;

				if (j != 0)
					j -= 2;
			}
		}
	}
}
void downsort(int classnumber)
{
	for (int i = 0; i < CLASS; i++)
	{
		for (int j = 0; j < Student; j++)
		{
			if (score[i][j] < score[i][j + 1])
			{
				int temp;
				temp = score[i][j];
				score[i][j] = score[i][j + 1];
				score[i][j + 1] = temp;
				if (j != 0)
					j -= 2;
			}
		}
	}
}
void Avarage()
{
	int sum;
	int sumall = 0;
	for (int i = 0; i < CLASS; i++)
	{
		sum = 0;
		for (int j = 0; j < Student; j++)
		{
			sum += score[i][j];
		}
		sumall += sum;
		printf("%d���� ����� %d�Դϴ�.\n", i + 1, sum / 20);
	}
	printf("������ ����� %d�Դϴ�.\n", sumall / 80);
}
void Highscore()
{
	int temp;
	int highall = 0;
	for (int i = 0; i < CLASS; i++)
	{
		temp = score[i][0];
		for (int j = 1; j < Student; j++)
		{
			if (temp < score[i][j])
			{
				temp = score[i][j];
			}
		}
		if (highall < temp)
		{
			highall = temp;
		}
		printf("%d���� �ְ� ������ %d�Դϴ�.\n", i + 1, temp);
	}
	printf("������ �ְ� ������ %d�Դϴ�.\n", highall);
}
void Lowscore()
{
	int temp;
	int lowall = 100;
	for (int i = 0; i < CLASS; i++)
	{
		temp = score[i][0];
		for (int j = 1; j < Student; j++)
		{
			if (temp > score[i][j])
			{
				temp = score[i][j];
			}
		}
		if (lowall > temp)
		{
			lowall = temp;
		}
		printf("%d���� ���� ������ %d�Դϴ�.\n", i + 1, temp);
	}
	printf("������ ���� ������ %d�Դϴ�.\n", lowall);
}
void getscore()
{
	for (int i = 0; i < CLASS; i++)
	{
		printf("%d�� \n ", i + 1);
		for (int j = 0; j < Student; j++)
		{
			printf("%d   ", score[i][j]);
		}
		printf("\n");
	}
	Highscore();
	Lowscore();
	Avarage();
}