#include <iostream>
using namespace std;

#define K 10001

int main(void)
{
	ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(NULL);
	
	int n;
	cin >> n;
	
	int cnt[K];
	for(int i = 0 ; i < K; i++)
		cnt[i] = 0;
	
	int tmp;
	for(int i = 0; i < n; i++)
	{
		cin >> tmp;
		cnt[tmp]++;
	}
	
	for(int i = 1; i < K; i++)
	{
		while(cnt[i] > 0)
		{
			cout << i << "\n";
			cnt[i]--;
		}
	}
}