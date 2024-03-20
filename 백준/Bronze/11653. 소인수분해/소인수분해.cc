#include <iostream>
using namespace std;

int main(void)
{
	int n;
	cin >> n;
	
	int ftr;
	while(1)
	{
		if(n == 1)
			break;
		
		for(int i = 2; i <= n; i++)
		{
			if(n % i == 0)
			{
				n = n / i;
				cout << i << "\n";
				break;
			}
		}
	}

}