#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

int main(void)
{
	int n, rst;
	int idx[100];
	for (int i = 0; i < 100; i++)
		idx[i] = -1;

	scanf("%d %d", &n, &rst);
	for (int i = 0; i < n; i++)
		scanf("%d", &idx[i]);

	int sum = 0;
	int ans = 0;
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < n; j++)
		{
			if (i < j)
			{
				for (int k = 0; k < n; k++)
				{
					if (k > j)
					{
						sum = idx[i] + idx[j] + idx[k];
						if (sum <= rst && ans <= sum)
							ans = sum;
					}
				}
			}
			}
			
		
	}

	printf("%d", ans);

	return 0;
}