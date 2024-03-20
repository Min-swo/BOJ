#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
#define SIZE 50

int main(void)
{
	char chess[SIZE][SIZE];

	int s_x, s_y;
	scanf("%d %d", &s_x, &s_y);
	fflush(stdin);

	for (int i = 0; i < s_x; i++)
	{
		for (int j = 0; j < s_y; j++)
		{
			scanf(" %c", &chess[i][j]);
		}
	}

	char blc[8][8];
	char wht[8][8];
	for (int i = 0; i < 8; i+=2)
	{
		for (int j = 0; j < 8; j+=2)
		{
			blc[i][j] = 'B';
			blc[i][j + 1] = 'W';
			wht[i][j] = 'W';
			wht[i][j + 1] = 'B';
		}
	}
	for (int i = 1; i < 8; i += 2)
	{
		for (int j = 0; j < 8; j += 2)
		{
			blc[i][j] = 'W';
			blc[i][j + 1] = 'B';
			wht[i][j] = 'B';
			wht[i][j + 1] = 'W';
		}
	}

	char tst[SIZE][SIZE];
	int b_lst = 64;
	int w_lst = 64;
	int b_crt;
	int b_wrn;
	int w_crt;
	int w_wrn;
	int n, m;
	for (int x = 0; x + 7 < s_x; x++)
	{
		for (int y = 0; y + 7 < s_y; y++)
		{
			n = 0;
			for (int i = x; i < x + 8; i++)
			{
				m = 0;
				for (int j = y; j < y + 8; j++)
				{
					tst[n][m] = chess[i][j];
					m++;
				}
				n++;
			}
			b_crt = 0;
			b_wrn = 0;
			for (int i = 0; i < 8; i++)
			{
				for (int j = 0; j < 8; j++)
				{
					if (tst[i][j] == blc[i][j])
						b_crt++;
					else if(tst[i][j] != blc[i][j])
						b_wrn++;
				}
			}
			if (b_wrn <= b_lst)
			{
				b_lst = b_wrn;
			}
			w_crt = 0;
			w_wrn = 0;
			for (int i = 0; i < 8; i++)
			{
				for (int j = 0; j < 8; j++)
				{
					if (tst[i][j] == wht[i][j])
						w_crt++;
					else
						w_wrn++;
				}
			}
			if (w_wrn <= w_lst)
			{
				w_lst = w_wrn;
			}
			
		}
	}
	
	if (w_lst < b_lst)
		printf("%d", w_lst);
	else
		printf("%d", b_lst);


	/* 8*8 - > Starting point = Black, White
	All posible point compare -> take different count! less count -> ans*/

	return 0;
}