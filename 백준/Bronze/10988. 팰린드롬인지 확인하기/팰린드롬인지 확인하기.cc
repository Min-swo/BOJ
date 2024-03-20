#include <iostream>
#include <string>
#include <stdlib.h>
using namespace std;


int main(void)
{
	ios::sync_with_stdio(false); 
	cin.tie(NULL);
	
	string str;
	cin >> str;
	
	int len = str.length();
	
	int ans = 1;
	for(int i = 0; i < len / 2; i++)
	{
		if(str[i] != str[len-1-i])
			ans = 0;
	}
	
	cout << ans;
	return 0;
}