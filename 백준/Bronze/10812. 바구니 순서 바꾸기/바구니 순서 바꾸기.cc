#include <iostream>
#include <string>
#include <stdlib.h>
using namespace std;


int main(void)
{
	ios::sync_with_stdio(false); 
	cin.tie(NULL);
	
	int n, m;
	cin >> n >> m;
	
	int* bsk = new int[n+1];
	for(int i = 0; i < n+1; i++)
		bsk[i] = i;
	
	int* bgnToMid = new int[n+1];
	int* midToEnd = new int[n+1];
	
	int idx;
	int bgn, mid, end;
	for(int i = 0; i < m; i++)
	{
		cin >> bgn >> end >> mid;
		// 1 2 3 4 5 6 7 8 9
		idx = 0;
		for(int j = bgn; j < mid; j++)
		{
			bgnToMid[idx++] = bsk[j];
		}
		
		idx = 0;
		for(int j = mid; j <= end; j++)
		{
			midToEnd[idx++] = bsk[j];
		}
		
		idx = 0;
		for(int j = 0; j < end - mid + 1; j++)
		{
			bsk[bgn+idx] = midToEnd[j];
			idx++;
		}
		for(int j = 0; j < mid - bgn; j++)
		{
			bsk[bgn+idx] = bgnToMid[j];
			idx++;
		}
		
		// for(int i = 1; i <= n; i++)
		// 	cout << bsk[i] << " ";
		// cout << "\n";
	}
	
	for(int i = 1; i <= n; i++)
		cout << bsk[i] << " ";
	
	return 0;
}