#include <iostream>
using namespace std;

#define DIV 1000000000

long long dp[201][201];

int main(void)
{
    int n, k;
    cin >> n >> k;

    for(int i = 0; i <= n; i++)
    {
        for(int j = 0; j <= k; j++)
            dp[i][j] = 0;
    }
    /*
    [20 2]
    0 20
    1 19
    2 18
    3 17
    ...
    19 1
    20 0
    [5 2] -> [5 1] + [4 1] + ... + [1 1] + [0 1] = 6
    [5 3] -> [5 2] + [4 2] + [3 2] + [2 2] = 6+5+4+3 = 18
    [4 3] -> [4 2] + [3 2] + [2 2] = 12
    [3 3] -> [3 2] + [2 2] + [1 2] + [0 2]
    
    [6 2] -> [6 1] + [5 1] + ... + [1 1] + [0 1]
    [6 3] -> [6 2] + [5 2] + [4 2] + [3 2] + [2 2] + [1 2] + [0 2]

    [2 2]
    0 2
    1 1
    2 0

    [1 10]

    */
    for(int i = 1; i <= k; i++)
        dp[0][i] = 1;
    for(int i = 1; i <= n; i++)
        dp[i][1] = 1;

    for(int i = 2; i <= k; i++)
    {
        for(int j = 1; j <= n; j++)
            dp[j][i] = (dp[j][i-1] % DIV + dp[j-1][i] % DIV) % DIV;
    }

    cout << dp[n][k] % DIV << "\n";
}