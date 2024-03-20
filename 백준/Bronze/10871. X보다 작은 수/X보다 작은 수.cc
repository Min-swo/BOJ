#include <iostream>
using namespace std;


int main(void)
{
	ios::sync_with_stdio(false); 
	cin.tie(NULL);
	
	int n, x;
	cin >> n >> x;
	
	int tmp;
	for(int i = 0; i < n; i++)
	{
		cin >> tmp;
		if(tmp < x)
			cout << tmp << " ";
	}
	
	return 0;
}