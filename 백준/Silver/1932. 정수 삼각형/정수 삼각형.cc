#include <iostream>
using namespace std;

#define MAX 501

long long tri[MAX][MAX];
long long dp[MAX][MAX];

int main(void)
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int n;
    cin >> n;
    for(int i = 1; i <= n; i++)
    {
        for(int j = 1; j <= i; j++)
            cin >> tri[i][j];
    }

    /*
    7
    3 8
    8 1 0
    2 7 4 4
    4 5 2 6 5
    */
    dp[1][1] = tri[1][1];
    dp[2][1] = tri[2][1] + dp[1][1];
    dp[2][2] = tri[2][2] + dp[1][1];
    for(int i = 3; i <= n; i++)
    {
        for(int j = 1; j <= i; j++)
        {
            if(j == 1)
                dp[i][j] = tri[i][j] + dp[i-1][j];
            else if(j == i)
                dp[i][j] = tri[i][j] + dp[i-1][j-1];
            else
            {
                if(dp[i-1][j-1] < dp[i-1][j])
                    dp[i][j] = tri[i][j] + dp[i-1][j];
                else
                    dp[i][j] = tri[i][j] + dp[i-1][j-1];
            }
        }
    }

    int max = -1;
    for(int i = 1; i <= n; i++)
    {
        if(max < dp[n][i])
            max = dp[n][i];
    }
    cout << max << "\n";

    // for(int i = 1; i <= n; i++)
    // {
    //     for(int j = 1; j <= i; j++)
    //         cout << dp[i][j] << " ";
    //     cout << "\n";
    // }
}