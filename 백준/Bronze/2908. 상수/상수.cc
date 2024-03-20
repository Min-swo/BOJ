#include <iostream>
#include <string>
#include <stdlib.h>
#include <algorithm>
using namespace std;


int main(void)
{
	ios::sync_with_stdio(false); 
	cin.tie(NULL);
	
	string a, b;
	cin >> a >> b;
	
	reverse(a.begin(), a.end());
	reverse(b.begin(), b.end());

	int aInt, bInt;
	aInt = stoi(a);
	bInt = stoi(b);
	
	if(aInt > bInt)
		cout << aInt;
	else
		cout << bInt;
	return 0;
}