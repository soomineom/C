#include <stdio.h>

int main()
{
	char num[10];
	int change = 65;
	int result = 0;

	printf("�빮�� 10���� �Է��ϼ���\n");

	for (int i = 0; i < 10; i++) {
		scanf(" %c", &num[i]);

	}

	for (int j = 0; j < 10; j++)
	{
		for (int z = 0; z < 26; z++)
		{

			if (num[j] == change) {
				num[j] = z + 1;
			}
			change++;
		}
		change = 65;
	}

	printf("�ƽ�Ű�ڵ� ��ȯ��");
	for (int k = 0; k<10; k++)
	{
		result += num[k];
		printf(" %d", num[k]);

	}
	printf(" �� :%d\n", result);
	return 0;
}