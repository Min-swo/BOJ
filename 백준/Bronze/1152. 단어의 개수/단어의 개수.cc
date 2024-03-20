#include <iostream>
#include <string>
#include <stdlib.h>
using namespace std;


int main(void)
{
	ios::sync_with_stdio(false); 
	cin.tie(NULL);
	
	string str;
	getline(cin, str);
	
	int cnt = 0;
	int len = str.length();
	for(int i = 1; i < len-1; i++)
	{
		
		if(str.at(i) == ' ')
			cnt++;
	}
	
	if(len > 1)
		cout << cnt+1;
	else if(len == 1)
	{
		if(str.at(0) == ' ')
			cout << 0;
		else
			cout << 1;
	}
	else
		cout << 0;
	
		
	
	return 0;
}