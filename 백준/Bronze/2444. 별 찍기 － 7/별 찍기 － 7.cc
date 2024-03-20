#include <iostream>
#include <string>
#include <stdlib.h>
using namespace std;


int main(void)
{
	ios::sync_with_stdio(false); 
	cin.tie(NULL);
	
	// 2(n-1) + 1
	
	int n;
	cin >> n;
	
	for(int i = 1; i <= n; i++)
	{
		for(int j = 0; j < n-i; j++)
			cout << " ";
		for(int k = 0; k < 2 * i - 1; k++)
			cout << "*";
		cout << "\n";
	}
	
	for(int i = n-1; i > 0; i--)
	{
		for(int j = 0; j < n-i; j++)
			cout << " ";
		for(int k = 0; k < 2 * i - 1; k++)
			cout << "*";
		cout << "\n";
	}
	
	return 0;
}