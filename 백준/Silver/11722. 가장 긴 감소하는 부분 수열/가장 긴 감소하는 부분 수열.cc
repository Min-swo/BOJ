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

    dp[1] = 1;
    for(int i = 2; i <= n; i++)
    {
        max = 0;
        for(int j = i - 1; j >= 1; j--)
        {
            if(seq[i] < seq[j])
            {
                if(max < dp[j])
                    max = dp[j];
            }
        }
        dp[i] = max + 1;
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