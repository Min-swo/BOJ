#include <iostream>
using namespace std;

#define MAX 1001

int seq[MAX];
int dp[MAX][2];

int main(void)
{
    int n, max;
    cin >> n;
    for(int i = 1; i <= n; i++)
        cin >> seq[i];

    dp[1][0] = 1;
    dp[1][1] = 1;
    for(int i = 2; i <= n; i++)
    {
        max = 0;
        for(int j = i - 1; j >= 1; j--)
        {
            if(seq[i] > seq[j])
            {
                if(max < dp[j][0])
                    max = dp[j][0];
            }
        }
        dp[i][0] = max + 1;

        max = 0;
        for(int j = i - 1; j >= 1; j--)
        {
            if(seq[i] < seq[j])
            {
                if(max < dp[j][0])
                    max = dp[j][0];
                if(max < dp[j][1])
                    max = dp[j][1];
            }
        }
        dp[i][1] = max + 1;
    }

    max = -1;
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