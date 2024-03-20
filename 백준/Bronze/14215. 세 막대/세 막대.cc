#include <iostream>
using namespace std;

int main(void)
{
	int s[3];
	cin >> s[0] >> s[1] >> s[2];
	
	int idx;
	int max = -1;
	for(int i = 0; i < 3; i++)
	{
		if(max < s[i])
		{
			max = s[i];
			idx = i;
		}
	}
	
	int sum = 0;
	for(int i = 0; i < 3; i++)
	{
		if(i != idx)
			sum += s[i];
	}
	
	while(!(max < sum))
		max--;
	
	cout << max + sum << "\n";
}