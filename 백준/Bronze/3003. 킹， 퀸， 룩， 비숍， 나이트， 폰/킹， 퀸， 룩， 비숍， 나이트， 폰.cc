#include <iostream>
#include <string>
#include <stdlib.h>
using namespace std;


int main(void)
{
	ios::sync_with_stdio(false); 
	cin.tie(NULL);
	
	int org[] = {1, 1, 2, 2, 2, 8};
	int crt[6];
	int ans[6];
	
	for(int i = 0; i < 6; i++)
		cin >> crt[i];
	
	for(int i = 0; i < 6; i++)
		ans[i] = org[i] - crt[i];
		
	for(auto x : ans)
		cout << x << " ";
	
	return 0;
}