#include <iostream>
#include <string>
using namespace std;


int main(void)
{
	ios::sync_with_stdio(false); 
	cin.tie(NULL);
	
	string str;
	getline(cin, str);
	
	int idx;
	cin >> idx;
	
	cout << str.at(idx-1);
	
	
	return 0;
}