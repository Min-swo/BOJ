#include <iostream>
using namespace std;

int main(void)
{
	int paper[100][100];
	for(int i = 0; i < 100; i++)
	{
		for(int j = 0; j < 100; j++)
		{
			paper[i][j] = 0;
		}
	}
	
	int n;
	cin >> n;
	
	int x, y;
	for(int i = 0; i < n; i++)
	{
		cin >> x >> y;
		for(int j = x; j < x+10; j++)
		{
			for(int k = y; k < y+10; k++)
				paper[j][k] = 1;
		}
	}
	
	int ans = 0;
	for(int i = 0; i < 100; i++)
	{
		for(int j = 0; j < 100; j++)
		{
			if(paper[i][j])
				ans++;
		}
	}
	
	cout << ans << "\n";
}