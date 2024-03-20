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
	cin >> str;
	
	int sum = 0;
	string snd3 = "ABC";
	string snd4 = "DEF";
	string snd5 = "GHI";
	string snd6 = "JKL";
	string snd7 = "MNO";
	string snd8 = "PQRS";
	string snd9 = "TUV";
	string snd10 = "WXYZ";
	for(auto x : str)
	{
		if(snd3.find(x) < 4)
			sum = sum + 3;
		else if(snd4.find(x) < 4)
			sum = sum + 4;
		else if(snd5.find(x) < 4)
			sum = sum + 5;
		else if(snd6.find(x) < 4)
			sum = sum + 6;
		else if(snd7.find(x) < 4)
			sum = sum + 7;
		else if(snd8.find(x) < 4)
			sum = sum + 8;
		else if(snd9.find(x) < 4)
			sum = sum + 9;
		else if(snd10.find(x) < 4)
			sum = sum + 10;
	}
	
	cout << sum;
	
	return 0;
}