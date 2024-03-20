#include <iostream>
using namespace std;

int main(void)
{
	int n, k;
	cin >> n >> k;
	
	int ans = 0;
	int cnt = 0;
	for(int i = 1; i <= n; i++)
	{
		if(n % i == 0)
		{
			cnt++;
			if(k == cnt)
			{
				ans = i;
				break;
			}
		}
	}
	
	cout << ans << "\n";
}