#include <iostream>
#include <string>
#include <stdlib.h>
#include <algorithm>
using namespace std;


int main(void)
{
	ios::sync_with_stdio(false); 
	cin.tie(NULL);
	
	string str;
	while(!(getline(cin, str).eof()))
	{
		cout << str << "\n";
	}
	
	// for(int i = 0; i < 3; i++)
	// {
	// 	getline(cin, str);
	// 	cout << str << "\n";
	// }
	
	return 0;
}