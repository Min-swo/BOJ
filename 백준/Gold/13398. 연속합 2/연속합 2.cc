#include <iostream>
using namespace std;

#define MAX 100001

long long seq[MAX];
long long dp[MAX][2];

int main(void)
{
    int n, max;
    cin >> n;
    for(int i = 1; i <= n; i++)
        cin >> seq[i];

    dp[1][0] = seq[1];
    dp[1][1] = -1000;
    if(dp[1][0] > 0)
        dp[2][0] = dp[1][0] + seq[2];
    else
        dp[2][0] = seq[2];
    dp[2][1] = seq[2];
    for(int i = 3; i <= n; i++)
    {
        if(dp[i-1][0] > 0)
            dp[i][0] = dp[i-1][0] + seq[i];
        else
            dp[i][0] = seq[i];

        if(dp[i-1][1] > dp[i-2][0])
            dp[i][1] = dp[i-1][1] + seq[i];
        else
            dp[i][1] = dp[i-2][0] + seq[i];
    }

    max = -1000;
    for(int i = 1; i <= n; i++)
    {
        for(int j = 0; j < 2; j++)
        {
            if(max < dp[i][j])
                max = dp[i][j];
        }
    }

    cout << max << "\n";
    return 0;
}