#include <iostream>
using namespace std;


int main(void)
{
	ios::sync_with_stdio(false); 
	cin.tie(NULL);
	
	int prst[31];
	for(int i = 0; i < 31; i++)
		prst[i] = 0;
	
	int tmp;
	for(int i = 0; i < 28; i++)
	{
		cin >> tmp;
		prst[tmp] = 1;
	}
	
	for(int i = 1; i <= 30; i++)
	{
		if(!prst[i])
			cout << i << "\n";
	}
	
	
	
	return 0;
}