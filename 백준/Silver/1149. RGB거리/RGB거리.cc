#include <iostream>
using namespace std;

#define MAX 1000
int price[MAX][3];
int dp[MAX][3];
int selected[MAX];

int main(void)
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int n;
    cin >> n;
    for(int i = 0; i < n; i++)
        cin >> price[i][0] >> price[i][1] >> price[i][2];

    for(int i = 0; i < 3; i++)
        dp[0][i] = price[0][i];

    for(int i = 1; i < n; i++)
    {
        for(int j = 0; j < 3; j++)
        {
            if(j == 0)
            {
                if(dp[i-1][1] < dp[i-1][2])
                    dp[i][j] = dp[i-1][1] + price[i][j];
                else
                    dp[i][j] = dp[i-1][2] + price[i][j];
            }
            else if(j == 1)
            {
                if(dp[i-1][0] < dp[i-1][2])
                    dp[i][j] = dp[i-1][0] + price[i][j];
                else
                    dp[i][j] = dp[i-1][2] + price[i][j];
            }
            else
            {
                if(dp[i-1][0] < dp[i-1][1])
                    dp[i][j] = dp[i-1][0] + price[i][j];
                else
                    dp[i][j] = dp[i-1][1] + price[i][j];
            }
        }
    }
    int min;
    min = dp[n-1][0];
    for(int i = 1; i < 3; i++)
    {
        if(min > dp[n-1][i])
            min = dp[n-1][i];
    }

    cout << min << "\n";
    return 0;
}