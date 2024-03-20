#include <iostream>
using namespace std;

int main(void)
{
	int s[3];
	int max;
	int idx;
	int sum;
	while(1)
	{
		cin >> s[0] >> s[1] >> s[2];
		if(s[0] == 0 && s[1] == 0 && s[2] == 0)
			break;
		
		max = -1;
		idx = -1;
		sum = 0;
		for(int i = 0; i < 3; i++)
		{
			if(max < s[i])
			{
				max = s[i];
				idx = i;
			}
		}
		
		for(int i = 0; i < 3; i++)
		{
			if(i != idx)
				sum += s[i];
		}
		//cout << sum << "\n" << max << "\n";
		
		if(sum > max)
		{
			if(s[0] == s[1] && s[1] == s[2])
				cout << "Equilateral\n";
			else if(s[0] == s[1] || s[1] == s[2] || s[0] == s[2])
				cout << "Isosceles\n";
			else
				cout << "Scalene\n";
		}
		else
		{
			cout << "Invalid\n";
		}
		
		
	}
}