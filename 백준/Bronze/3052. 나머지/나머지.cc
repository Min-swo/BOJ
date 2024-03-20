#include <iostream>
using namespace std;


int main(void)
{
	ios::sync_with_stdio(false); 
	cin.tie(NULL);
	
	int arr[42];
	for(int i = 0; i < 42; i++)
	{
		arr[i] = 0;
	}
	
	int tmp;
	for(int i = 0; i < 10; i++)
	{
		cin >> tmp;
		arr[tmp % 42] = 1;
	}
	
	int cnt = 0;
	for(int i = 0; i < 42; i++)
	{
		if(arr[i])
			cnt++;
	}
	
	cout << cnt;
	return 0;
}