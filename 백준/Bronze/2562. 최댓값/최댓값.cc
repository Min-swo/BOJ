#include <iostream>
using namespace std;


int main(void)
{
	ios::sync_with_stdio(false); 
	cin.tie(NULL);
	
	
	int tmp, idx;
	int max = 0;	
	for(int i = 0; i < 9; i++)
	{
		cin >> tmp;
		if(tmp > max)
		{
			max = tmp;
			idx = i+1;
		}
		
	}
	
	cout << max << "\n" << idx;
	
	return 0;
}