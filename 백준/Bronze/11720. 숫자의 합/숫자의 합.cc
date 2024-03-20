#include <iostream>
#include <string>
#include <stdlib.h>
using namespace std;


int main(void)
{
	ios::sync_with_stdio(false); 
	cin.tie(NULL);
	
	int n;
	cin >> n;
	
	char tmp;
	int num;
	int sum = 0;
	for(int i = 0; i < n; i++)
	{
		cin >> tmp;
		num = tmp - '0';
		sum = sum + num;
	}
		
	cout << sum;
}