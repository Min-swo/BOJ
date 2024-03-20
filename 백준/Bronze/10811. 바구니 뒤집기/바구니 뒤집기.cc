#include <iostream>
using namespace std;

void ChgBsk(int fst, int lst, int (&bsk)[101])
{
	int tmp = bsk[fst];
	bsk[fst] = bsk[lst];
	bsk[lst] = tmp;
}

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
		int rng = lst - fst + 1;
		if(rng % 2)
			rng++;
			
		for(int j = 0; j < rng / 2; j++)
			ChgBsk(fst+j, lst-j, bsk);
	}
	
	for(int i = 1; i <= n; i++)
		cout << bsk[i] << " ";
	return 0;
}