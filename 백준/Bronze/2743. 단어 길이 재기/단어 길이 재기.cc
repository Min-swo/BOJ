#include <iostream>
#include <string>
using namespace std;


int main(void)
{
	ios::sync_with_stdio(false); 
	cin.tie(NULL);
	
	string str;
	getline(cin, str);

	
	cout << str.length();
	
	
	return 0;
}