#include <iostream>
using namespace std;

#define MAX 1001

int seq[MAX];
int dp[MAX];

int main(void)
{
    int n, max;
    cin >> n;
    for(int i = 1; i <= n; i++)
        cin >> seq[i];

    dp[1] = seq[1];
    if(seq[2] > seq[1])
        dp[2] = dp[1] + seq[2];
    else
        dp[2] = seq[2];
    // 50 60 70 1 80 90 
    for(int i = 3; i <= n; i++)
    {
        max = 0;
        for(int j = i-1; j >= 1; j--)
        {
            if(seq[i] > seq[j])
            {
                if(max < dp[j])
                    max = dp[j];
            }
        }
        dp[i] = seq[i] + max;
    }

    max = -1;
    for(int i = 1; i <= n; i++)
    {
        if(max < dp[i])
            max = dp[i];
    }

    cout << max << "\n";
    return 0;
}