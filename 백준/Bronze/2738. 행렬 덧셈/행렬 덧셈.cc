#include <iostream>
#include <string>
using namespace std;

#define K 100

int main(void)
{
	int aMtx[K][K];
	int bMtx[K][K];
	int n, m;
	
	cin >> n >> m;
	
	for(int i = 0; i < n; i++)
	{
		for(int j = 0; j < m; j++)
		{
			cin >> aMtx[i][j];
		}
	}
	
	for(int i = 0; i < n; i++)
	{
		for(int j = 0; j < m; j++)
		{
			cin >> bMtx[i][j];
		}
	}
	
	for(int i = 0; i < n; i++)
	{
		for(int j = 0; j < m; j++)
		{
			cout << aMtx[i][j] + bMtx[i][j] << " ";
		}
		cout << "\n";
	}
	
}