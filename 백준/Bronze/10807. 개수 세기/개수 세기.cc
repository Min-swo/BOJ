#include <iostream>
using namespace std;


int main(void)
{
	ios::sync_with_stdio(false); 
	cin.tie(NULL);
	
	int n, v;
	cin >> n;
	
	int arr[100];
	
	for(int i = 0; i < n; i++)
		cin >> arr[i];
	
	cin >> v;
	
	int cnt = 0;
	for(int i = 0; i < n; i++)
	{
		if(arr[i] == v)
			cnt++;
	}
	
	cout << cnt;
	
	return 0;
}