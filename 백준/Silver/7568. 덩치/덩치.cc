#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

int main(void)
{
	int n;
	int info[50][2];
	scanf("%d", &n);
	for (int i = 0; i < n; i++)
	{
		scanf("%d %d", &info[i][0], &info[i][1]);
	}

	int scr[50];
	for (int i = 0; i < 50; i++)
		scr[i] = 0;

	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < n; j++)
		{
			if (info[i][0] < info[j][0])
				if (info[i][1] < info[j][1])
					scr[i]++;
		}
	}

	for (int i = 0; i < n; i++)
	{
		printf("%d ", scr[i] + 1);
	}

}
