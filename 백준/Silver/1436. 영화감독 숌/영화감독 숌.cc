#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

int pow(int d, int n);					//pow func

int main(void)
{
	int n;
	scanf("%d", &n);

	int k = 1;
	int j;
	int arr[10000];
	int p = 0;
	int q;
	int ck = 1;
	int ck2;
	int r;
	int c;
	for (int i = 666; ck == 1; i++)
	{
		j = 1;
		while (i / pow(10, j) != 0)
			j++;
		j--;

		r = i;
		c = j;
		while (c >= 0)							// reserve each point
		{
			arr[c] = r / pow(10, c);
			r = r % pow(10, c);
			c--;
		}

		q = 0;
		ck2 = 1;
		while (q + 2 <= j && ck2 == 1)			// 666 check
		{
			if (arr[q] == 6)
			{
				if (arr[q + 1] == 6)
				{
					if (arr[q + 2] == 6)
					{
						p++;
						ck2 = 0;
					}
				}
			}
			q++;
		}

		if (n == p)
		{
			printf("%d", i);
			ck = 0;
		}
			
	}
}

int pow(int d, int n)
{
	int rslt = 1;
	for (int i = 0; i < n; i++)
	{
		rslt = rslt * d;
	}

	return rslt;
}