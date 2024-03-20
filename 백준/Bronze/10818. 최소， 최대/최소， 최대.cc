#include <iostream>
using namespace std;


int main(void)
{
	ios::sync_with_stdio(false); 
	cin.tie(NULL);
	
	int n;
	cin >> n;
	
	int tmp;
	int max = -1000000;
	int min = 1000000;
	
	for(int i = 0; i < n; i++)
	{
		cin >> tmp;
		if(tmp > max)
			max = tmp;
		if(tmp < min)
			min = tmp;
	}
	
	cout << min << " " << max;
	
	return 0;
}