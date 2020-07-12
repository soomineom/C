#include <stdio.h>
#include <string.h>

struct string
{
	int score;
	char string[10000];
};
int score(char *arr)
{
	int score = 0;
	int i = 0;
	for (; arr[i] != 0; i++)
	{
		if ('A' <= arr[i] && arr[i] <= 'Z')score += (arr[i] - 64);
		else if ('a' <= arr[i] && arr[i] <= 'z')score += (arr[i] - 96);
		else score += 0;
	}
	return score;
}

int main(void)
{
	char string[10000];
	struct string string[10];
	int score = 0;
	int i = 0;
	int j = 0;
	for (; i < 10; i++)
	{
		printf("���ڸ� �Է����ּ���\n ");
		gets_s(&string, sizeof(string));
		score = scorevalue(string);
		strcpy_s(string[i].string, 100, string);
		string[i].score = score;
	}
	i = 0;
	for (; i < 10; i++)
	{
		for (j = i; j < 10; j++)
		{
			if (string[j].score > string[i].score)
			{
				int tempnum;
				tempnum = grade[i].score;
				string[i].score = string[j].score;
				string[j].score = tempnum;

				char tempch[100];
				strcpy_s(tempch, 100, grade[i].string);
				strcpy_s(string[i].string, 100, string[j].string);
				strcpy_s(string[j].string, 100, tempch);

				if (j != 0)
					j -= 2;
			}
		}
		printf("%d�� : %s\t %d��\n", i + 1, string[i].string, string[i].score);
	}
	return 0;
}
