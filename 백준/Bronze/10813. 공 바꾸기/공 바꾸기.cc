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
		bsk[i] = i;
	
	int fst, lst;
	for(int i = 0; i < m; i++)
	{
		cin >> fst >> lst;
		int tmp;
		tmp = bsk[fst];
		bsk[fst] = bsk[lst];
		bsk[lst] = tmp;
	}
	
	for(int i = 1; i <= n; i++)
		cout << bsk[i] << " ";
	return 0;
}