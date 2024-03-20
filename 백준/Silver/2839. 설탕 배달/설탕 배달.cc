#include <iostream>
using namespace std;

int main(void)
{
	int n;
	cin >> n;
	
	int df = n / 5;
	int dt = n / 3;
	
	int ans = -1;
	for(int i = df; i >= 0 && ans == -1; i--)
	{
		for(int j = dt; j >= 0 && ans == -1; j--)
		{
			if(i * 5 + j * 3 == n)
				ans = i + j;
		}
	}
	
	cout << ans << "\n";
}