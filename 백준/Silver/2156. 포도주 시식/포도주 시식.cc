#include <iostream>
using namespace std;

#define MAX 10001

long long amount[MAX];
long long dp[MAX][3];

int main(void)
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int n, max;
    cin >> n;
    for(int i = 1; i <= n; i++)
        cin >> amount[i];

    /*
    1 2 3 4 5
    dp[1][1] = score[1]

    dp[2][1] = score[2]
    dp[2][2] = dp[1][1] + dp[2][1];

    dp[3][1] = dp[1][1] + score[3];
    dp[3][2] = dp[2][1] + score[3];


    dp[i][1] = score[i] + dp[i-2 ~ 1][1~3]
    dp[i][2] = score[i] + dp[i-1][1]
    */

    dp[1][1] = amount[1];
    dp[2][1] = amount[2];
    dp[2][2] = amount[2] + dp[1][1];
    for(int i = 3; i <= n; i++)
    {
        for(int j = 1; j <= 2; j++)
        {
            max = -1;
            if(j == 1)
            {
                for(int k = i - 2; k >= 1; k--)
                {
                    for(int m = 1; m <= 2; m++)
                    {
                        if(max < dp[k][m])
                            max = dp[k][m];
                    }
                }
                dp[i][j] = amount[i] + max;
            }
            else
            {
                dp[i][j] = amount[i] + dp[i-1][j-1];
            }
        }
    }

    max = -1;
    for(int i = 1; i <= n; i++)
    {
        for(int j = 1; j <= 2; j++)
        {
            if(max < dp[i][j])
                max = dp[i][j];
        }
    }
    cout << max << "\n";
}