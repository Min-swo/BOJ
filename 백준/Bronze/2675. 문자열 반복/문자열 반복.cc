#include <iostream>
#include <string>
#include <stdlib.h>
using namespace std;


int main(void)
{
	ios::sync_with_stdio(false); 
	cin.tie(NULL);
	
	int t;
	cin >> t;
	
	int r, len;
	string str;
	for(int i = 0; i < t; i++)
	{
		cin >> r;
		cin.ignore();
		cin >> str;
		
		len = str.length();
		for(int j = 0; j < len; j++)
		{
			for(int k = 0; k < r; k++)
				cout << str[j];
		}
		cout << "\n";
		
	}
	
	return 0;
}