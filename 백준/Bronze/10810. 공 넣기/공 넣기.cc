#include <iostream>
using namespace std;


int main(void)
{
	ios::sync_with_stdio(false); 
	cin.tie(NULL);
	
	int n, m;
	int bsk[101];
	
	cin >> n >> m;
	for(int i = 1; i <= n; i++)
		bsk[i] = 0;
	
	int fst, lst, num;
	for(int i = 0; i < m; i++)
	{
		cin >> fst >> lst >> num;
		for(int j = fst; j <= lst; j++)
			bsk[j] = num;
	}
	
	for(int i = 1; i <= n; i++)
		cout << bsk[i] << " ";
	return 0;
}