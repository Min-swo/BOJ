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
	int n;
	cin >> n;
	
	int k;
	int cnt = 0;
	for(int i = 0; i < n; i++)
	{
		cin >> k;
		
		if(isPrime(k))
			cnt++;
	}
	
	cout << cnt << "\n";
}