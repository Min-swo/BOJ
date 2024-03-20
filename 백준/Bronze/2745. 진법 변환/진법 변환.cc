#include <iostream>
#include <cmath>
using namespace std;


int main(void)
{
	string str;
	int n;
	cin >> str >> n;
	
	int res = 0;
	int len = str.length();
	for(int i = 0; i < len; i++)
	{
		if(int(str[i]) > 64)
			res = res + (int(str[i]) - 55) * pow(n, len-i-1);
		else
			res = res + (int(str[i]) - 48) * pow(n, len-i-1);
	}
	
	cout << res << "\n";
	
}