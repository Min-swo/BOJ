#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

int main(void)
{
	int dgtsum, gen;
	scanf("%d", &dgtsum);

	int ck = 0;
	int q = 0;
	int ans;
	for(int a = 0; a < 10 && ck == 0; a++)
	{ 
		for (int b = 0; b < 10 && ck == 0; b++)
		{
			for (int c = 0; c < 10 && ck == 0; c++)
			{
				for (int i = 0; i < 10 && ck == 0; i++)
				{
					for (int j = 0; j < 10 && ck == 0; j++)
					{
						for (int k = 0; k < 10 && ck == 0; k++)
						{
							if (dgtsum ==100001*a+ 10001*b + 1001 * c+ 101 * i + 11 * j + 2 * k && ck == 0)
							{
								ans = 100000*a+ 10000*b+1000*c+ 100 * i + 10 * j + k;
								printf("%d", ans);
								ck = 1;
							}
						}
					}
				}
			}
		}

	}
	if (ck == 0)
		printf("%d", ck);

	return 0;

}