#include <iostream>
using namespace std;

#define MAX 100001

int* dp;

int main(void)
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int n, min, tmp;
    cin >> n;

    dp = new int[n+1];
    dp[1] = 1;
    dp[2] = 2;
    dp[3] = 3;
    for(int i = 2; i * i <= n; i++)
    {
        for(int j = i * i; j < (i+1) * (i+1) && j <= n; j++)
        {
            if(j == i * i)
                dp[j] = 1;
            else
            {
                min = MAX;
                for(int k = i; k >= 2; k--)
                {
                    tmp = dp[k * k] + dp[j - k * k];
                    if(min > tmp)
                        min = tmp;
                }
                dp[j] = min;
            }
        }
    }
    cout << dp[n] << "\n";
}