#include <iostream>
#include <string>
#include <stdlib.h>
using namespace std;

int ChangeIdx(int ch)
{
	if(ch >= 97)
		return ch - 97;
	else
		return ch - 65;
}


int main(void)
{
	ios::sync_with_stdio(false); 
	cin.tie(NULL);

	string str;
	cin >> str;

	int cnt[26];
	for(int i = 0; i < 26; i++)
		cnt[i] = 0;
	
	for(auto x : str)
	{
		cnt[ChangeIdx(int(x))]++;
	}
	
	
	int max = 0;
	for(auto x : cnt)
	{
		if(max < x)
		{
			max = x;
		}	
	}
	
	int same = 0;
	int idx = -1;
	for(int i = 0; i < 26; i++)
	{
		if(max == cnt[i])
		{
			if(idx != -1)
				same = 1;
			idx = i;
		}
	}
	
	if(same)
		cout << "?";
	else
		cout << char(idx + 65);
	
	return 0;
}