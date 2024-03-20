#include <iostream>
#include <cmath>
using namespace std;

int isPrime(int k)
{
	if(k == 1)
		return 0;
	
	for(int i = 2; i <= sqrt(k); i++)
	{
		if(k % i == 0)
			return 0;
	}
	
	return 1;
}

int main(void)
{
	int m, n;
	cin >> m >> n;
	
	int min;
	int sum = 0;
	for(int i = m; i <= n; i++)
	{
		if(isPrime(i))
		{
			if(sum == 0)
				min = i;
			
			sum += i;
		}
	}
	
	if(sum == 0)
		cout << -1 << "\n";
	else
		cout << sum << "\n" << min << "\n";
	
}