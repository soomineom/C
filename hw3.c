#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <time.h>
#include <stdlib.h>

#define CLASS 4
#define Student 20

char *fname = "score.txt";
FILE *f;

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

	f = fopen(fname, "w");
	inputscore();
	getscore();

	upsort();
	getscore();

	downsort();
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

void upsort()
{
	for (int i = 0; i < CLASS; i++)
	{
		for (int j = 0; j < Student - 1; j++)
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
void downsort()
{
	for (int i = 0; i < CLASS; i++)
	{
		for (int j = 0; j < Student - 1; j++)
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
		fprintf(f, "%d반의 평균은 %d입니다.\n", i + 1, sum / Student);
		printf("%d반의 평균은 %d입니다.\n", i + 1, sum / Student);
	}
	fprintf(f, "모든반의 평균은 %d입니다.\n", sumall / Student * CLASS);
	printf("모든반의 평균은 %d입니다.\n", sumall / Student * CLASS);
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
		fprintf(f, "%d반의 최고 점수는 %d입니다.\n", i + 1, temp);
		printf("%d반의 최고 점수는 %d입니다.\n", i + 1, temp);
	}
	fprintf(f, "모든반의 최고 점수는 %d입니다.\n", highall);
	printf("모든반의 최고 점수는 %d입니다.\n", highall);
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
		fprintf(f, "%d반의 최저 점수는 %d입니다.\n", i + 1, temp);
		printf("%d반의 최저 점수는 %d입니다.\n", i + 1, temp);
	}
	fprintf(f, "모든반의 최저 점수는 %d입니다.\n", lowall);
	printf("모든반의 최저 점수는 %d입니다.\n", lowall);
}
void getscore()
{
	for (int i = 0; i < CLASS; i++)
	{
		fprintf(f, "%d반 \n ", i + 1);
		printf("%d반 \n ", i + 1);
		for (int j = 0; j < Student; j++)
		{
			fprintf(f, "%d   ", score[i][j]);
			printf("%d   ", score[i][j]);
		}
		fprintf(f, "\n");
		printf("\n");
	}
	Highscore();
	Lowscore();
	Avarage();

	fprintf(f, "\n");
	printf("\n");
}