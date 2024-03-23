#include <iostream>
using namespace std;

#define MAX 100000

long long score[2][MAX];
long long dp[2][MAX];

int main(void)
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int t, n;
    cin >> t;
    for(int i = 0; i < t; i++)
    {
        cin >> n;
        for(int j = 0; j < 2; j++)
        {
            for(int k = 0; k < n; k++)
                cin >> score[j][k];
        }

        dp[0][0] = score[0][0];
        dp[1][0] = score[1][0];
        dp[0][1] = score[0][1] + dp[1][0];
        dp[1][1] = score[1][1] + dp[0][0];

        for(int k = 2; k < n; k++)
        {
            for(int j = 0; j < 2; j++)
            {
                if(j == 0)
                {
                    if(dp[j+1][k-1] < dp[j+1][k-2])
                        dp[j][k] = score[j][k] + dp[j+1][k-2];
                    else
                        dp[j][k] = score[j][k] + dp[j+1][k-1];
                }
                else
                {
                    if(dp[j-1][k-1] < dp[j-1][k-2])
                        dp[j][k] = score[j][k] + dp[j-1][k-2];
                    else
                        dp[j][k] = score[j][k] + dp[j-1][k-1];
                }
            }
        }
        if(dp[0][n-1] > dp[1][n-1])
            cout << dp[0][n-1] << "\n";
        else
            cout << dp[1][n-1] << "\n";
    }
        
}