#include <iostream>
#include <algorithm>
using namespace std;

int* seq, *dp;

int main(void)
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int n;
    cin >> n;

    seq = new int[n];
    dp = new int[n];

    for(int i = 0; i < n; i++)
        cin >> seq[i];

    dp[n-1] = seq[n-1];
    for(int i = n - 2; i >= 0; i--)
    {
        if(seq[i] > seq[i] + dp[i+1])
            dp[i] = seq[i];
        else
            dp[i] = seq[i] + dp[i+1];
    }

    sort(dp, dp+n);
    
    cout << dp[n-1] << "\n";
}