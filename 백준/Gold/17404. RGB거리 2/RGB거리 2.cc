#include <iostream>
using namespace std;

#define MAX 1001

int price[MAX][3];
int dp[3][MAX][3];

int main(void)
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int n, min;
    cin >> n;

    for(int i = 1; i <= n; i++)
    {
        for(int j = 0; j < 3; j++)
            cin >> price[i][j];
    }

    for(int k = 0; k < 3; k++)
    {
        for(int i = 0; i < 3; i++)
            dp[k][1][i] = price[1][k];
        dp[k][2][(k+1)%3] = dp[k][1][0] + price[2][(k+1)%3];
        dp[k][2][(k+2)%3] = dp[k][1][0] + price[2][(k+2)%3];
        if(dp[k][2][(k+1)%3] < dp[k][2][(k+2)%3])
            dp[k][3][k] = dp[k][2][(k+1)%3] + price[3][k];
        else
            dp[k][3][k] = dp[k][2][(k+2)%3] + price[3][k];
        dp[k][3][(k+1)%3] = dp[k][2][(k+2)%3] + price[3][(k+1)%3];
        dp[k][3][(k+2)%3] = dp[k][2][(k+1)%3] + price[3][(k+2)%3];

        for(int i = 4; i <= n; i++)
        {
            for(int j = 0; j < 3; j++)
            {
                if(dp[k][i-1][(j+1)%3] < dp[k][i-1][(j+2)%3])
                    dp[k][i][j] = dp[k][i-1][(j+1)%3] + price[i][j];
                else
                    dp[k][i][j] = dp[k][i-1][(j+2)%3] + price[i][j];
            }
        }  
    }
    // for(int k = 0; k < 3; k++)
    // {
    //     for(int i = 1; i <= n; i++)
    //     {
    //         for(int j = 0; j < 3; j++)
    //         {
    //            cout << dp[k][i][j] << " ";
    //         }
    //         cout << "\n";
    //     }
    //     cout << "\n";
    // }

    min = MAX * MAX;
    for(int k = 0; k < 3; k++)
    {
        for(int j = 0; j < 3; j++)
        {
            if(k != j)
            {
                if(min > dp[k][n][j])
                    min = dp[k][n][j];
            }
        }
    }
    cout << min << "\n";
    return 0;
}