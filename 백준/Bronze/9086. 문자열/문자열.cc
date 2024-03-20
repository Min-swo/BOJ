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
	cin.ignore();
	
	int tmp;
	string str;
	for(int i = 0; i < t; i++)
	{
		getline(cin, str);
		tmp = str.length() - 1;
		cout << str[0] << str.at(tmp) << "\n";
	}	
	
	return 0;
}