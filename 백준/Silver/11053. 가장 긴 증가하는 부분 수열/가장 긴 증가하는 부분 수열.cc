#include <iostream>
#include <algorithm>
using namespace std;

int* seq;
int* dp;

int main(void)
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int n, tmp;
    cin >> n;

    seq = new int[n];
    dp = new int[n];
    for(int i = 0; i < n; i++)
        cin >> seq[i];
    for(int i = 0; i < n; i++)
        dp[i] = 1;

    int max;
    for(int i = n - 2; i >= 0; i--)
    {
        max = -1;
        for(int j = i + 1; j < n; j++)
        {
            if(seq[i] < seq[j])
            {
                tmp = dp[j] + 1;
                if(max < tmp)
                    max = tmp;
            }
        }
        if(max != -1)
            dp[i] = max;
    }
    sort(dp, dp + n);
    // for(int i = 0; i < n; i++)
    //     cout << dp[i] << " ";
    // cout << "\n";
    cout << dp[n-1] << "\n";
}