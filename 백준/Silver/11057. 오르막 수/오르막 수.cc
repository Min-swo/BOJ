#include <iostream>
using namespace std;

#define MAX 1001
#define DIV 10007

long long dp[MAX][10];

int main(void)
{
    int n;
    cin >> n;

    for(int i = 1; i <= n; i++)
    {
        for(int j = 0; j < 10; j++)
            dp[i][j] = 0;
    }
    for(int i = 0; i < 10; i++)
        dp[1][i] = 1;

    for(int i = 2; i <= n; i++)
    {
        for(int j = 0; j < 10; j++)
        {
            for(int k = j; k >= 0; k--)
            {
                dp[i][j] = (dp[i][j] + dp[i-1][k] % DIV) % DIV;
            }
        }
    }

    long long ans = 0;
    for(int i = 0; i < 10; i++)
        ans = (ans + dp[n][i] % DIV) % DIV;

    cout << ans % DIV << "\n";
    /*
    [1]
    

    [2]
    0 = > dp[1][0]
    1 = > dp[1][0] + dp[1][1]
    */
}